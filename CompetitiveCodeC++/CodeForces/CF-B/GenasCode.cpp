#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int totalZeroes = 0;
    string nonb = "1";
    bool isZero = false;

    for(int i = 0; i<n; i++){
        string x;
        cin >> x;

        int numberOfZeroes = count(x.begin(), x.end(), '0');
        int numberOfOnes = count(x.begin(), x.end(), '1');

        bool wasnonb = false;

        for(int j = 2; j<=9; j++){
            if(count(x.begin(), x.end(), j + '0')){
                nonb = x;
                wasnonb= true;
            }
        }

        if(count(x.begin(), x.end(), '1') > 1){
            nonb = x;
            wasnonb= true;
        }

        if(wasnonb){
            continue;
        }

        if(numberOfZeroes == 1 && numberOfOnes == 0){
            isZero = true;
        }

        totalZeroes += numberOfZeroes;

    }

    if(isZero){
        cout<<"0\n";
    } else {
        cout<<nonb;
        for(int i = 0; i<totalZeroes; i++){
            cout<<"0";
        }

        cout<<'\n';
    }


    
}