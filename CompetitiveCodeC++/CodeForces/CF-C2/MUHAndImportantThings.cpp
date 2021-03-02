#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pii> nums;

void p(){
    for(int i = 0; i<nums.size(); i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", nums[i].second);
    }

    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);

    int dupCount = 0;
    bool possible = false;

    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        nums.push_back({x, i+1});
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i<n; i++){
        if(i+1 < n && nums[i+1].first == nums[i].first){
            dupCount++;
        }

        int cnt = 1;
        for(int j = i+1; j<n; j++){
            if(nums[j].first != nums[i].first){
                break;
            }
            cnt++;
        }

        if(cnt >= 3){
            possible = true;
        }
    }

    if(dupCount >= 2){
        possible = true;
    }


    if(possible){
        printf("YES\n");
        int currPrint = 1;
        p();

        for(int i = 0; i<n && currPrint < 3; i++){
            if(i-1 >= 0 && nums[i].first == nums[i-1].first){
                swap(nums[i], nums[i-1]);
                p();
                swap(nums[i], nums[i-1]);
                currPrint++;
            }
        }
    } else {
        printf("NO\n");
    }




}