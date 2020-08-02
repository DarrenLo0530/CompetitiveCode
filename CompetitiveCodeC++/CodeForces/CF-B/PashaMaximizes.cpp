#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string a;
    cin >> a;

    int k;
    scanf("%d", &k);

    int start = 0;
    while(k > 0 && start < a.size()){
        int maxIdx = start;
        int maxVal = a[start] - '0';
        for(int j = start+1; j<min(start+k+1, (int) a.size()); j++){
            if(a[j] - '0' > maxVal){
                maxIdx = j;
                maxVal = a[j] - '0';
            }
        }

        k -= (maxIdx - start);
        for(int i = maxIdx; i>start; i--){
            swap(a[i], a[i-1]);
        }
        start++;
    }
    
    cout<<a;
}