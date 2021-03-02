#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main(){
    int n;
    scanf("%d", &n);
    int cnt = 0;
    vector<pair<int, string>> people;
    map<string, int> heights;
    for(int i = 0; i<n; i++){
        string s;
        int a;
        cin >> s >> a;
        people.push_back({a, s});
    }

    sort(people.begin(), people.end());
    
    vector<string> heightOrder;
    for(int i = 0; i<n; i++){
        if(people[i].first == 0){
            heightOrder.push_back(people[i].second);
        } else {
            int insertIdx = heightOrder.size() - people[i].first;
            if(insertIdx < 0){
                printf("-1\n");
                return 0;
            } else {
                heightOrder.insert(heightOrder.begin() + insertIdx, people[i].second);
            }
        }
    }

    for(int i = 0; i<n; i++){
        heights[heightOrder[i]] = i+1;
    }

    for(int i = 0; i<n; i++){
        cout << people[i].second << " " << heights[people[i].second] << '\n';
    }
}