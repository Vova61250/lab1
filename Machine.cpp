#include "Machine.h"
#include <limits>

Machine::Machine(){}
Machine::Machine(const std::string&b,const std::string&m,const std::string&p){
    brand=b;model=m;plate=p;
}
Machine::Machine(const Machine&o):Base(o){
    brand=o.brand;model=o.model;plate=o.plate;
}

void Machine::print() const {
    std::cout<<"[Машина ID "<<id<<"] "<<brand<<" "<<model<<" Номер:"<<plate<<"\n";
}

void Machine::input(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Марка: ";getline(std::cin,brand);
    std::cout<<"Модель: ";getline(std::cin,model);
    std::cout<<"Номер: ";getline(std::cin,plate);
}

void Machine::save(std::ostream&os) const {
    os<<brand<<"\n"<<model<<"\n"<<plate<<"\n";
}
void Machine::load(std::istream&is){
    getline(is,brand);
    getline(is,model);
    getline(is,plate);
}
