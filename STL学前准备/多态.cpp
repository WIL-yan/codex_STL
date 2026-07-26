#include<iostream>
#include<string>
using namespace std;
//实现运行时多态需要满足三个条件：
// 1.存在继承关系
// 2.基类函数使用 virtual
// 3.使用基类指针或基类引用调用函数

class Animals{
    public:
    virtual void  speak(){
        cout<<"动物发出声音"<<endl;
    }
};

class Dog:public Animals{
    public:
    void speak(){
        cout<<"汪汪汪"<<endl;
    }
};

class Cat:public Animals{
    public:
    void speak(){
        cout<<"喵喵喵"<<endl;
    }
};

int main(){
    Cat c;
    Dog d;
    Animals a1=c;
    Animals a2=d;
    a1.speak();
    a2.speak();
    return 0;
}