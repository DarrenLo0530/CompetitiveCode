#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    printf("INTERSECTING LINES OUTPUT\n");
    while(n--){
        double x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        double a1, a2, b1, b2, c1, c2;

        a1 = y2 - y1;
        b1 = x1 - x2;
        c1 = a1*x1 + b1*y1;

        a2 = y4 - y3;
        b2 = x3 - x4;
        c2 = a2*x3 + b2*y3;

        double deteriminant = a1*b2 - a2*b1;
        if(deteriminant == 0){
            double intercept1 = c1/(x1-x2);
            double intercept2 = c2/(x3-x4);
            if(intercept1 == intercept2){
                printf("LINE\n");
            } else {
                printf("NONE\n");
            }

        } else {
            double x = (b2*c1 - b1*c2)/deteriminant;
            double y = (a1*c2 - a2*c1)/deteriminant;
            if(x == 0){
                x = 0;
            } 
            if(y == 0){
                y = 0;
            }
            printf("POINT %.2f %.2f\n", x, y);
        }
    }

    printf("END OF OUTPUT\n");
}