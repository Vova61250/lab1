#pragma once
#include "Base.h"
#include "MyException.h"
#include <string>

class Machine : public Base {
    std::string brand,model,plate;
public:
    Machine();
    Machine(const std::string&,const std::string&,const std::string&);
    Machine(const Machine&);
    ~Machine(){}

    void input() override;
    void print() const override;
    void save(std::ostream&) const override;
    void load(std::istream&) override;
    int getType() const override { return 3; }
    Base* clone() const override { return new Machine(*this); }
};
