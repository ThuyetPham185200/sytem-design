#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <cstdlib>  // For std::rand()

class Server {
public:
    void process_request(int request_id) {
        // Simulate processing time
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        std::cout << "Server " << this << " processed request " << request_id << " in " << std::this_thread::get_id() << std::endl;
    }
};

class LoadBalancer {
public:
    std::vector<Server> servers;
    std::queue<int> requests;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop_flag = false;
    int current_server = 0;
    int request_id = 0;
public:
    LoadBalancer(int num_servers) : servers(num_servers) {}

    void add_request(int request_id) {
        std::unique_lock<std::mutex> lock(mtx);
        requests.push(request_id);
        cv.notify_one();
    }

    void run() {
        std::cout << "Start!\n";
        while (true) {
        
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this] { return !requests.empty() || stop_flag; });
                if (stop_flag && requests.empty()) return;
                request_id = requests.front();
                requests.pop();
            }

            // Simple round-robin load balancing
            servers[current_server].process_request(request_id);
            current_server = getRandomServer(4); 

            std::cout << "Request " << request_id << " completed " << current_server << std::endl;
        }
    }

    int getRandomServer(int num_servers) {
        return std::rand() % num_servers;  // Returns a random number between 0 and num_servers-1
    }

    void stop() {
        std::unique_lock<std::mutex> lock(mtx);
        stop_flag = true;
        cv.notify_all();
    }
};

void client(LoadBalancer& lb) {
    for (int i = 0; i < 1000; ++i) {
        lb.add_request(i);
        if(lb.stop_flag) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}



int main() {
    LoadBalancer lb(4);
    std::thread lb_thread(&LoadBalancer::run, &lb);
    std::thread client_thread(client, std::ref(lb));

    std::thread t = std::thread([&lb] () {
        std::cout << "Streaming started. Press Enter to stop." << std::endl;
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            lb.stop();
        }
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    client_thread.join();    
    lb_thread.join();

    return 0;
}