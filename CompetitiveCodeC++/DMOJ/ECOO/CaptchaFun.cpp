#include <bits/stdc++.h>
using namespace std;
char captcha[502][502];
int N, H, W;

bool rowHasAsteriks(int row){
    for(int i = 0; i<502; i++){
        if(captcha[row][i] == '*'){
            return true;
        }
    }

    return false;
}

bool columnHasAsterik(int column, int t, int b){
    if(column < 0 || t+1 < 0 || b > H){
        return false;
    }
    for(int i = t+1; i<b; i++){
        if(captcha[i][column] == '*'){
            return true;
        }
    }
    return false;
}

bool top, bottom, tl, tr, bl,  br,  m;
int t, l, r, d;
int main(){
    int T;
    cin>>T;
    
    for(int i = 0; i<T; i++){
        string ans = "";
        cin>>N;
        for(int j = 0; j<N; j++){
            memset(captcha, '-', sizeof(captcha));
            t = l = r = d = -1;
            top = bottom = tl = tr = bl = br = m = false;
            cin>>H>>W;


            for(int h = 0; h<H; h++){
                for(int w = 0; w<W; w++){
                    cin>>captcha[h][w];
                }
            }


            bool found = false;

            for(int w = W-1; w >= 0 && r == -1; w--){
                for(int h = 0; h<H; h++){
                    if(captcha[h][w] == '*'){
                        r = w;
                        break;
                    }
                }
            }

            for(int h = 0; h<H && t == -1; h++){
                if(rowHasAsteriks(h)){
                    t = h;
                    break;
                }
            }
            int firstRight = -1;
            int lastRight;

            for(int h = 0; h<H; h++){
                if(captcha[h][r] == '*'){
                    if(firstRight == -1){
                        firstRight = h;
                    }
                    lastRight = h;
                }
            }

            //Get mid 
            int midRow = -1;
            for(int h = 1; h<H; h++){
                if(captcha[h][r] == '-' && captcha[h-1][r] == '*' && captcha[h+1][r] == '*'){
                    midRow = h;
                }
            }



            int lenRight = 0;
            if(midRow == -1){
                if(t == firstRight - 1){
                    midRow = lastRight + 1;
                } else {
                    midRow = firstRight - 1;
                }
                lenRight = lastRight - firstRight + 1;
            } else {
                lenRight = lastRight - midRow;
            }

            m = rowHasAsteriks(midRow);

            int topRow = midRow - lenRight - 1;
            int bottomRow = midRow + lenRight + 1;

            if(topRow >= 0){
                top = rowHasAsteriks(topRow);
            }

            if(bottomRow < H){
                bottom = rowHasAsteriks(bottomRow);
            }

            if(!m && !bottom && !top){
                ans += '1';
                continue;
            }

            int existingRow;
            if(m){
                existingRow = midRow;
            } else if(top){
                existingRow = topRow;
            } else{
                existingRow = bottomRow;
            }

            int firstRowAsterik;
            for(int w = 0; w<W; w++){
                if(captcha[existingRow][w] == '*'){
                    firstRowAsterik = w;
                    break;
                }
            }

            int l = firstRowAsterik - 1;
            tr = columnHasAsterik(r, topRow, midRow);
            br = columnHasAsterik(r, midRow, bottomRow);
            tl = columnHasAsterik(l, topRow, midRow);
            bl = columnHasAsterik(l, midRow, bottomRow);

            if(top && bottom && tr && tl && bl && br && !m){
                ans += '0';
            } else if(top && !tl && tr && m && bl && !br && bottom){
                ans += '2';
            } else if(top && !tl && tr && m && !bl && br && bottom){
                ans += '3';
            } else if(!top && tl && tr && m && !bl && br && !bottom){
                ans += '4';
            } else if(top && tl && !tr && m && !bl && br && bottom){
                ans += '5';
            } else if(top && tl && !tr && m && bl && br && bottom){
                ans += '6';
            } else if(top && !tl && tr && !m && !bl && br && !bottom){
                ans += '7';
            } else if(top && tl && tr && m && bl && br && bottom){
                ans += '8';
            } else if(top && tl && tr && m && !bl && br && bottom){
                ans += '9';
            } else {
                ans += 'B';
            }
        }
        cout<<ans<<'\n';
    }
}