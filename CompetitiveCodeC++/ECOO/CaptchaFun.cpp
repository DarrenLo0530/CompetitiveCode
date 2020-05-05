#include <bits/stdc++.h>
using namespace std;

char captcha[502][502];
bool top, bottom, tl, tr, bl,  br,  m;
int t, l, r, d;
int main(){
    int T;
    cin>>T;
    
    for(int i = 0; i<T; i++){
        int N, H, W;
        string ans = "";
        cin>>N;
        for(int j = 0; j<N; j++){
            top = bottom = tl = tr = bl = br = m = 0;
            cin>>H>>W;

            for(int h = 0; h<H; h++){
                for(int w = 0; w<W; w++){
                    cin>>captcha[h][w];
                }
            }

            bool found = false;

            for(int h =0; h<H; h++){
                for(int w = 1; w<W; w++){
                    if(captcha[h][w] != captcha[h][w-1]){
                        d = h;
                    }
                }
            }

            for(int h =H-1 ; h>=0; h--){
                for(int w = 1; w<W; w++){
                    if(captcha[h][w] != captcha[h][w-1]){
                        t = h;
                        break;
                    }
                }
            }

            for(int w = 0 ; w<W; w++){
                for(int h = 1; h<H; h++){
                    if(captcha[h][w] != captcha[h-1][w]){
                        r = w;
                        break;
                    }
                }
            }

            for(int w = W-1; w>=0; w--){
                for(int h = 1; h<H; h++){
                    if(captcha[h][w] != captcha[h-1][w]){
                        l = w;
                        break;
                    }
                }
            }

            for(int q = l + 1; q<r; q++){
                if(captcha[t][q] == '*'){
                    top = true;
                }

                if(captcha[d][q] == '*'){
                    bottom = true;
                }

                if(captcha[(d+t)/2][q] == '*'){
                    m = true;
                }
            }




            for(int x = t+1; x<((d+t)/2); x++){
                if(captcha[x][l] == '*'){
                    tl = true;
                }
                if(captcha[x][r] == '*'){
                    tr = true;
                }
            }

            for(int x = ((d+t)/2 + 1); x<d; x++){
                if(captcha[x][l] == '*'){
                    bl = true;
                }
                if(captcha[x][r] == '*'){
                    br = true;
                }
            }


            if(r == l){
                ans += '1';
            } else if(top && bottom && tr && tl && bl && br && !m){
                ans += '0';
            } else if(tr && br && !m && !top && !bottom && !tl && !bl){
                ans += '1';
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
            } else {
                ans += '9';
            }
        }


        cout<<ans<<'\n';
    }
}