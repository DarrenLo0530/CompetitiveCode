#include <bits/stdc++.h>
using namespace std;
#define mx 100001

int ans[mx];
int mxNum;
bool isNeg1, isNeg2, ansNeg;
string temp1, temp2;
int num1[mx];
int num2[mx];

int getLargerNum(){
    for(int i = mxNum-1; i>=0; i--){
        if(num1[i] > num2[i]){
            return 1;
        } else if(num2[i] > num1[i]){
            return 2;
        }
    }

    return 0;
}

void addition(){

    for(int i = 0; i<mxNum; i++){
        int res = ans[i] + num1[i] + num2[i];
        ans[i] = res%10;
        ans[i+1] = res/10;
    }
}

void subtraction(){
    int largerNum = getLargerNum();
    if(largerNum == 1 && isNeg1){
        ansNeg = true;
    } else if(largerNum == 2 && isNeg2){
        ansNeg = true;
    }

    if(largerNum == 2){
        swap(num1, num2);
    }

    for(int i = 0; i<mxNum; i++){
        if(num1[i] < num2[i]){
            int f = i+1;
            while(true){
                if(num1[f] != 0){
                    num1[f]--;
                    break;
                }
                num1[f] += 9;
                f++;
            }
            num1[i] += 10;
        }
        ans[i] = num1[i] - num2[i];
    }
    
}

void print(){
    string print = "";
    for(int i = 0; i < mxNum+1; i++){
        print += '0' + ans[i];
    }


    reverse(print.begin(), print.end());
    int end = 0;
    while(true){
        if(print[end] != '0' || end == print.size() - 1){
            break;
        } 
        end++;
    }
    print.erase(0, end);

    if(ansNeg){
        cout<<'-';
    }
    cout<<print<<"\n";
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        ansNeg = isNeg1 = isNeg2 = false;
        memset(num1, 0 , sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(ans, 0, sizeof(ans));
        cin >> temp1 >> temp2;

        if(temp1[0] == '-'){
            isNeg1 = true;
            temp1.erase(0, 1);
        }
        if(temp2[0] == '-'){
            isNeg2 = true;
            temp2.erase(0, 1);
        }

        ansNeg = (isNeg1 && isNeg2) ? true: false;

        mxNum = max(temp1.size(), temp2.size());

        for(int i = temp1.size()-1; i>=0; i--){
            num1[temp1.size() - 1 - i] = temp1[i] - '0';
        }
        for(int i = temp2.size()-1; i>=0; i--){
            num2[temp2.size() - 1 - i] = temp2[i] - '0';
        }

        if(isNeg1 ^ isNeg2){
            subtraction();
        } else {
            addition();
        }
        print();
    }    
}