#include <bits/stdc++.h>
using namespace std;
int units[8];
int pats[8];

#define ON 0
#define OP 1  
#define AN 2
#define AP 3
#define BN 4
#define BP 5
#define ABN 6
#define ABP 7

int ans = 0;

void updateBloodType(int bloodType, int patientType){
    int old = ans;
    if(units[bloodType] >= pats[patientType]){
        units[bloodType] -= pats[patientType];
        ans += pats[patientType];
        pats[patientType] = 0;
    } else {
        pats[patientType] -= units[bloodType];
        ans += units[bloodType];
        units[bloodType] = 0;
    }
    /*if(ans - old != 0){
        cout<<ans-old<<","<<bloodType<<","<<patientType<<"\n";
    }*/
}

void normUpdate(int nb, int nh){
    updateBloodType(nb, nh);
    updateBloodType(nb+1, nh+1);
    updateBloodType(nb, nh+1);
}

int main(){
    for(int i = 0; i<8; i++){
        scanf("%d", &units[i]);
    }

    for(int i = 0; i<8; i++){
        scanf("%d", &pats[i]);
    }

    normUpdate(ON, ON);
    normUpdate(AN, AN);
    normUpdate(BN, BN);

    updateBloodType(OP, AP);
    updateBloodType(OP, BP);
    updateBloodType(ON, AN);
    updateBloodType(ON, BN);
    updateBloodType(ON, AP);
    updateBloodType(ON, BP);

    for(int i = 1; i<8; i+=2){
        updateBloodType(i, ABP);
    }

    for(int i = 0; i<8; i+=2){
        updateBloodType(i, ABN);
    }

    for(int i = 0; i<8; i+=2){
        updateBloodType(i, ABP);
    }

    cout<<ans<<"\n";
}