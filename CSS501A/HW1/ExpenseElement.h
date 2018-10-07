#ifndef ExpenseElement_h
#define ExpenseElement_h

#include <vector>
#include <string>
#include "ExpenseVisitor.h"

using namespace std;

struct Bill{
    Bill(int year, int month, double amt);
    int Year;
    int Month;
    double Amount;
};

struct ExpenseElement{
    virtual void Accept(const ExpenseVisitor& visitor) = 0;
    virtual void AddBill(int year,int month, double amt) = 0;
};

class ElectricityExpense : public ExpenseElement{
    public:
        ElectricityExpense();
        ~ElectricityExpense();
        void Accept(const ExpenseVisitor& visitor) override;
        void AddBill(int year,int month, double amt) override;
    private:
        vector<Bill*> bills;
};

#include "ExpenseElement.cpp"

#endif