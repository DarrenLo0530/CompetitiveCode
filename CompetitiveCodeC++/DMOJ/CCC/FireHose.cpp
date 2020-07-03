#include <bits/stdc++.h>
using namespace std;

int h;
int numHydrants;
vector<int> houses;

int getHydrantsNeeded(int hoseLength){
    int minHydrants = 0x3f3f3f3f;
    int hoseSpan = hoseLength * 2;

    for(int i = 0; i<h; i++){
        int neededHydrants = 1;
        int currentHouse = (i+1) % h;
        int hoseLeft = hoseSpan;

        while(currentHouse != i){
            int dist;
            if(currentHouse == 0){
                dist = 1000000 + houses[0] - houses[h-1];
            } else {
                dist = houses[currentHouse] - houses[currentHouse-1];
            }
            
            //cout<<dist<<'\n';

            if(dist > hoseLeft){
                hoseLeft = hoseSpan;
                neededHydrants++;
            } else {
                hoseLeft -= dist;
            }

            currentHouse = (currentHouse + 1) % h;
        }
        //cout<<neededHydrants<<'\n';

        minHydrants = min(minHydrants, neededHydrants);
    }

    return minHydrants;
}

int main(){
    scanf("%d", &h);
    for(int i = 0; i<h; i++){
        int x;
        scanf("%d", &x);
        houses.push_back(x);
    }

    scanf("%d", &numHydrants);
    sort(houses.begin(), houses.end());

    int maxLength = 1000000;
    int minLength = 0;

    while(maxLength > minLength){
        int mid = (maxLength + minLength)/2;
        int hydrantsNeeded = getHydrantsNeeded(mid);
        //cout<<mid<<'\n';
        if(hydrantsNeeded > numHydrants){
            minLength = mid + 1;
        } else {
            maxLength = mid;
        }
    }

    cout << minLength << '\n';
}