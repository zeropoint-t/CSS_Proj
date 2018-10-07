#ifndef ExpenseVisitor_h
#define ExpenseVisitor_h

#include "PersonalExpense.h"

struct ExpenseVisitor{
    virtual void Visit(PersonalExpense& elecricBill) const = 0;
    virtual ~ExpenseVisitor(){};
};

class ExpenseElementCalcTotalVisitor: public ExpenseVisitor{
    public:
        ExpenseElementCalcTotalVisitor();
        ~ExpenseElementCalcTotalVisitor();
        void Visit(PersonalExpense& p_exp) const override;
};

#include "ExpenseVisitor.cpp"

#endif