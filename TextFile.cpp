#include "TextFile.h"

bool TextFile::isFileEmpty() {
    bool blank = true;
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true) {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            blank = false;
    }

    textFile.close();
    return blank;
}
string TextFile::getFileName() {
    return FILE_NAME;
}
