#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myprint(int a){
    cout<<a<<endl;
}

void test01(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // // 第一种遍历方法
    // vector<int>::iterator itBegin = v.begin();
    // vector<int>::iterator itEnd = v.end();

    // while(itBegin != itEnd){
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // //第二种
    // for(vector<int>::iterator it=v.begin();it!=v.end();it++){
    //     cout<<*it<<endl;
    // }
    //第三种，利用STL的遍历算法
    for_each(v.begin(),v.end(),myprint);
}

int main(){
    test01();
}