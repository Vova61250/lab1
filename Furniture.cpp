#include "Furniture.h"
#include <limits>

Furniture::Furniture() : height(0),width(0),depth(0),cost(0) {}
Furniture::Furniture(const std::string&t,double h,double w,double d,const std::string&c,const std::string&m,double ct){
    type=t;height=h;width=w;depth=d;color=c;material=m;cost=ct;
}
Furniture::Furniture(const Furniture&f):Base(f){
    type=f.type;height=f.height;width=f.width;depth=f.depth;color=f.color;material=f.material;cost=f.cost;
}

void Furniture::print() const {
    std::cout<<"[Мебель ID "<<id<<"] "<<type<<" ("<<color<<") "<<cost<<"р\n";
    std::cout<<"Размеры: "<<height<<"x"<<width<<"x"<<depth<<" Материал: "<<material<<"\n";
}

void Furniture::input(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Тип: "; getline(std::cin,type);
    std::cout<<"Высота: "; std::cin>>height;
    std::cout<<"Ширина: "; std::cin>>width;
    std::cout<<"Глубина: "; std::cin>>depth;
    std::cout<<"Цена: "; std::cin>>cost;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Цвет: ";getline(std::cin,color);
    std::cout<<"Материал: ";getline(std::cin,material);
}

void Furniture::save(std::ostream&os) const {
    os<<type<<"\n"<<height<<" "<<width<<" "<<depth<<"\n"<<color<<"\n"<<material<<"\n"<<cost<<"\n";
}

void Furniture::load(std::istream&is){
    std::getline(is,type);
    is>>height>>width>>depth;
    is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(is,color);
    std::getline(is,material);
    is>>cost;
    is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}
