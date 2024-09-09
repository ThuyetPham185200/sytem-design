#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H

#include <string>
#include <vector>

class Server {
public:
    Server(const std::string& name);
    void addLoad(int amount);
    int getLoad() const;
    std::string getName() const;

private:
    std::string name;
    int load;
};

class LoadBalancing {
public:
    LoadBalancing();
    void addServer(const Server& server);
    Server& getNextServer();

private:
    std::vector<Server> servers;
    size_t currentIndex;
};

#endif // LOAD_BALANCER_H
