#include "UserManager.h"

int UserManager::getNewUserId() {
    if(users.empty()) {
        return 1;
    } else {
        return users.size() + 1;
    }
}

User UserManager:: typeNewUserdata() {

}

bool UserManager::doesLoginExist(string login) {
    for(User user : users){
        if(user.login == login)
            return true;
    }
    return false;
}
void UserManager::userLogin() {}
void UserManager::userRegistartion() {}
void UserManager::changePassword() {}
bool UserManager::isUserLoggedIn() {}
