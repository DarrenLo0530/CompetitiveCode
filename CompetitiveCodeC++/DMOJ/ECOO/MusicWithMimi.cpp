#include <bits/stdc++.h>
using namespace std;

string notes[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
string fourNotes[4];
int idx[8];

int T;
int main(){
    cin >> T;

    for(int t = 0; t<T; t++){
        for(int i = 0; i<4; i++){
            cin>>fourNotes[i];
        }

        bool isDominant = false;
        
        for(int i = 0; i<4; i++){
            for(int f= 0; f<12; f++){
                if(notes[f] == fourNotes[i]){
                    idx[i] = f;
                    idx[i + 4] = f;
                    break;
                }
            }
        }

        for(int i = 0; i<4; i++){
            if(((idx[i] + 4) % 12 == idx[i + 1]) && ((idx[i + 1] + 3) % 12 == idx[i + 2]) && ((idx[i + 2] + 3) % 12 == idx[i + 3])){
                isDominant = true;
                if(i == 0){
                    cout<<"root"<<"\n";
                } else if(i == 3){
                    cout<<"first"<<"\n";
                } else if(i == 2){
                    cout<<"second"<<"\n";
                } else { 
                    cout<<"third"<<'\n';
                }
            }
        }

        if(!isDominant){
            cout<<"invalid"<<'\n';
        }

    }
}