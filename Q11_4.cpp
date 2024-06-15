#include <iostream>
#include <cstdlib>
#include "User.h"
#include "Administrator.h"

int main(){
    User user;
    Administrator admin;
    string usr, passwd;
    cout << "Enter your username=> ";
    cin >> usr;
    cout << "Enter your password=> ";
    cin >> passwd;
    cout << "[*] User Login: " << (user.Login(usr, passwd) ? "Success!" : "Failure!") << endl;
    cout << "[*] Admin Login: " << (admin.Login(usr, passwd) ? "Success!" : "Failure!") << endl;

    system("pause");
    return 0;
}

