#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
struct interval {
    int l, r;
    int size(){
        return r - l +  1;
    }
    int mid(){
        return (l + r)/2;
    }
};

struct compare {
    bool operator() (interval &i1, interval &i2){
        if(i1.size() == i2.size()){
            return i1.l > i2.l;
        }
        return i1.size() < i2.size();
    }
};

const int MX = 2e5 + 1;
int ans[MX];

int main(){
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i<t; i++){
        int n;
        scanf("%d", &n);
        memset(ans, false, sizeof(ans));
        priority_queue<interval, vector<interval>, compare> pq;
        pq.push(interval{1, n});
        int cnt = 1;
        while(!pq.empty()){
            interval next = pq.top();
            pq.pop();
            ans[next.mid()] = cnt++;

            if(next.mid() - 1 >= next.l){
                pq.push(interval{next.l, next.mid() - 1});
            }
            if(next.r >= next.mid() + 1){
                pq.push(interval{next.mid() + 1, next.r});
            }
        }

        for(int i = 1; i<=n; i++){
            if(i != 1){
                printf(" ");
            }
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}