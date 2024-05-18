#include "User.h"

bool User::Login(string username, string password){
        int validation = Security::validate(username, password);
        return validation == 1 || validation == 2;
}

