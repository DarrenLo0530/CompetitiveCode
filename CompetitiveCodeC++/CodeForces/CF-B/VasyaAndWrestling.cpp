#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
long long ap = 0, bp = 0;

int main(){
    int n;
    scanf("%d", &n);
    int last;
    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        if(x < 0){
            b.push_back(-x); 
            bp += -x;
        } else {
            a.push_back(x);
            ap += x;
        }

        last = x;
    }

    if(ap > bp){
        cout<<"first";
        return 0;
    } else if(bp > ap){
        cout<<"second";
        return 0;
    }

    for(int i = 0; i< min(a.size(), b.size()); i++){
        if(a[i] > b[i]){
            cout<<"first"<<'\n';
            return 0;
        } else if(b[i] > a[i]){
            cout<<"second"<<'\n';
            return 0;
        }

    }

    if(a.size() > b.size()){
        cout<<"first"<<"\n";
        return 0;
    } else if(b.size() > a.size()){
        cout<<"second"<<'\n';
        return 0;
    } else {
        if(last > 0){
            cout<<"first";
        } else {
            cout << "second";
        }
    }
}