#include <iostream>
#include "UserManager.h"
#include "User.h"
#include <vector>


using namespace std;

int main()
{
    vector <User> users;
    UserManager example("users");

    //example.userRegistartion();
    //example.userRegistartion();
    //example.userLogin();
    example.showVector();
    return 0;
}
