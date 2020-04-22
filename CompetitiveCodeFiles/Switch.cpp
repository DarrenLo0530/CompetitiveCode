#include <bits/stdc++.h>
using namespace std;

int K, a;
bool checked[33554433];
int powers[25];


int main(){
    for(int i = 0; i<25; i++){
        powers[i] = 1<<i;
    }

    scanf("%d", &K);
    int hsh = 0;

    for(int i = 0; i<K; i++){
        scanf("%d", &a);
        hsh += a * powers[i];
    }

    int turn = 0;
    queue<int> tv;
    tv.push(hsh);

    while(true){
        queue<int> nextTv;

        while(!tv.empty()){
            int curr = tv.front();
            checked[curr] = true;
            tv.pop();

            if(curr == 0){
                cout<<turn;
                return 0;
            }

            for(int i = 0; i<K; i++){
                if((curr & powers[i]) == 0){ //ith bit from left is 0
                    int copy = curr;
                    copy += powers[i];
                    
                    int oldStart = 0;
                    for(int j = 0; j<=K; j++){ //Check if jth bit is off
                        if((copy & powers[j]) == 0){
                            if(j - oldStart >= 4){
                                for(int k = oldStart; k<j; k++){
                                    copy -= powers[k];
                                }
                            }
                            oldStart = j+1;
                        }
                    }

                    if(!checked[copy]){
                        checked[copy] = true;
                        nextTv.push(copy);
                    }
                }
            }
        }

        tv = nextTv;
        ++turn;
    }
}