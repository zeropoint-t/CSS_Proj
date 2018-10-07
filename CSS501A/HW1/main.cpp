
#include <iostream>
#include "ExpenseElement.h"
#include "PersonalExpense.h"
#include "ExpenseVisitor.h"

using namespace std;

int main(int argc, const char * argv[]){
    cout << "Hello World" << endl;

    ElectricityExpense elecBills;
    elecBills.AddBill(2018,1,100);
    elecBills.AddBill(2018,2,150);
    elecBills.AddBill(2018,3,130);

    PersonalExpense p_exp;
    p_exp.AddExpense(elecBills);

    ExpenseElementCalcTotalVisitor calcTotalVisitor;
    calcTotalVisitor.Visit(p_exp);

    return 0;
}

