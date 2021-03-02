#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int n;
string s;

char fi = 'b';
char se = 'r';

int solve(){
    int fc = 0, sc = 0;
    for(int i = 0; i<n; i+=2){
        if(s[i] == se){
            sc++;
        }
    }
    
    for(int i = 1; i<n; i+=2){
        if(s[i] == fi){
            fc++;
        }
    }

    //Lets say that there are fc cockroachs of the first colour that are in the wrong position
    //sc cockraoches of second colour in wrong position

    //If you swap min(fc, sc) times between the two out of place cockroaches, it is guranteed that the places of one colour will all be filled by right cockroach
    //Now for the other colour, there will be max(fc, sc) - min(fc, sc) cockroaches that are still in the wrong spot
    //These cockroaches need to change colour
    //So ans is min(fc, sc) + max(fc, sc) - min(fc, sc) = max(fc, sc)
    return max(fc, sc);
}

int main(){
    cin >> n >> s;
    int ans = solve();
    swap(fi, se);
    ans = min(ans, solve());
    printf("%d\n", ans);

}