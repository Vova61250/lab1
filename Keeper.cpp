#include "Keeper.h"
#include "MyException.h"
#include <limits>

Keeper::Keeper():arr(nullptr),size(0){}
Keeper::Keeper(const Keeper&o):arr(nullptr),size(o.size){
    arr=new Base*[size];
    for(int i=0;i<size;i++) arr[i]=o.arr[i]->clone();
}
Keeper& Keeper::operator=(const Keeper&o){
    if(this==&o)return *this;
    clear(); size=o.size; arr=new Base*[size];
    for(int i=0;i<size;i++)arr[i]=o.arr[i]->clone();
    return *this;
}
Keeper::~Keeper(){ clear(); }

void Keeper::clear(){
    for(int i=0;i<size;i++) delete arr[i];
    delete[] arr;arr=nullptr;size=0;
}

void Keeper::add(Base*o){
    if(!o) throw MyException("NULL объект");
    Base**tmp=new Base*[size+1];
    for(int i=0;i<size;i++)tmp[i]=arr[i];
    tmp[size]=o;
    delete[]arr;arr=tmp;size++;
}

void Keeper::remove(int i){
    if(i<0||i>=size) throw MyException("Неверный индекс");
    delete arr[i];
    Base**tmp=new Base*[size-1];
    for(int j=0,k=0;j<size;j++) if(j!=i) tmp[k++]=arr[j];
    delete[]arr;arr=tmp;size--;
}

Base* Keeper::get(int i) const{
    if(i<0||i>=size) throw MyException("Неверный индекс");
    return arr[i];
}

void Keeper::printAll() const{
    if(size==0) std::cout<<"Нет объектов\n";
    else for(int i=0;i<size;i++){ std::cout<<"--- "<<i<<" ---\n"; arr[i]->print(); }
}

void Keeper::saveToFile(const char*file) const{
    std::ofstream f(file);
    if(!f) throw MyException("Ошибка файла");
    f<<size<<"\n";
    for(int i=0;i<size;i++){
        f<<arr[i]->getType()<<'\n';
        arr[i]->save(f);
    }
}

void Keeper::loadFromFile(const char*file){
    std::ifstream f(file);
    if(!f) throw MyException("Нет файла");
    clear();
    int n,t; f>>n; f.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    for(int i=0;i<n;i++){
        f>>t;f.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        Base*o=nullptr;
        if(t==1)o=new Furniture();
        if(t==2)o=new Worker();
        if(t==3)o=new Machine();
        o->load(f); add(o);
    }
}
