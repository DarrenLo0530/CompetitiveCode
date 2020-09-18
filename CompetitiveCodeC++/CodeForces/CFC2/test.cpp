#include <bits/stdc++.h>
using namespace std;
int f(int x){
    return x + (1<<31)-2;
}
int main(){
    int a = 5;
    cout<<f(f(a));
}