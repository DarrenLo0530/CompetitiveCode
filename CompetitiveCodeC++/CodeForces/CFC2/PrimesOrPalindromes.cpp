#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MX 20000000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

bool isPrime[MX+1];
vector<int> palindromes;
vector<int> primes;
void generatePalindromes(string prev){
    if(prev.size() < 4){
        for(char i = prev.size() == 0 ? '1' : '0'; i<='9'; i++){
            generatePalindromes(prev + i);
        }
    }

    if(prev.size() != 0){   
        string copy = prev.substr(0, prev.size() - 1);
        reverse(copy.begin(), copy.end());
        palindromes.push_back(stoi(prev + copy));
        string copy2 = prev;
        reverse(copy2.begin(), copy2.end());
        palindromes.push_back(stoi(prev + copy2));
    }
}
int main(){
    int p, q;
    scanf("%d%d", &p, &q);
    generatePalindromes("");
    sort(palindromes.begin(), palindromes.end());

    memset(isPrime, true, sizeof(isPrime));
    for(ll i = 2; i<=MX; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j = i*i; j<=MX; j+=i){
                isPrime[j] = false;
            }
        }
    }

    int ans = -1;
    int np = -1;
    for(int i = 0; i<palindromes.size(); i++){
        int numPrimes = --upper_bound(primes.begin(), primes.end(), palindromes[i]) - primes.begin() + 1;
        int numPalindromes = i+1;
        if((double) numPalindromes*p/q >= numPrimes){
            ans = palindromes[i];
            np = numPalindromes;
        }
    }

    if(ans == -1){
        printf("Palindromic tree is better than splay tree");
    } else {
        for(int i = ans; i<*upper_bound(palindromes.begin(), palindromes.end(), ans); i++){
            int numPrimes = --upper_bound(primes.begin(), primes.end(), i) - primes.begin() + 1;
            if((double) np*p/q >= numPrimes){
                ans = i;
            }
        }
        printf("%d\n", ans);
    }

}