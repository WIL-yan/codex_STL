#include<iostream>
#include<string>
using namespace std;

//查找
void test01(){
    string str1="abcdefgde";
    int pos=str1.find("de");   //找到返回下标，没有返回-1
    cout<<"pos = "<<pos<<endl;

    //rfind(从右向左查找)
    pos=str1.rfind("de");
    cout<<"pos = "<<pos<<endl;

}

void test02(){
    string str1="abcdefg";
    str1.replace(1,3,"1111");            //从哪里开始，替换多少个，加什么
    cout<<"str1 = "<<str1<<endl;
}

int main(){
    test01();
    test02();
    return 0;
}