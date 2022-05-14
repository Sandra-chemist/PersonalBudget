#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
	if(newIncomeId >= 0)
		incomeId = newIncomeId;
}
void Income::setUserId(int newUserId)
{
	if(newUserId >= 0)
		userId = newUserId;
}
void Income::setDate(int newDate)
{
	date = newDate;
}
void Income::setItem(string newItem)
{
	item = newItem;
}
void Income::setAmount(float newAmount)
{
	amount = newAmount;
}
int Income::getIncomeId()
{
	return incomeId;
}
int Income::getUserId()
{
	return userId;
}
int Income::getDate()
{
	return date;
}
string Income::getItem()
{
	return item;
}
float Income::getAmount()
{
	return amount;
}

Income Income::addIncome()
{
        Income income;
        string item;
        float amount;

        cout << "Enter item of income: ";
        item = AuxiliaryMethods::loadLine();
        income.setItem(item);

        cout << "Enter amount of income in xxxx,xx format: ";
       // amount = AuxiliaryMethods::loadFloat();
        income.setAmount(amount);




}
