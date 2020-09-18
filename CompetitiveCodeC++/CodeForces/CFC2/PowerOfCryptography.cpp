#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string multiplication(string first, string second){
    int ans[300] = {0};
    for(int i = 0; i<second.size(); i++){
        for(int j = 0; j<first.size(); j++){
            ans[j + i] += (first[j] - '0') * (second[i] - '0');
        }
    }

    for(int i = 0; i<300; i++){
        ans[i+1] += ans[i]/10;
        ans[i] = ans[i] % 10;
    }

    string ret = "";
    for(int i = 299; i>=0; i--){
        if(ret == "" && ans[i] == 0){
            continue;
        } else {
            ret += '0' + ans[i];
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string fastExponentiation(string curr, int expo){
    string multiplier = curr;
    string ans = "1";
    while(expo > 0){
        if(expo % 2 != 0){
            ans = multiplication(ans, multiplier);
        }
        multiplier = multiplication(multiplier, multiplier);
        expo/=2;
    }
    return ans;
}

bool larger(string a, string b){
    if(a.size() == b.size()){
        for(int i = a.size()-1; i>=0; i--){
            if(a[i] != b[i]){
                return (a[i] - '0') > (b[i] - '0');
            }
        }
    } 
    return a.size() > b.size();
}

int main(){
    int a;
    string b;  
    while(cin >> a >> b ){
        reverse(b.begin(), b.end());
        int l = 1, r = 1e9;
        while(l <= r){
            int mid = (l + r + 1)/2;
            stringstream ss;
            ss << mid;
            string sMid;
            ss >> sMid;
            reverse(sMid.begin(), sMid.end());
            string ans = fastExponentiation(sMid, a);
            //cout<<l<<" "<<r<<" "<<ans<<'\n';

            if(ans == b){
                cout<<mid<<'\n';
                break;
            } else if(larger(b, ans)){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
    }
}