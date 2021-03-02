#include <bits/stdc++.h>
using namespace std;

int lvlsUsed[500000];

int main(){
    int n;
    scanf("%d", &n);
    string exception, temp;
    string line;
    getline(cin, temp);
    int lvl = 0, throwLvl = -1;
    for(int i = 0; i<n; i++){
        getline(cin, line);
        string op = "";
        int ptr = 0;
        if(line.find_first_not_of(' ') == string::npos){
            continue;
        }
        while(ptr < line.size() && line[ptr] != '('){
            if(line[ptr] != ' '){
                op += line[ptr];
            }
            ptr++;
        }
        if(op == "try"){
            lvl++;
        } else if(op == "catch"){
            lvl--;
            if(throwLvl == -1 || lvl+1 > throwLvl){
                continue;
            }

            if(lvlsUsed[lvl+1]){
                continue;
            }
            lvlsUsed[lvl+1] = true;

            int l = ptr;
            int r = line.size()-1;
            while(line[l] == '(' || line[l] == ' '){
                l++;
            }

            string caughtException = "";
            string message = "";
            while(line[l] != ','){
                if(line[l] != ' '){
                    caughtException += line[l];
                }
                l++;
            }

            if(caughtException != exception){
                continue;
            }

            int quoteCnt = 0;
            while(quoteCnt != 2){
                if(line[l] == '"'){
                    quoteCnt++;
                } else if(quoteCnt == 1){
                    message += line[l];
                }
                l++;
            }
            cout<<message<<"\n";
            return 0;
        } else {
            throwLvl = lvl;
            int l = ptr;
            int r = line.size()-1;
            while(line[l] == '(' || line[l] == ' '){
                l++;
            }
            while(line[r] == ')' || line[r] == ' '){
                r--;
            }
            exception = line.substr(l, r-l+1);
        }
        
    }

    printf("Unhandled Exception\n");
}