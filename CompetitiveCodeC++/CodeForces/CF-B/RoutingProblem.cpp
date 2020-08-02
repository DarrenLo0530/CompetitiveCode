#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii subtract(pii p1, pii p2){
    int d = __gcd(p1.second, p2.second);
    int n1 = p1.first*p2.second/d;
    int n2 = p2.first*p1.second/d;

    return pii{n1 - n2, p2.second*p1.second/d};
}
pii reduce(pii p1){
    int d = __gcd(p1.first, p1.second);
    return {p1.first/d, p1.second/d};
}

pii divide(pii p1, pii p2){
    return reduce({p1.first*p2.second, p2.first*p1.second});
}

int main(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    if((double) a/b == (double) c/d){
        printf("0/1\n");
        return 0;
    } 
    
    if((double) a/b < (double) c/d){
        swap(a, b);
        swap(c, d);
    }
    pii screen = {a, b};
    pii video = {c, d};
    
    pii remaining = divide(subtract(screen, video), screen);
    printf("%d/%d\n", remaining.first, remaining.second);

}