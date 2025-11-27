#pragma once
#include "Base.h"
#include "MyException.h"
#include <string>

class Worker : public Base {
    std::string name,position,address,phone;
    double salary;
public:
    Worker();
    Worker(const std::string&,const std::string&,double,const std::string&,const std::string&);
    Worker(const Worker&);
    ~Worker(){}

    void input() override;
    void print() const override;
    void save(std::ostream&) const override;
    void load(std::istream&) override;
    int getType() const override { return 2; }
    Base* clone() const override { return new Worker(*this); }
};
