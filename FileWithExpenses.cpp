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
    xml.AddElem("UserId", expense.getUserId());
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
            xml.FindElem("UserId");
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
void FileWithExpenses::displayExpense(Expense expense) {
    cout << "ExpenseId:          " << expense.getExpenseId() << endl;
    cout << "UserId:             " << expense.getUserId() << endl;
    cout << "ExpenseDate: "    << expense.getDate() << endl;
    cout << "Item: "    << expense.getItem() << endl;
    cout << "Amount: "  << expense.getAmount() << endl;
    cout << endl;
}

