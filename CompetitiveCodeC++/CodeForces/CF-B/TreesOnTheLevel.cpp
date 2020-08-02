#include <bits/stdc++.h>
using namespace std;

struct NodePath{
    int value;
    string path;

    bool operator < (const NodePath &n1) const {
        if(path.size() == n1.path.size()){
            return path < n1.path;
        }

        return path.size() < n1.path.size();
    }
};

int main(){
    string s;
    while(cin >> s){
        set<string> used;
        vector<NodePath> nodes;
        vector<string> input;
        vector<string> paths;
        input.push_back(s);
        

        while(true){
            cin >> s;
            if(s == "()"){
                break;
            }

            input.push_back(s);
        }

        bool incomplete = false;
        int maxIdx = 0;
        for(string i: input){
            string removeParen = i.substr(1, i.size() - 2);
            int val = stoi(removeParen.substr(0, i.find(',')));
            string dir = "";
            if(removeParen.find(',') + 1 < removeParen.size()){
                dir = removeParen.substr(removeParen.find(',') + 1);
            }

            if(used.count(dir)){
                incomplete = true;
            }
            used.insert(dir);
            nodes.push_back(NodePath{val, dir});
            paths.push_back(dir);
        }

        for(string i: paths){
            if(!used.count(i.substr(0, i.size() -1))){
                incomplete = true;
            }
        }

        if(incomplete){
            printf("not complete\n");
        } else {
            sort(nodes.begin(), nodes.end());
            for(int i = 0; i<nodes.size(); i++){
                if(i != 0){
                    cout<< " ";
                }
                printf("%d", nodes[i].value);
            }
            cout<<'\n';

        }

        

    }

}