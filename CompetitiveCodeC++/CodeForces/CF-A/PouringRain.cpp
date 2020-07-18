#include <bits/stdc++.h>
using namespace std;
const double PI = 2*acos(0.0);


int main(){
    double d, h, v, e;
    scanf("%lf%lf%lf%lf", &d, &h, &v, &e);   

    double r = d/2;
    double rateOfChange = (PI*pow(r, 2)*e - v);
    if(rateOfChange >= 0){
        printf("NO\n");
    } else {
        printf("YES\n");
        double initialVolume = PI*pow(r, 2)*h;
        double time = abs(initialVolume/rateOfChange);
        printf("%.12f\n", time);
    }
}