#include<bits/stdc++.h>
using namespace std;

class student{
    private:
    string name;
    int score;
    public:
    student(string n,int sc ){
        name=n;
        score=sc;
    }
    int  get_score()const{
        return score;
    }
    string get_name()const{
        return name;
    }
};


int main(){
    //lambda
    int x=10;
    double y=2.5;
    auto p=[&](int a,int b){return x+y+a*b;};
    cout<<p(2,4)<<endl;
    //如果想修改捕获进来的副本，需要加 mutable
    int n = 10;
    auto f = [n]() mutable {
        n++;
        cout << n << endl;
    };
    f(); // 11
    cout << n << endl; // 10


    //lambda在sort里的应用
    vector<student> s={{"leo",30},{"lisa",20},{"alice",10}};
    sort(s.begin(),s.end(),[](student a,student b){
        return a.get_score()<b.get_score();
    });

    for(const auto& x:s){
        cout<<x.get_name()<<' '<<x.get_score()<<endl;
    }
    return 0;
}