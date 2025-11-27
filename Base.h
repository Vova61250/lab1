#pragma once
#include <iostream>

class Base {
protected:
    int id;
    static int nextId;
public:
    Base();
    Base(const Base& other);
    virtual ~Base() {}

    int getId() const;

    virtual void print() const = 0;
    virtual void input() = 0;
    virtual void save(std::ostream& os) const = 0;
    virtual void load(std::istream& is) = 0;
    virtual int getType() const = 0;
    virtual Base* clone() const = 0;
};
