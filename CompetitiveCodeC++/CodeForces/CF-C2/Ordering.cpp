#include <bits/stdc++.h>
using namespace std;
vector<int> adj[26];
int indegree[26], v[26];
int numNodes = 0;
vector<string> answers;

void genAns(int cnt, string ans, vector<int> toVisit){
    if(cnt == numNodes){
        answers.push_back(ans);
    }

    for(int i : toVisit){
        string copy = ans;
        vector<int> toVisitCopy = toVisit;
        toVisitCopy.erase(find(toVisitCopy.begin(), toVisitCopy.end(), i));

        copy += 'A' + i;
        for(int n: adj[i]){
            if(!--indegree[n] && !v[n]){
                toVisitCopy.push_back(n);
            }
        }
        v[i] = true;
        genAns(cnt + 1, copy, toVisitCopy);
        v[i] = false;
        for(int n: adj[i]){
            indegree[n]++;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    cin.ignore(1000, '\n');
    for(int testCase = 0; testCase < t; testCase++){
        answers.clear();
        for(int i = 0; i<26; i++){
            adj[i].clear();
            v[i] = 0;
            indegree[i] = -1;
        }

        numNodes = 0;
        string letters, edges, edge;
        getline(cin, letters);
        getline(cin, letters);
        getline(cin, edges);
        stringstream split(edges), letterSplit(letters);
        char c;

        while(letterSplit >> c){
            indegree[c - 'A'] = 0;
            numNodes++;
        }
        while(split >> edge){
            if(edge[1] == '>'){
                swap(edge[2], edge[0]);
            }
            //Left side is smaller and is the parent node;
            //Then we always print children nodes before parent nodes by topological sort using vector/queue instead of a stack AKA parents get pushed after children
            adj[edge[0] - 'A'].push_back(edge[2] - 'A');
            indegree[edge[2] - 'A']++;
        }

        vector<int> toVisit;
        for(int i = 0; i<26; i++){
            if(indegree[i] == 0){
                v[i] = true;
                toVisit.push_back(i);
            }
        }
        
        genAns(0, "", toVisit);

        if(testCase != 0){
            printf("\n");
        }
        if(answers.size() == 0){
            printf("NO\n");
        } else {
            sort(answers.begin(), answers.end());
            for(int i = 0; i < answers.size(); i++){
                for(int c = 0; c<answers[i].size(); c++){
                    if(c != 0){
                        printf(" ");
                    }
                    printf("%c", answers[i][c]);
                }
                printf("\n");
            }
        }
    }
}
