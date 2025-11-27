#include "Worker.h"
#include <limits>

Worker::Worker():salary(0){}
Worker::Worker(const std::string&n,const std::string&p,double s,const std::string&a,const std::string&ph){
    name=n;position=p;salary=s;address=a;phone=ph;
}
Worker::Worker(const Worker&o):Base(o){
    name=o.name;position=o.position;salary=o.salary;address=o.address;phone=o.phone;
}

void Worker::print() const {
    std::cout<<"[Работник ID "<<id<<"] "<<name<<" ("<<position<<") "<<salary<<"р\n";
    std::cout<<"Адрес: "<<address<<" Телефон: "<<phone<<"\n";
}

void Worker::input(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"ФИО: ";getline(std::cin,name);
    std::cout<<"Должность: ";getline(std::cin,position);
    std::cout<<"Зарплата: ";std::cin>>salary;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Адрес: ";getline(std::cin,address);
    std::cout<<"Телефон: ";getline(std::cin,phone);
}

void Worker::save(std::ostream&os) const{
    os<<name<<"\n"<<position<<"\n"<<salary<<"\n"<<address<<"\n"<<phone<<"\n";
}
void Worker::load(std::istream&is){
    getline(is,name);
    getline(is,position);
    is>>salary;
    is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(is,address);
    getline(is,phone);
}
