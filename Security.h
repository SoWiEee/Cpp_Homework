#ifndef SECURITY_H
#define SECURITY_H
#include <string>
using namespace std;

// declare class here
class Security {
public:
    static int validate(string username, string password);
};

#endif