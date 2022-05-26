#include "FinanceManager.h"

void FinanceManager::showAllIncomesForCurrentMonth() {
    incomeManager.showAllIncomesForCurrentMonth();
}
void FinanceManager::showAllExpensesForCurrentMonth() {
    expenseManager.showAllExpensesForCurrentMonth();
}
void FinanceManager::displayBalanceForCurrentMonth(){
   showAllIncomesForCurrentMonth();
   showAllExpensesForCurrentMonth();

}
