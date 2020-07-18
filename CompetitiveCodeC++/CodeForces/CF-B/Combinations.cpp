#include <bits/stdc++.h>
using namespace std;

int pascal[101][101];

int main(){
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for(int row = 2; row <=100; row++){
        pascal[row][0] = 1;
        pascal[row][row] = 1;
        for(int col = 1; col < row; col++){
            pascal[row][col] = pascal[row-1][col] + pascal[row-1][col-1];
        }
    }
    
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        cout<<n<<" things taken "<<m<<" at a time is "<<pascal[n][m]<<" exactly."<<endl;
    }
}
