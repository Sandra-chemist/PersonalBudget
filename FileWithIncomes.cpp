#include "FileWithIncomes.h"
#include "Markup.h"

void FileWithIncomes::addIncomeToFile(Income income) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(income.getAmount()));

    xml.Save(getFileName());
}
vector <Income> FileWithIncomes::loadIncomesFromFile(int loggedInUserId) {
    Income income;
    vector <Income> incomes;

    CMarkup xml;
    bool fileExists = xml.Load(getFileName());

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income") == true) {

            xml.IntoElem();
            xml.FindElem("IncomeId");
            int incomeId = atoi(xml.GetData().c_str());
            income.setIncomeId(incomeId);
            xml.FindElem("UserId");
            int userId = atoi(xml.GetData().c_str());
            income.setUserId(userId);
            xml.FindElem("Date");
            int date = atoi(xml.GetData().c_str());
            income.setDate(date);
            xml.FindElem("Item");
            string item = xml.GetData();
            income.setItem(item);
            xml.FindElem("Amount");
            float amount = atof(xml.GetData().c_str());
            income.setAmount(amount);
            incomes.push_back(income);

            xml.OutOfElem();
        }
    }
    return incomes;
}
void FileWithIncomes::displayIncome(vector <Income>::iterator itr) {
    cout << "IncomeId:           " << itr -> getIncomeId() << endl;
    cout << "UserId:             " << itr -> getUserId() << endl;
    cout << "Date:               " << itr -> getDate() << endl;
    cout << "Item:               " << itr -> getItem() << endl;
    cout << "Amount:             " << itr -> getAmount() << endl;
    cout << endl;
}

