#ifndef ITEM_H_
#define ITEM_H_
#include<string>

class Item
{
private:
    std::string _name;
    int _age;
public:
    Item():_name("default"),_age(0){};
    Item(std::string name,int age):_name(name),_age(age){};

    std::string getName() const {return _name;}
    int getAge() const {return _age;}

    void changeName(const std::string &name){_name=name;}
    void changeAge(int age){_age=age;}
    
    ~Item(){};
};



#endif