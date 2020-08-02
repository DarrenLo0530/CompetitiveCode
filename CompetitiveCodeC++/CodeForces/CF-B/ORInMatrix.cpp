    #include <bits/stdc++.h>
    using namespace std;

    int grid[101][101];
    int ans[101][101];

    bool rowFilled[101];
    bool colFilled[101];

    bool hascol = false, hasrow = false;

    int main(){
        int m, n;
        scanf("%d%d", &m, &n);

        memset(colFilled, true, sizeof(colFilled));
        memset(rowFilled, true, sizeof(rowFilled));

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                scanf("%d", &grid[i][j]);
                if(grid[i][j] != 1){
                    rowFilled[i] = false;
                }
            }
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(grid[j][i] != 1){
                    colFilled[i] = false;
                }
            }
        }

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(grid[i][j] && !(rowFilled[i] || colFilled[j])){
                    cout<<"NO\n";
                    return 0;
                }
            }
        }


        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(colFilled[j] && rowFilled[i]){
                    ans[i][j] = 1;
                }
                if(colFilled[j]){
                    hascol = true;
                }

                if(rowFilled[i]){
                    hasrow = true;
                }
            }
        }

        if(hasrow && !hascol || hascol && !hasrow){
            cout<<"NO\n";
            return 0;
        }

        cout<<"YES\n";

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(j != 1){
                    cout<<" ";
                }
                cout<<ans[i][j];
            }

            cout<<'\n';
        }

    }