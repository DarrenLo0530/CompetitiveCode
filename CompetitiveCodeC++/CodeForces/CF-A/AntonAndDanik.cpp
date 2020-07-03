#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    string games;
    cin>>games;

    int dWon = count(games.begin(), games.end(), 'D');
    int aWon = n-dWon;

    if(aWon == dWon){
        cout<<"Friendship"<<'\n';
    } else if(aWon > dWon){
        cout<<"Anton"<<'\n';
    } else {
        cout<<"Danik"<<"\n";
    }
}