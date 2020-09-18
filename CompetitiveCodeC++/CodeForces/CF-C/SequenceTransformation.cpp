#include <bits/stdc++.h>
using namespace std;


int main(){
    //All ans are length n
    //Has to start off with atleast n/2 1's
    //gcd of 2 or more primes is 1
    //gcd of consecutive numbers is 1/
    int n;
    scanf("%d", &n);


    int num = 1;
    int cnt = n;
    vector<int> ans;
    while(cnt > 0){
        if(cnt == 3){
            ans.push_back(pow(2, num-1));
            ans.push_back(pow(2, num-1));
            ans.push_back(3 * pow(2, num-1));
            break;
        }
        int amount = cnt - n/(int)pow(2, num);
        cnt -= amount;
        
        for(int i = 0; i < amount; i++){
            ans.push_back(pow(2, num-1));
        }
        num++;
    }

    for(int i = 0; i<n; i++){
        if(i != 0){
            cout<<" ";
        }
        cout<<ans[i];
    }    

    cout<<'\n';
}