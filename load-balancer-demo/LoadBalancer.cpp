#include "LoadBalancer.h"

LoadBalancer::LoadBalancer() {
    m_systemTime = 0;
}
LoadBalancer::~LoadBalancer() {

}

void LoadBalancer::incTime() {
    ++m_systemTime;
}
int LoadBalancer::systemTime() {
    return m_systemTime;
}
void LoadBalancer::addRequest(Request r) {
    m_requests.push(r);
}
Request LoadBalancer::request() {
    incTime();
    if(!m_requests.empty()) {
        Request r = m_requests.front();
        m_requests.pop();
        return r;
    } 
    return Request();
}
bool LoadBalancer::isRequestsEmpty() {
    return m_requests.empty();
}