#include "WebServer.h"

WebServer::WebServer(std::string serverName){
    m_serverName = serverName;
    m_startTime = 0;
}
WebServer::WebServer() {
    m_serverName = "";
    m_startTime = 0;
}

WebServer::~WebServer() {

}


void WebServer::addRequest(Request r, int currTime) {
    m_request = r;
    m_startTime = currTime;
}
std::string WebServer::serverName() {
    return m_serverName;
}
Request WebServer::request() {
    return m_request;
}
bool WebServer::isRequestDone(int currTime) {
    return currTime > m_startTime + m_request.processTime;
}