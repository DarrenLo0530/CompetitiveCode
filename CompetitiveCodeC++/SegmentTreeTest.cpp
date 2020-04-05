#include <bits/stdc++.h>
#define mx 200001
#define INF 0x3f3f3f3f

using namespace std;

int N, M, botLen;
int minTree[2*mx];
pair<int, int> gcdTree[2*mx];//Pair stores the GCD of the range and the number of numbers equal to that GCD in the range

int gcd(int a, int b){  //Euclidean algorithm to get GCD
    if(a<b){
        swap(a, b);
    }

    if(a == INF){
        return b;
    }

    int newA;
    while(b != 0){
        newA = b;
        b = a%b;
        a = newA;
    }

    return a;
}

pair<int, int> gcdFreq(pair<int, int> a, pair<int, int> b){ 
    //Gets GCD and sees if the GCD is either number
    //If the GCD is equal, the GCD frequency from that number carries over and is added as the GCD did not change
    int gcdAns = gcd(a.first, b.first);
    int gcdCnt = 0;
    if(gcdAns == a.first){
        gcdCnt += a.second;
    }
    if(gcdAns == b.first){
        gcdCnt += b.second;
    }

    return make_pair(gcdAns, gcdCnt);
}

void updateMinNode(int idx, int newVal){
    idx += botLen-1;
    minTree[idx] = newVal;

    while(idx > 1){
        idx = idx/2;
        minTree[idx] = min(minTree[idx*2], minTree[idx*2+1]);
    }
}       

void updateGCDNode(int idx, int newVal){
    idx += botLen-1;
    gcdTree[idx] = make_pair(newVal, 1);

    while(idx > 1){
        idx = idx/2;
        pair<int, int> gcdAns = gcdFreq(gcdTree[idx*2], gcdTree[idx*2+1]);
        
        gcdTree[idx].first = gcdAns.first;
        gcdTree[idx].second = gcdAns.second;
    }
}  

int query(int l, int r, char opp){
    //Either queries GCD or the min depending on operation letter
    int ans = (opp == 'M') ? INF: 0;

    l += botLen-1;
    r += botLen-1;

    while(l<=r){
        if(l%2 != 0){
            ans = (opp == 'M') ? min(ans, minTree[l]) : gcd(ans, gcdTree[l].first);
            l+=1;
        }
        if(r%2 == 0){
            ans = (opp == 'M') ? min(ans, minTree[r]) : gcd(ans, gcdTree[r].first);
            r-=1;
        }
        l = l/2;
        r = r/2;
    }
    return ans;
}


int queryFreq(int l, int r){
    //Basically querying GCD except it keeps track of the number of nodes equal to GCD to
    pair<int, int> ans = make_pair(0, 0);
    pair<int, int> gcdFreqInfo;
    
    l += botLen-1;
    r += botLen-1;

    while(l<=r){
        if(l%2 != 0){
            gcdFreqInfo = gcdFreq(ans, gcdTree[l]);
            ans.first = gcdFreqInfo.first;
            ans.second = gcdFreqInfo.second;
            l+=1;
        }
        if(r%2 == 0){
            gcdFreqInfo = gcdFreq(ans, gcdTree[r]);
            ans.first = gcdFreqInfo.first;
            ans.second = gcdFreqInfo.second;
            r-=1;
        }
        l = l/2;
        r = r/2;
    }

    return ans.second;

}

void change(int x, int v){
    updateGCDNode(x, v);    
    updateMinNode(x, v);
}

int main(){
    //Sets default values
    memset(minTree, INF, sizeof(minTree));
    for(int i = 0; i<2*mx; i++){
        gcdTree[i] = make_pair(INF, 0);
    }

    scanf("%d %d", &N, &M);
    botLen = pow(2, ceil(log2(N)));

    int a;
    for(int i = 1; i<=N; i++){
        scanf("%d", &a);
        updateMinNode(i, a);
        updateGCDNode(i, a);
    }   
    
    char opp;
    int x, y;

    for(int i = 0; i<M; i++){
        scanf(" %c %d %d", &opp, &x, &y);
        if(opp == 'C'){ 
            change(x, y);
        } else if(opp == 'Q'){
            cout<<queryFreq(x, y)<<"\n";
        } else {
            cout<<query(x, y, opp)<<"\n";
        }
    }
    
}