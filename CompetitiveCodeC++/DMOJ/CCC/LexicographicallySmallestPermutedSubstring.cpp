#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int MX = 2e5 + 10;

vector<int> nums;

int permCount[MX];
int totCount[MX];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        totCount[x]++;

        if(i < k) {
            permCount[x]++;
        }
        nums.push_back(x);
    }


        vector<int> lexSmallest;
        for(int i = 0; i<n; i++) {
            int curr = nums[i];
            if(!(permCount[curr] <= 0)) {
                while(!lexSmallest.empty()) {   
                    int back = lexSmallest.back();
                    if(curr < back && totCount[back] >= permCount[back] + 1) {
                        lexSmallest.pop_back();
                        permCount[back]++;
                    } else {
                        break;
                    }
                }
                lexSmallest.push_back(curr);
                permCount[curr]--;
            }

            totCount[curr]--;
        }

        assert(lexSmallest.size() == k);
    
    for(int i = 0; i<k; i++){
        if(i != 0){ 
            printf(" %d", lexSmallest[i]);
        } else {
            printf("%d", lexSmallest[i]);
        }
    }

    

}   

//6 3
//3 2 1 3 2 3