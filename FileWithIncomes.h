#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "XmlFile.h"

using namespace std;

class FileWithIncomes : public XmlFile {

    string fileNameWithIncomes;
public:
    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes) {};

};
#endif
