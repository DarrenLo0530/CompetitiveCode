    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int divs[1000001];

    int numDivs(int num){
        if(divs[num] != 0){
            return divs[num];
        }

        for(int j = 1; j<=sqrt(num); j++){
            if((double)num/j == j){
                divs[num]++;
            } else if ((double)num/j == num/j){
                divs[num]+=2;
            }
        }

        return divs[num];
    }

    const int m = 1073741824;
    int main(){
        

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ll ans = 0;
        for(int i = 1; i<=a; i++){
            for(int j = 1; j<=b; j++){
                for(int k = 1; k<=c; k++){
                    ans += numDivs(i*j*k);
                    ans %= m;
                }
            }
        }

        printf("%lld", ans);

        


    }