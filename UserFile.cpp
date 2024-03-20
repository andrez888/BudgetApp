#include "UserFile.h"

void UserFile::addUserToFile(const User &user) {

    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.15\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    } else {
        xml.FindElem(); // Move to the root element
    }

    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserName", user.name);
    xml.AddElem("UserSurname", user.surname);
    xml.AddElem("UserId", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.OutOfElem(); // Move out of <User>

    xml.Save(FILE_NAME);
}

vector <User>  UserFile::loadUsersFromFile() {

    CMarkup xml;
    vector<User> users;

    if (xml.Load(FILE_NAME)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.IntoElem();

            User user;
            xml.FindElem("UserName");
            user.name = xml.GetData();
            xml.FindElem("UserSurname");
            user.surname = xml.GetData();
            // Read UserId, Login, and Password from XML
            xml.FindElem("UserId");
            user.id = stoi(xml.GetData());
            xml.FindElem("Login");
            user.login = xml.GetData();
            xml.FindElem("Password");
            user.password = xml.GetData();

            // Add User object to the vector
            users.push_back(user);

            xml.OutOfElem(); // Move out of the User element
        }
    }
    return users;
}
