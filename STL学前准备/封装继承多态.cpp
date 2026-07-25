#include<iostream>
#include<string>

using namespace std;

class Student:public Person{
    private:
    string name;
    int age;
    static int count;
    public:
    Student(string n){
        name=n;
    }
    void study(){
        cout<<"正在学习"<<endl;
    }
    //如果成员函数不会改变成员变量，可在后面加上const
    string getname()const{
        return name;
    }
    static void  showcount(){
        cout<<count<<endl;
    }
    //静态成员函数不能访问成员函数变量
    static void showCount() {
        cout << count << endl;
    }
    //初始化列表
    Student(string n,int a):name(n),age(a){
        cout<<"student对象被创建"<<endl;
    }
    //拷贝构造函数
    Student(const Student& s){
        this->age=s.age;
        this->name=s.name;

    }
    //析构函数在离开创建对象的所在作用域是销毁，在同一个作用域内，先创建的对象最后被销毁，继承过程中，先析构子类再析构父类
    ~Student(){
        cout<<"student对象被销毁"<<endl;
    }
    //友元
    friend  void visit(const Student& s);

};

class Person{
    private:

    public:
    void eat(){
        cout<<"正在吃饭"<<endl;
    }
};

void visit(const Student& s){
    cout<<s.name<<endl;
}
int Student:: count=10;
int main(){
    string na;
    int a;
    cin>>na>>a;
    Student stu(na);
    Student st(na,a);
    cout<<stu.getname()<<endl;
    return 0;
}