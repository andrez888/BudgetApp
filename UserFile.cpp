#include "UserFile.h"

void UserFile::addUserToFile(const User &user) {

    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.15\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    } else {
        xml.FindElem();
    }
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserName", user.name);
    xml.AddElem("UserSurname", user.surname);
    xml.AddElem("UserId", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.OutOfElem();

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
            xml.FindElem("UserId");
            user.id = stoi(xml.GetData());
            xml.FindElem("Login");
            user.login = xml.GetData();
            xml.FindElem("Password");
            user.password = xml.GetData();

            users.push_back(user);

            xml.OutOfElem();
        }
    }
    return users;
}

bool UserFile::changePasswordInFile(int id, const string newPassword) {
    CMarkup xml;

    if (xml.Load(FILE_NAME)) {

        if (xml.FindElem("Users")) {
            xml.IntoElem();

            while (xml.FindElem("User")) {

                xml.IntoElem();
                xml.FindElem("UserId");

                if ( xml.GetData() == to_string(id)) {
                    if (xml.FindElem("Password")) {
                        xml.SetData(newPassword);
                        xml.OutOfElem();
                        break;
                    }
                }
            }
        }
        xml.Save(FILE_NAME);
        return true;
    } else {
        return false;
    }
}

