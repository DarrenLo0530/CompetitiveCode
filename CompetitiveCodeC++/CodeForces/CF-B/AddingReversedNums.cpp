#include <bits/stdc++.h>
using namespace std;

string add(string a, string b){
    string ans = "";
    int index = 0;
    int carryOver = 0;
    while(index < a.size() && index < b.size()){
        int curr = a[index] - '0' + b[index] - '0' + carryOver;
        ans += '0' + curr % 10;
        carryOver = curr/10;
        index++;
    }

    while(index < a.size()){
        int curr = a[index] - '0' + carryOver;
        ans += '0' + curr % 10;
        carryOver = curr/10;
        index++;

    }

    while(index < b.size()){
        int curr = b[index] - '0' + carryOver;
        ans += '0' + curr % 10;
        carryOver = curr/10;
        index++;
    }

    ans += '0' + carryOver; 

    return ans;

}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        string a, b;
        cin >> a >> b;

        string ans = add(a, b);
        int start = 0;
        int end = ans.size() - 1;
        while(ans[end] == '0'){
            end--;
        }
        while(ans[start] == '0'){
            start++;
        }

        for(int i = start; i<=end; i++){
            cout << ans[i];
        }

        

        cout << '\n';
    }
}