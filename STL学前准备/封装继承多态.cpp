#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    int weight;

public:
    Person(int w) : weight(w) {}

    void eat() {
        cout << "正在吃饭" << endl;
    }
};

class Student : public Person {
private:
    string name;
    int age;
    static int count;

public:
    // 调用父类构造函数，将体重暂时初始化为 0
    Student(string n)
        : Person(0), name(n), age(0) {}

    void study() {
        cout << "正在学习" << endl;
    }

    // const 表示该函数不会修改对象的成员变量
    string getname() const {
        return name;
    }

    static void showcount() {
        cout << count << endl;
    }

    // showcount 和 showCount 是两个不同的函数名
    static void showCount() {
        cout << count << endl;
    }

    // 初始化列表
    Student(int w, string n, int a)
        : Person(w), name(n), age(a) {
        cout << "Student对象被创建" << endl;
    }

    // 拷贝构造函数
    Student(const Student& s)
        : Person(s.weight), name(s.name), age(s.age) {
        cout << "Student对象被拷贝" << endl;
    }

    //析构函数在离开创建对象的所在作用域是销毁，在同一个作用域内，先创建的对象最后被销毁，继承过程中，先析构子类再析构父类
    ~Student() {
        cout << "Student对象被销毁" << endl;
    }

    // 友元函数声明
    friend void visit(const Student& s);
};

// 友元函数定义
void visit(const Student& s) {
    cout << s.name << endl;
}

// 静态成员变量在类外初始化
int Student::count = 10;

int main() {
    string na;
    int a, w;

    cin >> na >> a >> w;

    Student stu(na);
    Student st(w, na, a);

    cout << stu.getname() << endl;

    visit(st);

    return 0;
}