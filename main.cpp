#include <iostream>
#include <locale>
#include "Keeper.h"

int main(){
    setlocale(LC_ALL,"");
    Keeper k;int cmd;

    while(true){
        std::cout<<"\n1-Мебель 2-Работник 3-Машина\n"
                 <<"4-Все 5-Удалить 6-Изменить\n"
                 <<"7-Сохранить 8-Загрузить 9-Выход\n>";

        std::cin>>cmd;
        try{
            if(cmd==1) k.add(new Furniture), k.get(k.get(0)->getId());
            if(cmd==1){ Base*o=new Furniture();o->input();k.add(o);}
            else if(cmd==2){ Base*o=new Worker();o->input();k.add(o);}
            else if(cmd==3){ Base*o=new Machine();o->input();k.add(o);}
            else if(cmd==4) k.printAll();
            else if(cmd==5){ int i;std::cout<<"i=";std::cin>>i;k.remove(i);}
            else if(cmd==6){ int i;std::cout<<"i=";std::cin>>i;k.get(i)->input();}
            else if(cmd==7){ k.saveToFile("data.txt");std::cout<<"Сохранено\n";}
            else if(cmd==8){ k.loadFromFile("data.txt");std::cout<<"Загружено\n";}
            else if(cmd==9) break;
        }catch(std::exception&e){ std::cout<<"Ошибка: "<<e.what()<<'\n'; }
    }
}
