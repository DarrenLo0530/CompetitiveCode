    #include <bits/stdc++.h>
    using namespace std;

    vector<int> results;
    int main(){
        int n;

        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 

        cin >> n;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;   
            results.push_back(x);
        }

        int minRemoved = 0x3f3f3f3f;
        sort(results.begin(), results.end());
        for(int i = 0; i<n; i++){
            auto end = upper_bound(results.begin(), results.end(), results[i] * 2);
            int removedBack = results.end() - end;
            minRemoved = min(removedBack + i, minRemoved);
        }

        printf("%d\n", minRemoved);
    }