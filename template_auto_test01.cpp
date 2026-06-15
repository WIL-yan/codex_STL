#include<bits/stdc++.h>
using namespace std;

int main(){
    //auto
    auto x=3.14;
    auto y="hello";
    cout<<x<<endl<<y<<endl;
    //auto
    vector<string> names={"alice","leo","lisa"};
    for(auto x:names){
        x+="!";
    }
    for(auto x:names){
        cout<<x<<endl;
    }
    //auto&
    for(auto& x:names){
        x+='!';
    }
    //const auto&
    for(const auto& x:names){
        cout<<x<<endl;
    }
    


    return 0;
}