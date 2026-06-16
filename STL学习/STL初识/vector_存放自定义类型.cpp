#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class person{
    public:
    string name;
    int age;
    person(string n,int a){
        name=n;
        age=a;
    }

};

void test01(){
    vector<person> v;
    person p1("aaa",10);
    person p2("bbb",11);
    person p3("ccc",12);
    person p4("ddd",13);
    person p5("eee",14);

    //向容器中存放数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //遍历数据
    for(vector<person>::iterator it=v.begin();it!=v.end();it++){
        cout<<(*it).name<<endl<<(*it).age<<endl;

    } 
}

void test02(){
    vector<person*> v;
    person p1("aaa",10);
    person p2("bbb",11);
    person p3("ccc",12);
    person p4("ddd",13);
    person p5("eee",14);

    //向容器中存放数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for(vector<person*>::iterator it=v.begin();it!=v.end();it++){
        cout<<(*it)->name<<endl<<(*it)->age<<endl;
    }
}

int main(){
    test02();
    return 0;
}