#include <bits/stdc++.h>
using namespace std;
#define NINF -0x3f3f3f3f

struct Group{
    int c, p, i;
    bool operator < (const Group &g2) const {
        return p > g2.p;
    }
};

set<pair<int, int>> tables;

vector<Group> people;
int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int c, p;
        scanf("%d%d",&c,&p);
        people.push_back(Group{c, p, i});
    }

    sort(people.begin(), people.end());

    int m = 0, s = 0;
    int k;
    scanf("%d", &k);

    for(int i = 1; i<=k; i++){
        int r;
        scanf("%d", &r);
        tables.insert({r, i});
    }

    vector<int> acceptedRequests;
    vector<int> usedTable;
    for(int i = 0; i<people.size(); i++){
        Group group = people[i];
        auto table = tables.lower_bound({group.c, NINF});
        if(table != tables.end()){
            m++;
            s+=group.p;
            acceptedRequests.push_back(group.i);
            usedTable.push_back(table -> second);
            tables.erase(table);
        }
    }

    printf("%d %d\n", m, s);
    for(int i = 0; i<acceptedRequests.size(); i++){
        printf("%d %d\n", acceptedRequests[i], usedTable[i]);
    }
}