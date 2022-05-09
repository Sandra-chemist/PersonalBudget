#include "FileWithUsers.h"
#include "Markup.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileName);
     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem( "UserID", user.getUserId() );
    xml.AddElem( "Name", user.getName() );
    xml.AddElem( "Surname", user.getSurname() );
    xml.AddElem( "Login", user.getLogin() );
    xml.AddElem( "Password", user.getPassword() );

    xml.Save(fileName);

}
vector <User> FileWithUsers::loadUsersFromFile() {
    {
    User user;
    vector <User> users;

    CMarkup xml;
    string fileName = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileName);

    if (fileExists == true)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true) {

            xml.IntoElem();
            xml.FindElem( "UserID");
            int id = atoi(xml.GetData().c_str());
            user.setId(newId);
            xml.FindElem( "Name");
            string name = xml.GetData();
            user.setName(newName);
            xml.FindElem( "Surname");
            string surname = xml.GetData();
            user.setSurname(newSurname);
            xml.FindElem( "Login");
            string login = xml.GetData();
            user.setLogin(newLogin);
            xml.FindElem( "Surname");
            string password = xml.GetData();
            user.setPassword(newPassword);
            users.push_back(user);

            xml.OutOfElem();
        }
    }

    return users;
}
