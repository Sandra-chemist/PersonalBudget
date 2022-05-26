#include "FinanceManager.h"

void FinanceManager::addIncome() {
    Income income;
    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = provideDataOfNewIncome();
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
    cout << "New income has been added" << endl;
}
Income FinanceManager::provideDataOfNewIncome() {
    Income income;
    string item;
    float amount;
    int currentDate;
    char choice;
    int otherDate;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add income with current date?" << endl << endl;
    cout << "If yes, enter '1',if you want to choose different date - enter '2'." << endl;
    choice = AuxiliaryMethods::loadChar();

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    if (choice == '1') {
        currentDate = date.getCurrentDate();
        income.setDate(currentDate);
    } else if (choice == '2') {
        do {
            otherDate = date.writeOtherDateThanCurrent();
        } while (date.isDateRight(otherDate) == false);
        income.setDate(otherDate);
    }
    cout << "Enter item of income: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Enter amount of income: ";
    amount = AuxiliaryMethods::loadFloat();
    income.setAmount(amount);
    return income;
}
int FinanceManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
void FinanceManager::showAllIncomesForCurrentMonth() {
    Income income;
    int minDate = (date.getCurrentDate()/100)*100 + 1;
  //  cout << "MinDate: " << minDate << endl;
    int maxDate = (date.getCurrentDate()/100 + 1) * 100;
  //  cout << "MaxDate: " << maxDate << endl;
    system ("pause");

    system("cls");
    if (!incomes.empty()) {
        cout << ">>> DISPLAY BALANCE FOR CURRENT MONTH <<<" << endl << endl;
        for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end(); itr++) {
             int currentDate = itr -> getDate();

          if (currentDate >= minDate && currentDate <= maxDate) {
                fileWithIncomes.displayIncome(*itr);
               // countTotalIncome(itr);
           }
        }
        system("pause");
    }
}
void FinanceManager::countTotalIncome(vector <Income>::iterator itr)
{
    totalIncome += itr -> getAmount();
   cout << "TotalIncome: " << totalIncome << endl;
}
void FinanceManager::addExpense() {
    Expense expense;
    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = provideDataOfNewExpense();
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
    cout << "New expense has been added" << endl;
}
Expense FinanceManager::provideDataOfNewExpense() {
    Expense expense;
    string item;
    float amount;
    int currentDate;
    char choice;
    int otherDate;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add expense with current date?" << endl << endl;
    cout << "If yes, enter '1',if you want to choose different date - enter '2'." << endl;
    choice = AuxiliaryMethods::loadChar();

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    if (choice == '1') {
        currentDate = date.getCurrentDate();
        expense.setDate(currentDate);
    } else if (choice == '2') {
        do {
            otherDate = date.writeOtherDateThanCurrent();
        } while (date.isDateRight(otherDate) == false);
        expense.setDate(otherDate);
    }
    cout << "Enter item of expense: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    cout << "Enter amount of expense: ";
    amount = AuxiliaryMethods::loadFloat();
    expense.setAmount(amount);
    return expense;
}
int FinanceManager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}
void FinanceManager::showAllExpensesForCurrentMonth() {
    Expense expense;
    int minDate = (date.getCurrentDate()/100)*100 + 1;
   // cout << "MinDate: " << minDate << endl;
    int maxDate = (date.getCurrentDate()/100 + 1) * 100;
   // cout << "MaxDate: " << maxDate << endl;
    system ("pause");

    system("cls");
    if (!expenses.empty()) {
        cout << ">>> DISPLAY BALANCE FOR CURRENT MONTH <<<" << endl << endl;
        for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr++) {
             int currentDate = itr -> getDate();

          if (currentDate >= minDate && currentDate <= maxDate) {
                fileWithExpenses.displayExpense(*itr);
              //  countTotalExpense(itr);
           }
        }
        system("pause");
    }
}
void FinanceManager::countTotalExpense(vector <Expense>::iterator itr)
{
    totalExpense += itr -> getAmount();
   cout << "TotalIncome: " << totalExpense << endl;
}
void FinanceManager::displayBalanceForCurrentMonth(){
   showAllIncomesForCurrentMonth();
   showAllExpensesForCurrentMonth();
}
