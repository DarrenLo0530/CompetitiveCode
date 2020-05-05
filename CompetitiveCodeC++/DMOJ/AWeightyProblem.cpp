#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define mx 200001
pair<int, double> d[101];
pair<int, double> sorted[101];
int coins[101]; 
int C, D, K, v;
double w;

double dp[mx];

double calculateWeightReturned(int change){
    double weight = 0;
    for(int i = D-1; i>=0; i--){
        int num = change / sorted[i].first;
        weight += sorted[i].second*num;
        change %= sorted[i].first;
    }


    return weight;
}

int main(){
    for(int i = 0; i<mx; i++){
        dp[i] = -1;
    }
    cin>>C>>D>>K;

    for(int i = 0; i<D; i++){
        cin>>v>>w;
        d[i] = make_pair(v, w);
        sorted[i] = make_pair(v, w);
    }

    sort(sorted, sorted + D);


    int total = 0;
    double totalWeight = 0;
    for(int i = 1; i<=K; i++){
        cin>>coins[i];
        coins[i]--;
        total += d[coins[i]].first;
        totalWeight += d[coins[i]].second;
    }

    if(total < C){  
        cout<<"too poor\n";
        return 0;
    }
    
    dp[0] = 0;

    for(int f = 1; f<=K; f++){
        int i = coins[f];

        for(int j = total; j>=0; j--){
            if(j - d[i].first < 0){
                continue;
            }

            if(dp[j-d[i].first] != -1)
                dp[j] = max(dp[j-d[i].first] + d[i].second, dp[j]);
        }
    }



    double ans = INF;
    for(int j = C; j<=total; j++){
        if(dp[j] != -1)
            ans = min(ans, totalWeight - dp[j] + calculateWeightReturned(j - C));
    }

    printf("%.2f\n", ans);
}