#include <bits/stdc++.h>
using namespace std;
int N, M;
struct Node{
    int key = 0;
    Node* left = NULL;
    Node* right = NULL;
    int height = 1;
    int uniqueLeft = 0, uniqueRight = 0, totalLeft = 0, totalRight = 0;
    int appearances = 1;
};

typedef pair<Node*, bool> nb;
Node* root = NULL;

int getHeight(Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

Node* rightRotation(Node* z){//Returns new root
    Node* y = z->left;
    z->left = y->right;
    y->right = z;

    //Updating number of nodes on right and left
    z->uniqueLeft = y->uniqueRight;
    z->totalLeft = y->totalRight;

    y->uniqueRight = 1 + z->uniqueLeft + z->uniqueRight;
    y->totalRight = z->appearances + z->totalLeft + z->totalRight;

    //Updating heights of subtrees
    z->height = 1 + max(getHeight(z->right), getHeight(z->left));
    y->height = 1 + max(getHeight(y->right), getHeight(y->left));

    return y;
}

Node* leftRotation(Node* z){//Returns new root
    Node* y = z->right;
    z->right = y->left;
    y->left = z;

    //Updating number of nodes on right and left
    z->uniqueRight = y->uniqueLeft;
    z->totalRight = y->totalLeft;

    y->uniqueLeft = 1 + z->uniqueRight + z->uniqueLeft;
    y->totalLeft = z->appearances + z->totalRight + z->totalLeft;

    //Updating heights of subtrees    
    z->height = 1 + max(getHeight(z->right), getHeight(z->left));
    y->height = 1 + max(getHeight(y->right), getHeight(y->left));

    return y;
}

bool find(Node* root, int val){
    if(root == NULL){
        return false;
    } else if(val > root->key){
        return find(root->right, val);
    } else if(val < root->key){
        return find(root->left, val);
    } else {
        return true;
    }
}

void insertExisting(Node* root, int val){
    if(val > root->key){
        root->totalRight++;
        insertExisting(root->right, val);
    } else if(val < root->key){
        root->totalLeft++;
        insertExisting(root->left, val);
    } else {
        root->appearances++;
        return;
    }
}

nb insertUnique(Node* root, int val){//Return curr root and true if insert was unique
    bool isUnique = false;

    if(root == NULL){
        Node* n = new Node();
        n->key = val;
        return nb{n, true};
        //Inserting node will not make same node imbalanced
    } else if(val > root->key){
        root->totalRight++;
        nb ret = insertUnique(root->right, val);
        root->right = ret.first;
        if(ret.second){
            root->uniqueRight++;
        }
        isUnique = ret.second;
    } else if(val < root->key){
        root->totalLeft++;
        nb ret = insertUnique(root->right, val);
        root->left = ret.first;
        if(ret.second){
            root->uniqueLeft++;
        }
        isUnique = ret.second;
    } else {
        root->appearances++;
        return nb{root, false};
    }

    int rightHeight = getHeight(root->right);
    int leftHeight = getHeight(root->left);
    root->height = 1 + max(rightHeight, leftHeight);

    int balanceFac = leftHeight - rightHeight;
    if(balanceFac > 1 && val < root->left->key){//Val was inserted going left then left  (LL)
        return nb{rightRotation(root), isUnique};
    } else if(balanceFac < -1 && val > root->right->key){//Val was inserted going right then right (RR)
        return nb{leftRotation(root), isUnique};
    } else if(balanceFac > 1 && val > root->left->key){ //Val was inserted going left then right (LR)
        root->left = leftRotation(root->left);
        return nb{rightRotation(root), isUnique};
    } else if(balanceFac < -1 && val < root->right->key){//Val was inserted right then left (RL)
        root->right = rightRotation(root->right);
        return nb{leftRotation(root), isUnique};
    }

    return nb{root, isUnique};
}

/*Node* deleteUnique(Node* root, int val){
    if(root == NULL){
        return NULL;
    } else if (val > root->key){
        deleteUnique(root->left, val);
    } else if (val < root->key){
        deleteUnique(root->right, val);
    } else {
        
    }

}*

void insert(int val){
    root = insertUnique(root, val).first;
}

int nSmallest(Node* root, int n){
    if(n == root->uniqueLeft + 1){
        return root->key;
    } else if(n > root->uniqueLeft + 1){
        return nSmallest(root->right, n-(root->uniqueLeft+1));
    } else {
        return nSmallest(root->left, n);
    }
}

int firstOccur(Node* root, int v, int numLessThan){
    if(root == NULL){
        return -1;
    }

    if(v > root->key){
        numLessThan += root->totalLeft + root->appearances;
        return firstOccur(root->right, v, numLessThan);
    } else if(v < root->key){
        return firstOccur(root->left, v, numLessThan);
    } else {
        numLessThan += root->totalLeft;
        return numLessThan;
    }
}

void output(Node* root){
    if(root->left != NULL){
        output(root->left);
    }

    //for(int i = 0; i<root->appearances; i++){
        printf("%d %d %d %d %d %d\n", root->key, root->appearances, root->totalLeft, root->totalRight, root->uniqueLeft, root->uniqueRight);
    //}

    if(root->right != NULL){
        output(root->right);
    }
}

int main(){  
    int N, M, a;
    char o;
    int prevAns = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i<N; i++){
        scanf("%d", &a);
        insert(a);
    }


    output(root);



}