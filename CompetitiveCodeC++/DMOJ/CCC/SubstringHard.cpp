#include <bits/stdc++.h>
using namespace std;

int letterCount[65];
//order[] orders the letters lexicographically based using the indices they start at
int order[16][5001];
int eqCount[16][5001];
int invOrder[5001];
int lcp[5001];
int nCount[5001];

int getlcp(int startIndex, string s1, string s2){
    if(startIndex < 0){
        startIndex = 0;
    }  
    int counter = 0;
    for(int i = startIndex; i<min(s1.length(), s2.length()); i++){
        if(s1[i] == s2[i]){
            ++counter;
        } else {
            return counter;
        }
    }

    return counter;
}

int getNumericValue(char c){
    if(c >= '`' && c <= 'z')
        return c - '`';
    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 27;
    if(c >= '0' && c <= '9')
        return c - '0' + 53;
    
    return 0;
}

void solve(string s){
    s += '`';


    memset(lcp, -1, sizeof(lcp));
    memset(order, 0, sizeof(order));
    memset(letterCount, 0, sizeof(letterCount));
    memset(eqCount, 0, sizeof(eqCount));
    memset(invOrder, 0, sizeof(invOrder));
    memset(nCount, 0, sizeof(nCount));


    int mod = s.length();

    //TODO: Construct Suffix Array
    //Length of cyclic shift
    //Generate length and count of every 1 letter cyclic shift

    for(int i = 0; i<s.length(); i++){
        letterCount[getNumericValue(s[i])]++;
    }

    for(int i = 1; i<63; i++){
        letterCount[i] += letterCount[i-1];
    }

    //Stable
    for(int i = s.length()-1; i>=0; i--){
        order[0][letterCount[getNumericValue(s[i])] - 1] = i;
        letterCount[getNumericValue(s[i])]--;
    }

    for(int i = 1; i<s.length(); i++){
        eqCount[0][order[0][i]] = eqCount[0][order[0][i-1]];
        if(s[order[0][i]] != s[order[0][i-1]]){
            eqCount[0][order[0][i]]++;
        }
    }

    for(int i = 1; i<log2(s.length()) + 2; i++){ //i is length of half interval, 2i is length of new interval

        //Length of segment current iteration focuses
        int l = (1 << (i-1));
        fill(nCount, nCount + 5001, 0);

        //Count frequency of equivelance array
        for(int j = 0; j<s.length(); j++){
            nCount[eqCount[i-1][j]]++;
        }

        //SEtting up counting sort
        for(int j = 1; j<s.length(); j++){
            nCount[j] += nCount[j-1];
        }

        //Using the previous order as the base. Stable sort again using the l letters before the substring of length l at index order[j] of the original string    
        for(int j = s.length()-1; j>=0; j--){
            //The start of the section of l letters before the section of l letters previously ordered jth lexicographically
            int first = (order[i-1][j] - l + mod) % mod;
            //Stable sort the order again
            order[i][nCount[eqCount[i-1][first]] - 1] = first;
            nCount[eqCount[i-1][first]]--;
        }

        //Equality count again the new sorted array of partial cycles of length 2*l
        for(int j = 1; j<s.length(); j++){
            eqCount[i][order[i][j]] = eqCount[i][order[i][j-1]];
            if(eqCount[i-1][order[i][j]] != eqCount[i-1][order[i][j-1]] || eqCount[i-1][(order[i][j]+l) % mod] != eqCount[i-1][(order[i][j-1]+l) % mod]){
                eqCount[i][order[i][j]]++;
            }
        }
    }

    int h = log2(s.length()) + 1;

    for(int i = 0; i<s.length(); i++){
        invOrder[order[h][i]] = i;
        //invOrder[o] = the order that the substring starting at o is
    }   

    string s1 = s.substr(order[h][0]);
    string s2 = s.substr(order[h][1]);

    lcp[0] = getlcp(0, s1, s2);

    int nextStart = lcp[0] - 1;
    int curr = (order[h][0] + 1) % mod;


    
    while(lcp[invOrder[curr]] == -1){
        if(nextStart < 0){
            nextStart = 0;
        }
        lcp[invOrder[curr]] = getlcp(nextStart, s.substr(curr), s.substr(order[h][(invOrder[curr] + 1) % mod])) + nextStart;
        nextStart = lcp[invOrder[curr]] - 1;
        //Go to next in string
        curr += 1;
    }
    for(int i = 0; i<s.length(); i++){
        //cout<<s.substr(order[h][i])<<"\n";
    }

    int totalLcp = 0;

    for(int i = 0; i<s.length(); i++){
        //cout<<lcp[i]<<"\n";
        totalLcp += lcp[i];
    }

    int totalSubstrings = ((s.length() - 1) * s.length())/2;
    //cout<<totalLcp;
    int ans = totalSubstrings - totalLcp + 1;

    cout<<ans<<'\n';
}
int main(){ 
    int n;
    cin>>n;

    for(int i =0; i<n; i++){
        string s;
        cin>>s;
        solve(s);
    }
}

