    #include <bits/stdc++.h>
    using namespace std;

    #define INF 0x3f3f3f3f
    #define INFLL 0x3f3f3f3f3f3f3f3f
    #define PI 3.141592653589793

    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<double, double> pdd;

    const int MX = 5e5 + 10;

    int psa[3][MX];
    int cnt[3];


    int get(char cnt) {
        return cnt == 'L' ? 0 : cnt == 'M' ? 1 : 2;
    }

    int getCnt(char cnt, int l, int r) {
        return psa[get(cnt)][r] - psa[get(cnt)][l-1];
    }

    int main(){
        string s;
        cin >> s;
        for(int i = 1; i<=s.size(); i++) {
            cnt[get(s[i-1])]++;
            psa[get(s[i-1])][i]++;

            for(int j = 0; j<3; j++) {
                psa[j][i] += psa[j][i-1];
            }
        }

        int outtaPlace = 0;

        cnt[1] += cnt[0];
        cnt[2] += cnt[1];

        for(int i = 1; i<=s.size(); i++) {
            bool bad = false;
            if(s[i-1] == 'L') {
                bad = i > cnt[0];
            } else if(s[i-1] == 'M') {
                bad = i <= cnt[0] || i > cnt[1];
            } else {
                bad = i <= cnt[1] || i > cnt[2];
            }

            if(bad) {
                outtaPlace++;
            }
        }

        int mInFirst = getCnt('M', 1, cnt[get('L')]);
        int sInFirst = getCnt('S', 1, cnt[get('L')]);

        int lInSecond = getCnt('L', cnt[get('L')] + 1, cnt[get('M')]);
        int sInSecond = getCnt('S', cnt[get('L')] + 1, cnt[get('M')]);

        int lInThird = getCnt('L', cnt[get('M')] + 1, cnt[get('S')]);
        int mInThird = getCnt('M', cnt[get('M')] + 1, cnt[get('S')]);

        int oneSwaps = min(mInFirst, lInSecond) + min(sInFirst, lInThird) + min(sInSecond, mInThird);
        int twoSwaps = 2*(outtaPlace - oneSwaps*2)/3;
        printf("%d\n", oneSwaps + twoSwaps);
    }
