#include <bits/stdc++.h>
using namespace std;

bool isTriangle(int s1, int s2, int s3){
    return s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1;
}

vector<int> sides;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int s;
        scanf("%d", &s);
        sides.push_back(s);
    }

    sort(sides.begin(), sides.end());
    for(int i = 2; i<sides.size(); i++){
        if(isTriangle(sides[i], sides[i-1], sides[i-2])){
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
}