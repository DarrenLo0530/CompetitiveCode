#include <bits/stdc++.h>
using namespace std;

queue<int> p1;
queue<int> p2;

long long player1;
long long player2;

int main(){
    int n;
    scanf("%d", &n);
    int k1;
    scanf("%d", &k1);

    for(int i = 0; i<k1; i++){
        int x;
        scanf("%d", &x);
        p1.push(x);
    }

    int k2;
    scanf("%d", &k2);

    for(int i = 0; i<k2; i++){
        int x;
        scanf("%d", &x);
        p2.push(x);
    }

    int moves = 0;
    while(moves < 40000000){
        if(p1.size() == 0){
            cout<<moves<<" 2"<<'\n';
            return 0;
        } else if (p2.size() == 0){
            cout<<moves<<" 1"<<'\n';
            return 0;
        }
        
        if(p2.front() > p1.front()){
            p2.push(p1.front());
            p2.push(p2.front());
        } else {
            p1.push(p2.front());
            p1.push(p1.front());
        }
        p2.pop();
        p1.pop();

        moves++;

    }

    cout<<-1<<'\n';


}
