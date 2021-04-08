#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> vec){
    stack<int> s;
    vector<int> res;
    s.push(vec[vec.size()-1]);
    res.push_back(-1);
    for(int i=vec.size()-2; i>=0; i--){
        while(!s.empty() && s.top()<=vec[i]){
            s.pop();
        }

        (s.empty())?res.push_back(-1):res.push_back(s.top());
        s.push(vec[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<int> vec = {15, 10, 18, 12, 4, 6, 2, 8};
    vector<int> res = nextGreater(vec);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}