#include <bits/stdc++.h>
using namespace std;



struct Node{
    vector<pair<Node*, char>> connections;
};


void addString(Node* root, string str, int idx){
    if(idx >= str.length()){
        return;
    }

    for(auto i: root->connections){
        if(i.second == str[idx]){
            addString(i.first, str, idx+1);
            return;
        }
    }

    Node* next = new Node();
    root->connections.push_back(make_pair(next, str[idx]));
    addString(next, str, idx+1);
    
}

void print(Node* root){
    for(auto i: root->connections){
        cout<<i.second;
        print(i.first);
    }
}

int getSub(Node* root){
    int ret = 1;
    for(auto i: root->connections){
        if(i.second != '$'){
            ret += getSub(i.first);
        }
    }

    free(root);
    return ret;
}

int main(){

    int N;
    string s;
    scanf("%d", &N);

    for(int i = 0; i<N; i++){
        Node* root = new Node();
        cin>>s;
        s += '$';
        for(int i = 0; i<s.length(); i++){
            addString(root, s.substr(i), 0);
        }

        cout<<getSub(root)<<'\n';
    }
}