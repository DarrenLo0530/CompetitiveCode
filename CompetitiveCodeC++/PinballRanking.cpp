#include <bits/stdc++.h>
using namespace std;

int numBefore;
double avg = 0;

struct Node{
    int key = 0;
    Node* left = NULL;
    Node* right = NULL;
    int toLeft = 0, toRight = 0, appearances = 1, height = 1;
};

int getHeight(Node* curr){
    if(curr == NULL){
        return 0;
    }

    return curr->height;
}

Node* right(Node* z){
    Node* y = z->left;
    Node* T3 = y->right;

    z->left = T3;
    y->right = z;

    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    y->height = 1 + max(getHeight(y->right), getHeight(y->left));

    z->toLeft = y->toRight;
    y->toRight = z->appearances + z->toRight + z->toLeft;

    return y;
}

Node* left(Node* z){
    Node* y = z->right;
    Node* T2 = y->left;

    z->right = T2;
    y->left = z;

    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    y->height = 1 + max(getHeight(y->right), getHeight(y->left));

    z->toRight = y->toLeft;
    y->toLeft = z->appearances + z->toLeft + z->toRight;

    return y;
}

Node* insert(Node* root, int key){
    if(root == NULL){
        Node* n = new Node();
        n->key = key;
        return n;
    } else if (key < root->key){
        numBefore += root->toRight + root->appearances;
        root->toLeft++;
        root->left = insert(root->left, key);
    } else if(key > root->key){
        root->toRight++;
        root->right = insert(root->right, key);
    } else {
        numBefore+=root->toRight;
        root->appearances++;
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    int balFac = getHeight(root->left) - getHeight(root->right);

    if(balFac > 1 && key < root->left->key){//Left left
        return right(root);
    } else if(balFac < -1 && key > root->right->key){//Right right
        return left(root);
    } else if (balFac > 1 && key > root->left->key){//Left right
        root->left = left(root->left);
        return right(root);
    } else if(balFac < -1 && key < root->right->key){//Right left
        root->right = right(root->right);
        return left(root);
    }
    return root;
}
/*
void output(Node* root){
    if(root != NULL){
        if(root->left != NULL){
            output(root->left);
        }    

        printf("%d %d\n", root->key, root->appearances);

        if(root->right != NULL){
            output(root->right);
        }
    }
}
*/


int main(){
    int N, a;
    Node* root = NULL;
    
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &a);
        numBefore = 0;
        root = insert(root, a);
        avg += numBefore+1;
        //cout<<numBefore+1<<"\n";
        //output(root);
    }

    double ans = avg/(double)N;
    printf("%.2f", ans);
}