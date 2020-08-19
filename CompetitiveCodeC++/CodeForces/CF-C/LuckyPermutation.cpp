#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;

int main(){
    int n;
    scanf("%d", &n);

    if(n % 2 == 0){
        cout<<-1<<'\n';
        return 0;
    }

    for(int i = 0; i<n; i++){
        if(i != 0 ){
            cout<<" ";
        }
        cout<<i;
    }
    cout<<'\n';
    for(int i = 0; i<n; i++){
        if(i != 0 ){
            cout<<" ";
        }
        cout<<i;
    }

    cout<<'\n';

    for(int i = 0; i<n; i++){
        if(i != 0 ){
            cout<<" ";
        }
        cout<<(2*i) % n;
    }

    cout<<'\n';

    
}