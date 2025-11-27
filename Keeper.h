#pragma once
#include "Base.h"
#include "Furniture.h"
#include "Worker.h"
#include "Machine.h"
#include <fstream>

class Keeper {
    Base** arr;
    int size;
    void clear();
public:
    Keeper();
    Keeper(const Keeper&);
    Keeper& operator=(const Keeper&);
    ~Keeper();

    void add(Base*);
    void remove(int);
    Base* get(int) const;
    void printAll() const;

    void saveToFile(const char*) const;
    void loadFromFile(const char*);
};
