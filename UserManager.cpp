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
    cin>>user.name;

    cout << endl <<"Type surname: ";
    cin >> user.surname;
    do {
        cout << endl << "Type your login :";
        cin >> user.login;
    } while(doesLoginExist(user.login));

    cout << endl << "Type password :";
    cin >> user.password;

    cout << endl << "Your account has been created ";
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

void UserManager::userLogin(vector <User>& users) {
    string inputLogin = "";
    string inputPassword = "";

    cout << "Enter your login: ";
    cin >> inputLogin;

    for(User user : users){
        if(user.login == inputLogin){
        for(int attempts = 3 ; attempts > 0; attempts-- ){
            cout << endl << "Enter your password, you have "<<attempts<<" attempts: ";
            cin >> inputPassword;
                if(user.password == inputPassword){
                    loggedInUserId = user.id;
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

void UserManager::userRegistartion(vector <User> &users) {
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
