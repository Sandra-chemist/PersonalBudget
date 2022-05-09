#ifndef XMLTFILE_H
#define XMLTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile {

    const string FILE_NAME;

public:

    XmlFile(string fileName) : FILE_NAME(fileName) {
    }
    string getFileName();

};
#endif
