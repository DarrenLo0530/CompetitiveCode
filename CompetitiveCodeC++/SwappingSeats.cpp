#include <bits/stdc++.h>
using namespace std;
#define mx 1000001
#define INF 0x3f3f3f3f

char temp[2*mx];
int PSA[2*mx];
int PSB[2*mx];
int PSC[2*mx];
int numA, numB, numC;
string word;
int main(){
    cin>>word;
    int l = word.length();

    for(int i = 0; i < l; i++){
        temp[i] = word[i];
        temp[i+l] = word[i];
    }


    for(int i = 1; i<=2*l; i++){
        PSA[i] = PSA[i-1];
        PSB[i] = PSB[i-1];
        PSC[i] = PSC[i-1];

        if(temp[i-1] == 'A'){
            PSA[i]++;
        } else if(temp[i-1] == 'B'){
            PSB[i]++;
        } else if(temp[i-1] == 'C'){
            PSC[i]++;
        }
    }

    numA = PSA[l];
    numB = PSB[l];
    numC = PSC[l];


    int ans = INF;
    int newAns1, newAns2;

    for(int i = 1; i<=l; i++){
        int endA = i + numA - 1;


        //Num required to swap out in A block
        int notA = PSB[endA] - PSB[i-1] + PSC[endA] - PSC[i-1];

        int endB = endA + numB;
        //Block B
        int notB = PSA[endB] - PSA[endA] + PSC[endB] - PSC[endA];
        
        int numBA = PSB[endA] - PSB[i-1];
        int numAB = PSA[endB] - PSA[endA];

        newAns1 = notA + notB - min(numBA, numAB);

        //Block C
        int endC = endA + numC;
        int notC = PSA[endC] - PSA[endA] + PSB[endC] - PSB[endA];

        int numCA = PSC[endA] - PSC[i-1];
        int numAC = PSA[endC] - PSA[endA];

        newAns2 = notA + notC - min(numCA, numAC);

        ans = min(newAns2, min(ans, newAns1));
    }

    cout<<ans;

    
}