#include <bits/stdc++.h>
using namespace std;


int main(){
    string chars = "qwertyuiopasdfghjklzxcvbnm";
    int n, t;
    scanf("%d%d", &n, &t);
    string a, b;
    cin >> a >> b;

    int numDiff = 0;
    for(int i = 0; i<n; i++){
        if(a[i] != b[i]){
            numDiff++;
        }
    }

    int maxRemainSame = numDiff/2 + (n - numDiff);
    if(t < n - maxRemainSame){
        //Too little number of letters that should differ
        cout<<-1<<'\n';
        return 0;
    }


    if(t >= numDiff){
        //Must also modify index where letters of a and b are same since not enough using just numDiff.
        //This is the number of indexes where letters of a and b that we have to make differ
        t -= numDiff;
        for(int i = 0; i<n; i++){
            if(a[i] == b[i]){
                if(t > 0){
                    for(char c: chars){
                        if(c != a[i] && c != b[i]){
                            cout<<c;
                            break;
                        }
                    }
                    t--;
                } else {
                    //We have gotten enough indexes where a and b are equal to differ already, so now we want them to remain the same
                    cout<<a[i];
                }
            } else {
                //Always make it differ from both the letters of a and b seeing as we already don't have enoguh using just these letter types, so maximize differs we can get.
                for(char c: chars){
                    if(c != a[i] && c != b[i]){
                        cout<<c;
                        break;
                    }
                }
            }   
        }
    } else {
        //We can get all the required differences by only modifying indexes where letter from a and b are different
        //Before we got 1 differ out of one index where letters of a and b were different
        //Places where letters a and b differ can never have a match for both
        //Since we dont want as many differs, we want to use more indexes up to get 1 differ.
        //We can pair up indexes where a and b differ. For first index we set it to the letter of a, then 2nd we set to letter of b.
        //That way we get one differs out of 2 index. This is done until number of indexes where a and b mismatch is equal to number of differs.
        //Then we can do the strategy from before where we choose a char that matches neither to get 1 differ out of 1 index again.
        int temp = (numDiff - t) * 2;
        for(int i = 0; i<n; i++){
            if(a[i] == b[i]){
                //Seeing as we can get all differs already out of the indexes where a and b mismatch, we dont want a differ where a and b are the same
                //So we want a match
                cout<<a[i];
            } else {
                if(temp > 0){
                    if(temp % 2 == 0){
                        cout<<a[i];
                    } else {
                        cout<<b[i];
                    }
                    temp--;                    
                } else {
                    for(char c: chars){
                        if(c != a[i] && c != b[i]){
                            cout<<c;
                            break;
                        }
                    }
                }
            }   
        }
        
    }

    
    
    

    cout<<'\n';
}