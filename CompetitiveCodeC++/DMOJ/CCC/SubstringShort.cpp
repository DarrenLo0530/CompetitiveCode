#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    while(n--){
        string s;
        vector<string> sv;
        cin>>s;
        s+='$';


        for(int i = 0; i<s.length(); i++){
            sv.push_back(s.substr(i));
        }

        sort(sv.begin(), sv.end());

        int lcp = 0;

        for(int i = 0; i<s.length()-1; i++){
            int currLcp = 0;
            while(sv[i][currLcp] == sv[i+1][currLcp]){
                currLcp++;
            }
            lcp+=currLcp;
        }

        int ans = (s.length() - 1) * s.length()/2 - lcp + 1;
        cout<<ans<<'\n';
    }
}