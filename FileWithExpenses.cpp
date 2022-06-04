#include "FileWithExpenses.h"
#include "Markup.h"

void FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserID", expense.getUserId());
    string dateAsString = AuxiliaryMethods::convertIntToString(expense.getDate());
    string dateAsStringWithDash = AdditionalMethodsOnDate::addDashToDate(dateAsString);
    xml.AddElem("Date", dateAsStringWithDash);
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));

    xml.Save(getFileName());
}
vector <Expense> FileWithExpenses::loadExpensesFromFile(int loggedInUserId) {
    Expense expense;
    vector <Expense> expenses;

    CMarkup xml;
    bool fileExists = xml.Load(getFileName());

    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense") == true) {

            xml.IntoElem();
            xml.FindElem("ExpenseId");
            int expenseId = atoi(xml.GetData().c_str());
            expense.setExpenseId(expenseId);
            xml.FindElem("UserID");
            int userId = atoi(xml.GetData().c_str());
            expense.setUserId(userId);
            xml.FindElem("Date");
            string date = xml.GetData();
            string dateWithoutDash = AdditionalMethodsOnDate::removeDashFromDate(date);
            expense.setDate(AuxiliaryMethods::convertStringToInt(dateWithoutDash));
            xml.FindElem("Item");
            string item = xml.GetData();
            expense.setItem(item);
            xml.FindElem("Amount");
            string amount = xml.GetData();
            expense.setAmount(AuxiliaryMethods::convertStringToFloat(amount));
            expenses.push_back(expense);

            xml.OutOfElem();
        }
    }
    return expenses;
}
int FileWithExpenses::getNewExpenseId() {
    CMarkup xml;
    vector <Expense> expenses;
    bool fileExists = xml.Load(getFileName());
    if (fileExists == true) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense")) {
            xml.FindChildElem("ExpenseId");
        }
        lastExpenseId = AuxiliaryMethods::convertStringToInt(xml.GetChildData());;
        return lastExpenseId;
    } else
        return 0;
}
void FileWithExpenses::displayExpense(Expense expense) {
    int date = expense.getDate();
    string dateAsString = AuxiliaryMethods::convertIntToString(date);
    string dateWithDash = AdditionalMethodsOnDate::addDashToDate(dateAsString);
    cout << "ExpenseDate: " << dateWithDash << endl;
    cout << "Item:        " << expense.getItem() << endl;
    cout << "Amount:      " << fixed << setprecision(2) << expense.getAmount() << endl;
    cout << endl;
}

