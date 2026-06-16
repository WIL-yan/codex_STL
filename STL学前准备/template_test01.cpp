#include<bits/stdc++.h>
using namespace std;

template<class T>
void swap_T(T& a,T& b){
    T temp=a;
    a=b;
    b=temp;
}

int main(){

    int a,b;
    cin>>a>>b;
    cout<<'a'<<' '<<a<<endl
        <<'b'<<' '<<b<<endl;
    swap_T(a,b);
    cout<<'a'<<' '<<a<<endl
        <<'b'<<' '<<b<<endl;
    return 0;
}