#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int aLeave[1450] = {0};
        int bLeave[1450] = {0};

        int aArrival[1450] = {0};
        int bArrival[1450] = {0};

        int t;
        scanf("%d", &t);

        int na, nb;
        scanf("%d%d", &na, &nb);
        int trainsA = 0;
        int trainsB = 0;

        int trainsStartA = 0;
        int trainsStartB = 0;

        for(int i = 0; i<na; i++){
            string s;
            cin>>s;

            int hour = stoi(s.substr(0, 2));
            int mins = stoi(s.substr(3));
            aLeave[hour*60 + mins]++;

            cin>>s;
            hour = stoi(s.substr(0, 2));
            mins = stoi(s.substr(3)) + t;
            if(hour*60 + mins < 1440){
                bArrival[hour*60 + mins]++;
            }
        }

        for(int i = 0; i<nb; i++){
            string s;
            cin>>s;

            int hour = stoi(s.substr(0, 2));
            int mins = stoi(s.substr(3));
            bLeave[hour*60 + mins]++;

            cin>>s;
            hour = stoi(s.substr(0, 2));
            mins = stoi(s.substr(3)) + t;
            if(hour*60 + mins < 1440){
                aArrival[hour*60 + mins]++;
            }
        }

        for(int h = 0; h<1440; h++){
            trainsA += aArrival[h];
            trainsB += bArrival[h];

            if(aLeave[h] > trainsA){
                trainsStartA += aLeave[h] - trainsA;
                trainsA = 0;
            } else {
                trainsA -= aLeave[h];
            }
            if(bLeave[h] > trainsB){
                trainsStartB += bLeave[h] - trainsB;
                trainsB = 0;
            } else {
                trainsB -= bLeave[h];
            }
        }

        printf("Case #%d: %d %d\n", i, trainsStartA, trainsStartB);
    }

}