#include <bits/stdc++.h>
using namespace std;

int nums[100010];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", nums + i);
    }
    bool isDecreasing = false;
    int l = 1;
    int r = 1;
    bool onlyOne = true;
    bool hasDecreased = false;

    for(int i = 1; i<=n; i++){
        if(nums[i] < nums[i-1] && !isDecreasing){
            isDecreasing = true;
            l = i-1;
        }
        if(nums[i] > nums[i-1] && isDecreasing){
            isDecreasing = false;
            hasDecreased = true;
            r = i-1;
        }

        if(nums[i] < nums[i-1] && hasDecreased){
            onlyOne = false;
        }
    }

    if(isDecreasing){
        hasDecreased = true;
        r = n;
    }
    nums[n + 1] = 0x3f3f3f3f;

    if(hasDecreased && onlyOne){
        if(nums[r] > nums[l-1] && nums[l] < nums[r+1]){
            cout << "yes\n";
            printf("%d %d\n", l, r);
        } else {
            cout << "no\n";
        }
    } else if (!hasDecreased){
        cout << "yes\n";
        printf("%d %d\n", l, r);
    } else {
        cout << "no\n";
    }
}