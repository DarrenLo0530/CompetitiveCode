#include <bits/stdc++.h>
using namespace std;
double p[21];
double ans[21];
bool used[21];
int n, r;
//Probability that r people are exactly chosen
double totalProb = 0;
void gen(double prob, int curr, int cnt){
    if(curr == n && cnt == r){
        totalProb += prob;
        for(int i = 0; i<n; i++){
            if(used[i]){
                ans[i] += prob;
            }
        }
        return;
    } else if(curr >= n){
        return;
    }

    if(cnt < r){
        used[curr] = true;
        gen(prob * p[curr], curr+1, cnt+1);
    }

    used[curr] = false;
    gen(prob * (1.0 - p[curr]), curr+1, cnt);
}


int main(){
    int t = 0;
    while(cin >> n >> r){
        for(int i = 0; i<21; i++){
            p[i] = ans[i] = used[i] = 0;
        }
        totalProb = 0;

        if(!n && !r){
            break;
        }   

        printf("Case %d:\n", ++t);
        double total = 0;
        for(int i = 0; i<n; i++){
            cin >> p[i];
        }
        
        gen(1.0, 0, 0);

        for(int i=0; i<n; i++){
            //We must first restrict the possibility to when we get exactly R people since we are asked possibility of person being chosen if we alreayd know exactly R people were chosen
            //If it asked for possibility that exactly R people where chosen AND person i was one of them, I don't think we would divide by totalProb.
            //Num events that satisfy/num possible events
            //AKA
            //Poss where person i is included in a group of exactly r people/Poss where exactly r people are selected
            printf("%.6f\n", ans[i]/totalProb);
        }
    }
}