#include<iostream>
#include<string>

using namespace std;

class Student{
    private:
    string name;
    int age;
    static int count;
    public:
    Student(string n){
        name=n;
    }
    //如果成员函数不会改变成员变量，可在后面加上const
    string getname()const{
        return name;
    }
    static void  showcount(){
        cout<<count<<endl;
    }
    //初始化列表
    Student(string n,int a):name(n),age(a){
        cout<<"student对象被创建"<<endl;
    }
    //析构函数在离开创建对象的所在作用域是销毁，在同一个作用域内，先创建的对象最后被销毁，继承过程中，先析构子类再析构父类
    ~Student(){
        cout<<"student对象被销毁"<<endl;
    }
    //友元
    friend  void visit(const Student& s);

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