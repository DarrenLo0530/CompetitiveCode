#include <bits/stdc++.h>
using namespace std;
const int g = 34943;
string digits = "0123456789ABCDEF";

string toHex(int num){
    string ret = "";
    for(int i = 0; i < 4; i++){
        int dig = num % 16;
        ret = digits[dig] + ret;
        num /= 16;
    }

    return ret;
}

int main(){
    string s;
    while(getline(cin, s)){
        if(s == "#"){
            break;
        }
        int ans = 0;
        int power = pow(2, 16);
        power %= g;


        for(int i = s.size()-1; i>=0; i--){
            int num = (int) s[i];
            for(int j = 0; j<8; j++){
    
                if((1 << j) & num){

                    ans = (ans + power) % g;
                }
                power = (power * 2) % g;

            }
        }

        string hexAns = toHex((g - ans) % g);
        cout<<hexAns.substr(0, 2)<<" "<<hexAns.substr(2)<<'\n';
    }
}