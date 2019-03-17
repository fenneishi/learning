#include<iostream>

#include "list.h"


void showStu(Item &);
void chanEge(Item &);
void chanNam(Item &);

int main(int argc, char const *argv[])
{
    List list;

    list.add(Item("student1",11));
    list.add(Item("student2",12));
    list.add(Item("student3",13));
    list.add(Item("student4",14));
    list.visit(showStu);

    list.visit(chanNam);
    list.visit(showStu);

    list.visit(chanEge);
    list.visit(showStu);


    return 0;
}

void showStu(Item &stu)
{
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<stu.getName()<<":"<<stu.getAge()<<std::endl;
}
void chanEge(Item &stu)
{
    int newAge;
    std::cout<<stu.getName()<<" new age:";
    std::cin>>newAge;
    stu.changeAge(newAge);
}
void chanNam(Item &stu)
{
    std::string newName;
    std::cout<<stu.getName()<<" new name:";
    std::cin>>newName;
    stu.changeName(newName);
}



