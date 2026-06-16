#include<bits/stdc++.h>
using namespace std;
//decltype来获取一个表达式的类型

template<typename T,typename U>
auto add_auto(T a,U b)->decltype(a+b){
    return a+b;
}
int main(){
    auto a=1;
    decltype(a) b=2;
    cout<<b<<endl;

    cout<<add_auto(2,2.5)<<endl;
    return 0;

}