
// 访问权限问题
// 1.public 子类和类外都可访问
// 2.protected 子类可访问，类外不可访问
// 3.private 子类不可访问

#include <iostream>
#include <string>
using namespace std;

// 父类：Person
class Person {
private:
    string name;

protected:
    int age;

public:
    Person(const string& name, int age)
        : name(name), age(age) {
        cout << "Person 构造函数被调用\n";
    }

    const string& getName() const {
        return name;
    }

    // 虚函数：允许子类重写
    virtual void introduce() const {
        cout << "我叫" << name
             << "，今年" << age << "岁。\n";
    }

    // 虚析构函数
    virtual ~Person() {
        cout << "Person 析构函数被调用\n";
    }
};

// 子类：Student
class Student : public Person {
private:
    string major;

public:
    Student(const string& name, int age, const string& major)
        : Person(name, age), major(major) {
        cout << "Student 构造函数被调用\n";
    }

    // 重写父类虚函数
    void introduce() const override {
        cout << "我叫" << getName()
             << "，今年" << age
             << "岁，我的专业是" << major << "。\n";
    }

    void study() const {
        cout << getName() << "正在学习 C++。\n";
    }

    ~Student() override {
        cout << "Student 析构函数被调用\n";
    }
};

// 子类：Teacher
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(const string& name, int age, const string& subject)
        : Person(name, age), subject(subject) {
    }

    void introduce() const override {
        cout << "我叫" << getName()
             << "，今年" << age
             << "岁，我教授" << subject << "。\n";
    }
};

// 普通函数：接收父类引用
void printInformation(const Person& person) {
    person.introduce();
}

int main() {
    Student student("张三", 20, "计算机科学与技术");
    Teacher teacher("李老师", 35, "数据结构");

    cout << "\n学生信息：\n";
    printInformation(student);

    cout << "\n教师信息：\n";
    printInformation(teacher);

    cout << "\n学生自己的函数：\n";
    student.study();

    return 0;
}