#include <bits/stdc++.h>
using namespace std;
int a[10], b[10], c[10];
vector<int> ans;
int n;
vector<int> dig(int n){
    //Get value of each digit
    vector<int> digs;
    int p = 1;
    for(int i = 0; i<4; i++){
        digs.push_back(n/p % 10);
        p*=10;
    }
    return digs;
}

int isDiff(int n){
    //Check that all digits are distinct
    vector<int> digits = dig(n);
    for(int j = 0; j<4; j++){
        for(int k = j-1; k>=0; k--){
            if(digits[j] == digits[k]){
                return false;
            }
        }
    }

    return true;
}

void solve(){
    int cnt = 0;
    //Try every 4 digit number
    for(int i = 0; i<9999; i++){
        if(!isDiff(i)){
            continue;
        }          

        vector<int> ansDig = dig(i);
        bool satisfiesAll = true;

        //Check that it satisfiies all the queries with matching bulls and cows
        for(int j = 0; j<n; j++){
            vector<int> expDig = dig(a[j]);
            int bulls = 0, cows = 0;
            for(int k = 0; k<4; k++){
                if(ansDig[k] == expDig[k]){
                    bulls++;
                } else if(count(ansDig.begin(), ansDig.end(), expDig[k])){
                    cows++;
                }
            }
            satisfiesAll &= (bulls == b[j] && cows == c[j]);
        }
        
        if(satisfiesAll){
            ans = ansDig;
            cnt++;
        }
    }

    //If no answers found in the end, then incorrect data
    if(!cnt){
        printf("Incorrect data\n");
    } else if(cnt > 1){
        printf("Need more data");
    } else {
        for(int i = 3; i>=0; i--){
            printf("%d", ans[i]);
        }
        printf("\n");
    }

    //If satisifies one then sufficient
    //If satisifies more than one then not enough info
    //Else incorrect
}
int main(){ 
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d%d%d", a + i, b + i, c + i);
    }

    solve();
}