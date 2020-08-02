#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    set<int> squares;
    for(int i = 1; i<=100; i++){
        squares.insert(i*i);
    }

    while(t--){
        int n;
        scanf("%d", &n);
        set<int> nums;
        int i = 0;

        while(true){
            i++;
            int search = 0x3f3f3f3f;
            for(int k: nums){
                if(squares.count(k + i)){
                    search = min(search, k);
                }
            }

            if(search == 0x3f3f3f3f){
                if(nums.size() < n){
                    nums.insert(i);
                } else {
                    cout<<i-1<<'\n';
                    break;
                }
            } else {
                nums.erase(search);
                nums.insert(i);
            }
        }
    }
}