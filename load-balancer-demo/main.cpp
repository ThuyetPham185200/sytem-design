// #include "WebServer.h"
// #include "LoadBalancer.h"
#include "load_balancer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

// const int NUMWEBSERVERS = 5;

// // create a request
// Request createRandomRequest() {
//     stringstream ips, ipd;
//     Request r;

//     ips << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
//     ipd << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256) << "." << (rand() % 256);
    
//     r.source = ips.str();
//     r.destination = ipd.str();
//     r.processTime = rand() % 500;

//     return r;
// }

// void demo_1() {
//     LoadBalancer lb;

//     // Start off with a "full" queue
//     for (int i = 0; i < 10; i++) {
//         Request r = createRandomRequest();
//         lb.addRequest(r);
//     }

//     // An array of webservers
//     WebServer webarray[NUMWEBSERVERS];
//     for (int i = 0; i < NUMWEBSERVERS; i++) {
//         std::string name = "Server " + std::to_string(i);
//         WebServer w(name);
//         webarray[i] = w;
//         webarray[i].addRequest(lb.request(), lb.systemTime());
//     }

//     // Loop
//     while (lb.systemTime() < 10000) {
//         int currTime = lb.systemTime();

//         // Check each webserver if it's done
//         if (webarray[currTime % NUMWEBSERVERS].isRequestDone(currTime)) {
//             Request r = webarray[currTime % NUMWEBSERVERS].request();
//             cout << "At " << currTime << " " << webarray[currTime % NUMWEBSERVERS].serverName()
//                 << " processed request from " << r.source << " to " << r.destination << endl;
//             webarray[currTime % NUMWEBSERVERS].addRequest(lb.request(), currTime);
//         }

//         // Every random amount of time, we get a new request
//         if (rand() % 10 == 0) {
//             Request r = createRandomRequest();
//             lb.addRequest(r);
//         }

//         lb.incTime();

//     }
// }



void demo_2() {
    LoadBalancing loadBalancer;
    
    // Add some servers
    loadBalancer.addServer(Server("Server1"));
    loadBalancer.addServer(Server("Server2"));
    loadBalancer.addServer(Server("Server3"));
    
    // Simulate some requests
    for (int i = 0; i < 10; ++i) {
        Server& server = loadBalancer.getNextServer();
        server.addLoad(1);
        std::cout << "Request " << i + 1 << " assigned to " << server.getName() 
                  << " (Current load: " << server.getLoad() << ")" << std::endl;
    }    
}

void demo_3() {
    
}

int main() {

    demo_2();
    return 0;
}