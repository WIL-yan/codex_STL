#include<bits/stdc++.h>
using namespace std;

struct student{
    string name;
    int score;
    //<的重载
    bool operator<(const student& s) const{
        return score<s.score;
    }
};
struct Point {
    int x;
    int y;
    //==的重载
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

int main(){

    vector<student> v={{"alice",10},{"leo",30},{"lisa",20}};
    sort(v.begin(),v.end());
    for(const auto& x: v){
        cout<<x.name<<endl;
    }
    Point a{1, 2};
    Point b{1, 2};

    if (a == b) {
        cout << "same" << endl;
    }
    return 0;
}