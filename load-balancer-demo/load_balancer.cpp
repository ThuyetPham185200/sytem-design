#include "load_balancer.h"

// Server implementation
Server::Server(const std::string& name) : name(name), load(0) {}

void Server::addLoad(int amount) {
    load += amount;
}

int Server::getLoad() const {
    return load;
}

std::string Server::getName() const {
    return name;
}



// Constructor for LoadBalancer to initialize currentIndex
LoadBalancing::LoadBalancing() : currentIndex(0) {}

// LoadBalancer implementation
void LoadBalancing::addServer(const Server& server) {
    servers.push_back(server);
}

Server& LoadBalancing::getNextServer() {
    if (currentIndex >= servers.size()) {
        currentIndex = 0;
    }
    return servers[currentIndex++];
}

