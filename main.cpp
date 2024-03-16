#include <iostream>
#include "UserManager.h"
#include "User.h"
#include <vector>


using namespace std;

int main()
{
    vector <User> users;
    UserManager example("users");

    example.userRegistartion(users);
    example.userRegistartion(users);
    example.userLogin(users);
    return 0;
}
