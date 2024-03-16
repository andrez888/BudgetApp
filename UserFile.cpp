#include "UserFile.h"

void UserFile::addUserToFile(const User &user){

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
    xml.AddElem("UserId", user.id);
    xml.AddElem("Login", user.login);
    xml.AddElem("Password", user.password);
    xml.OutOfElem(); // Move out of <User>

    xml.Save(FILE_NAME);
}
