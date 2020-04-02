#include <bits/stdc++.h>
using namespace std;

int main(){
    double x1, y1, x2, y2, x3 ,y3, x4, y4, x, y;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    double A1 = y1-y2;
    double A2 = y3-y4;
    double B1 = x2-x1;
    double B2 = x4-x3;
    double C1 = (y2-y1)*x1 - (x2-x1)*y1;
    double C2= (y4-y3)*x3 - (x4-x3)*y3;

    if(A1*B2 == A2*B1){
        if(C1*B2 == C2*B1){
            cout<<"coincident";
        } else {
            cout<<"parallel";
        }
    } else {
        x =(C2*B1 - C1*B2)/(A1*B2-A2*B1);
        if(B1 != 0){
            y = -A1*x/B1 - (C1/B1); 
        } else {
            y = -A2*x/B2 - (C2/B2); 
        }
        printf("%.6f %.6f", x, y);
    }

}