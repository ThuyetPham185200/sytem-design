#ifndef REQUEST_H
#define REQUEST_H

#include <string>
struct Request {
    std::string source;
    std::string destination;
    int processTime;
};

#endif // REQUEST_H