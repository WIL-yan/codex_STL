#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Box{
    private:
    T value;
    public:
    Box(T v){
        value=v;
    }
    T get() const{
        return value;
    }
    void set(T v){
        value=v;
    }
};

int main(){
    Box<int> b1(10);
    Box<string> b2("hello");


    cout<<b1.get()<<endl;
    cout<<b2.get()<<endl;

    return 0;
}