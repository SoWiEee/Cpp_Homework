#include <functional>
#include "Security.h"

int Security::validate(string username, string password){
    hash<string> hasher;
    size_t hash_usr= hasher(username);
    size_t hash_passwd = hasher(password);

    // vaildate info by hash
    if(hash_usr == hasher("abbott") && hash_passwd == hasher("monday")) return 1;  //user
    if (hash_usr == hasher("costello") && hash_passwd == hasher("tuesday")) return 2;  //admin
    return 0;   // invalid
}
