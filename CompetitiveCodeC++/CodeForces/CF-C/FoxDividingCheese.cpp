    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int a, b;
        scanf("%d%d", &a, &b);
        
        int ans = 0;
        for(int i = 0; i<2; i++){
            int gcd = a/__gcd(a, b);

            while(gcd % 5 == 0){
                gcd/=5;
                ans++;
            }
            while(gcd % 3 == 0){
                gcd/=3;
                ans++;
            }
            while(gcd % 2 == 0){
                gcd/=2;
                ans++;
            }

            if(gcd != 1){
                cout<<-1<<'\n';
                return 0;
            }
            swap(a, b);
        }

        cout<<ans<<'\n';



    }