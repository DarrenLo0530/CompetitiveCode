#include <bits/stdc++.h>
using namespace std;

int wait[1002];
vector<int> bark[1002];
int timeBarked[1002];
int currWaiting[1002];
bool noUpdate[1002];
int update[1002];

int D, F, T, a, b;

int main(){
    cin>>D;
    for(int i = 1; i<=D; i++){
        cin>>wait[i];
    }

    cin>>F;
    for(int i = 0; i<F; i++){
        cin>>a>>b;
        bark[a].push_back(b);
    }
    cin>>T;

    currWaiting[1] = 1;

    for(int i = 0; i<=T; i++){
        memset(noUpdate, false, sizeof(noUpdate));
        memset(update, 0, sizeof(update));
        for(int j = 1; j<=D; j++){
            if(currWaiting[j] > 0){
                currWaiting[j]--;
                if(currWaiting[j] == 0){
                    noUpdate[j] = true;
                    timeBarked[j]++;
                    for(int b: bark[j]){
                        if(currWaiting[b] == 0){    
                            update[b] = wait[b];
                        }
                    }
                }
            }
        }

        for(int j = 1; j<=D; j++){
            if(!noUpdate[j]){
                currWaiting[j] += update[j];
            }
        }
    }

    for(int i = 1; i<=D; i++){
        cout<<timeBarked[i]<<"\n";
    }

}