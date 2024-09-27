#ifndef LITERAL_HPP
#define LITERAL_HPP

#include "expression.hpp"

class literal : public expression
{
private:
    int val;
public:
    literal(int);

    void setVal(int);
    int getVal() const override;
};

#endif
