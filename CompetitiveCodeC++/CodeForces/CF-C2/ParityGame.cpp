#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

string a, b;

bool solve(){
    int bOne = count(b.begin(), b.end(), '1');
    int maxOne = count(a.begin(), a.end(), '1');
    if(maxOne % 2 != 0){
        maxOne++;
    }

    return maxOne >= bOne;
}
int main(){

    //Odd # of 1's, add 1 to end
    //Even # of 1's, add 0 to end
    //Remove 1st 
    //Lets say u have only 1 one, then its doomed if u need
    //Max number of 1's is number of 1's rounded u p
    //Infinite number of 0's at end
    cin >> a >> b;
    if(solve()){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    

}