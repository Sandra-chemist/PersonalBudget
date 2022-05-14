#include "FileWithUsers.h"
#include "Markup.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem( "UserID", user.getId() );
    xml.AddElem( "Name", user.getName() );
    xml.AddElem( "Surname", user.getSurname() );
    xml.AddElem( "Login", user.getLogin() );
    xml.AddElem( "Password", user.getPassword() );

    xml.Save(getFileName());

}
vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;

    CMarkup xml;
    string fileNameWithUsers = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithUsers);

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("User") == true) {

            xml.IntoElem();
            xml.FindElem( "UserID");
            int id = atoi(xml.GetData().c_str());
            user.setId(id);
            xml.FindElem( "Name");
            string name = xml.GetData();
            user.setName(name);
            xml.FindElem( "Surname");
            string surname = xml.GetData();
            user.setSurname(surname);
            xml.FindElem( "Login");
            string login = xml.GetData();
            user.setLogin(login);
            xml.FindElem( "Surname");
            string password = xml.GetData();
            user.setPassword(password);
            users.push_back(user);

            xml.OutOfElem();
        }
    }

    return users;
}
void FileWithUsers::saveAllUsersToFile(vector <User> &users) {

    CMarkup xml;
    remove("Users.xml");

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        xml.Load(getFileName());

        if(!xml.FindElem("Users")) {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Users");
        }

        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", to_string(itr -> getId()));
        xml.AddElem("Name", itr -> getName());
        xml.AddElem("Surname", itr -> getSurname());
        xml.AddElem("Login", itr -> getLogin());
        xml.AddElem("Password", itr -> getPassword());
        xml.OutOfElem();
        xml.Save(getFileName());
    }
}

