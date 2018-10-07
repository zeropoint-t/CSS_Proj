#include "ExpenseVisitor.h"
#include "ExpenseElement.h"

//Constructor
ExpenseElementCalcTotalVisitor::ExpenseElementCalcTotalVisitor(){};
//Destructor
ExpenseElementCalcTotalVisitor::~ExpenseElementCalcTotalVisitor(){};

void ExpenseElementCalcTotalVisitor::Visit(PersonalExpense& p_exp) const{
    //do stuff with electric bills here
    auto expenses = p_exp.GetExpenses();
    for(auto it = expenses.begin(); it != expenses.end(); ++it){
        (*it)->Accept(*this);
        // cout << "Hello World" << endl;
    }
}