#include "UserManager.h"

int UserManager::getNewUserId() {
    if(users.empty()) {
        return 1;
    } else {
        return users.size() + 1;
    }
}

User UserManager:: typeNewUserdata() {
    system("cls");
    User user;

    user.id = getNewUserId();

    cout << "Type first name : ";
    user.name = Utils::readLine();

    cout << endl <<"Type surname: ";
    user.surname = Utils::readLine();
    do {
        cout << endl << "Type your login :";
         user.login = Utils::readLine();
    } while(doesLoginExist(user.login));

    cout << endl << "Type password :";
    user.password = Utils::readLine();

    cout << endl << "Your account has been created" << endl;
    system("pause");
    return user;
}

bool UserManager::doesLoginExist(string login) {
    for(const User& user : users) {
        if(user.login == login)
            return true;
    }
    return false;
}

void UserManager::userLogin() {
    string inputLogin = "";
    string inputPassword = "";

    cout << "Enter your login: ";
     inputLogin = Utils::readLine();

    for(User user : users){
        if(user.login == inputLogin){
        for(int attempts = 3 ; attempts > 0; attempts-- ){
            cout << endl << "Enter your password, you have "<<attempts<<" attempts: ";
            inputPassword = Utils::readLine();
                if(user.password == inputPassword){
                    loggedInUserId = user.id;
                    cout << "You have been logged in succesfully"<<endl;
                    system("pause");
                    return;
                }
            }
            cout <<endl<< "You have exceed the maximum number of password attempts";
            system("pause");
            return;
        }
    }
    cout << endl <<"Incorrect login";
    system("pause");
}

void UserManager::userRegistartion() {
        User user = typeNewUserdata();

        users.push_back(user);
        userFile.addUserToFile(user);
}

void UserManager::changePassword() {}

bool UserManager::isUserLoggedIn() {
    if(loggedInUserId > 0){
        return true;
    }else{
        return false;
    }
}

void UserManager::showVector(){
    for(auto x: users){
        cout << x.name <<" "<<x.surname<<" " <<x.id<<" "<<x.login<<" " <<x.password<<endl;
    }
}

int UserManager::getLoggedInUserId(){
    return loggedInUserId;
}

void UserManager::userLogOut(){
    loggedInUserId = 0;
}

void UserManager::changePassword() {
    system("cls");
    string newPassword;

    cout << "Type a new password" << endl;
    newPassword = Utils::readLine();

    if(userFile.changePasswordInFile(loggedInUserId, newPassword)) {
        cout << "Your password has been changed" << endl;
        for(User &user : users) {
            if(user.id == loggedInUserId) {
                user.password = newPassword;
            }
        }
        system("pause");
    } else {
        cout << "Error. Enable to change password" << endl;
        system("pause");
    }
}

