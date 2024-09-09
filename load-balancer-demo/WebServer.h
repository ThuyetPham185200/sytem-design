#ifndef WEBSERVER_H
#define WEBSERVER_H
#include "Request.h"

class WebServer {
public: 
    WebServer(std::string serverName); 
    WebServer();
    ~WebServer();

    void addRequest(Request r, int currTime);
    std::string serverName();
    Request request();
    bool isRequestDone(int currTime); 

private:
    Request m_request;
    int m_startTime;
    std::string m_serverName;
};

#endif // WEBSERVER_H