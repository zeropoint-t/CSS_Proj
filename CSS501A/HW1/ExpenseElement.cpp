

#include "ExpenseElement.h"

Bill::Bill(int year, int month, double amt):Year(year), Month(month), Amount(amt){
}

//Costructor
ElectricityExpense::ElectricityExpense(){
}

//Destructor
ElectricityExpense::~ElectricityExpense(){
}

void ElectricityExpense::Accept(const ExpenseVisitor& visitor){
    
}

void ElectricityExpense::AddBill(int year, int month, double amt) {
    bills.push_back(new Bill(year,month,amt));
}
