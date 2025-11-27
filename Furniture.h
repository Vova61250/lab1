#pragma once
#include "Base.h"
#include "MyException.h"
#include <string>

class Furniture : public Base {
    std::string type,color,material;
    double height,width,depth,cost;
public:
    Furniture();
    Furniture(const std::string&,double,double,double,const std::string&,const std::string&,double);
    Furniture(const Furniture&);
    ~Furniture(){}

    void input() override;
    void print() const override;
    void save(std::ostream&) const override;
    void load(std::istream&) override;
    int getType() const override { return 1; }
    Base* clone() const override { return new Furniture(*this); }
};
