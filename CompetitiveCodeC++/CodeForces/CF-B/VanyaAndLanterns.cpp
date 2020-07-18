#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    scanf("%d%d", &n, &l);

    vector<double> lanterns;
    
    for(int i = 0; i<n; i++){
        double x;
        cin >> x;
        lanterns.push_back(x);
    }

    sort(lanterns.begin(), lanterns.end());

    double d = lanterns[0];
    for(int i = 0; i<lanterns.size()-1; i++){
        d = max(d, (lanterns[i+1] - lanterns[i])/2);
    }

    d = max(d, l - lanterns[lanterns.size() - 1]);
    printf("%.10f\n", d);   
}