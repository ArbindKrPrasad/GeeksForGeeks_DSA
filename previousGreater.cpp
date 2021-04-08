#include<bits/stdc++.h>
using namespace std;

vector<int> previousGreater(vector<int> vec){
    vector<int> res;
    stack<int> s;
    res.push_back(-1);
    s.push(vec[0]);

    for(int i=1; i<vec.size(); i++){
        while(!s.empty() && s.top()<vec[i]){
            s.pop();
        }

        (s.empty()) ? res.push_back(-1) : res.push_back(s.top());
        s.push(vec[i]); 
    }
    return res;
}

int main(){
    vector<int> vec = {15, 10, 18, 12, 4, 6, 2, 8};
    vector<int> res = previousGreater(vec);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}