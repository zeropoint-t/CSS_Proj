#include "PersonalExpense.h"

PersonalExpense::PersonalExpense(){}

PersonalExpense::~PersonalExpense(){}

void PersonalExpense::AddExpense(ExpenseElement& expense){
    expenses.push_back(&expense);
}

vector<ExpenseElement*>& PersonalExpense::GetExpenses(){
    return expenses;
}