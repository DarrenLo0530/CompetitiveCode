#include <bits/stdc++.h>
using namespace std;

map<string, int> pri;

struct cust{
    int x;
    string s;
    bool operator < (const cust &c1){
        if(c1.x == x){
            return s < c1.s;
        } else {
            return x > c1.x;
        }
    }
};

string removeAp(string name){
    return name.substr(0, name.find("'"));
}

int main(){
    string name;
    cin >> name;
    int n;
    scanf("%d", &n);
    string t;
    getline(cin, t);

    for(int i=0; i<n; i++){
        string c;
        getline(cin, c);
        stringstream sstream(c);
        string first, second;
        string throwAway;  

        int score;

        if(c.find("posted on") != string::npos){
            sstream >> first >> throwAway >> throwAway >> second;
            score = 15;
        } else if(c.find("commented on") != string::npos){
            sstream >> first >> throwAway >> throwAway >> second;
            score = 10;
        } else {
            sstream >> first >> throwAway >> second;
            score = 5;
        }

        second = removeAp(second);
        if(first != name && second != name){
            if(pri.find(first) == pri.end()){
                pri[first] = 0;
            }

            if(pri.find(second) == pri.end()){
                pri[second] = 0;
            }

            continue;
        }

        if(first == name){
            swap(first, second);
        }

        if(pri.find(first) == pri.end()){
            pri[first] = score; 
        } else {
            pri[first] += score;
        }
    }

    vector<cust> ans;
    for(auto it = pri.begin(); it != pri.end(); ++it){
        ans.push_back(cust{it->second, it->first});
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i].s<<'\n';
    }
}