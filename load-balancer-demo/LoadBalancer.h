#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include "Request.h"
#include <queue>
class LoadBalancer {
public: 
    LoadBalancer();
    ~LoadBalancer();

    void incTime();
    int systemTime();
    void addRequest(Request r);
    Request request();
    bool isRequestsEmpty();

private:
    std::queue<Request> m_requests;
    int m_systemTime;
};

#endif // LOADBALANCER_H