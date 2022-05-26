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
    string dateAsString = AuxiliaryMethods::convertIntToString(income.getDate());
    string dateAsStringWithDash = AuxiliaryMethods::addDashToDate(dateAsString);
    xml.AddElem("Date", dateAsStringWithDash);
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
            string date = xml.GetData();
            string dateWithoutDash = AuxiliaryMethods::removeDashFromDate(date);
            income.setDate(AuxiliaryMethods::convertStringToInt(dateWithoutDash));
            xml.FindElem("Item");
            string item = xml.GetData();
            income.setItem(item);
            xml.FindElem("Amount");
            string amount = xml.GetData();
            income.setAmount(AuxiliaryMethods::convertStringToFloat(amount));
            incomes.push_back(income);

            xml.OutOfElem();
        }
    }
    return incomes;
}
void FileWithIncomes::displayIncome(Income income) {
    cout << "IncomeId:           " << income.getIncomeId() << endl;
    cout << "UserId:             " << income.getUserId() << endl;
    cout << "Date:               " << income.getDate() << endl;
    cout << "Item:               " << income.getItem() << endl;
    cout << "Amount:             " << income.getAmount() << endl;
    cout << endl;
}

