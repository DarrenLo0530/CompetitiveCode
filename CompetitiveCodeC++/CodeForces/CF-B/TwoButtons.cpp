    #include <bits/stdc++.h>
    using namespace std;

    int minSteps[20002];
    int main(){
        int n, m;
        scanf("%d%d", &n, &m);
        

        memset(minSteps, -1, sizeof(minSteps));
        queue<int> toUse;
        toUse.push(n);
        minSteps[n] = 0;

        while(minSteps[m] == -1){
            int curr = toUse.front();
            toUse.pop();
            if(curr*2 < 20001 && minSteps[curr * 2] == -1){
                toUse.push(curr * 2);
                minSteps[curr * 2] = minSteps[curr] + 1;
            }

            if(curr-1 >= 0 && minSteps[curr -1] == -1){
                toUse.push(curr - 1);
                minSteps[curr-1] = minSteps[curr] + 1;
            }
        }

        printf("%d\n", minSteps[m]);
    }

