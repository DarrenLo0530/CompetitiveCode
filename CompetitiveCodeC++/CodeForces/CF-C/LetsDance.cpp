#include <bits/stdc++.h>
using namespace std;
long double nk[110][110];
void gen(){
    nk[0][0] = 1;
    for(int i = 1; i<=100; i++){
        nk[i][0] = 1;
        for(int j = 1; j<=i; j++){
            nk[i][j] = nk[i-1][j-1] + nk[i-1][j];
        }
    }
}
int main(){
    gen();

    while(true){
        int m, w, c;
        scanf("%d%d%d", &m, &w, &c);
        if(m == 0 && w == 0){
            break;
        }
        double ans = 0;
        double mp = (double)m/(m+w);
        double wp = (double)1 - mp;
        
        
        for(int i = 0; i <= c; i+=2){
            //Since evenly distributed, it matters which candy was given to the men or women
            //For example if one distribution, the first candy was given to the man and the second to a women
            //It is different than another distribution where first candy was given to a women and the second to a man
            //It does not matter WHICh man or women it is given to seeing as the 2nd and 3rd parts account for 
            //WHICh man or women the candy was given to.
            //Candies choose i means we choose i of the candies to have gone to the men
            //Second part is the change that you choose i men
            //Third part is the change that you have chosen c-i women
            //AKA chance that you've chosen i men and the rest are women
            ans += nk[c][i] * pow(mp, i) * pow(wp, c-i);
        }

        printf("%.7lf\n", ans);
    }
}