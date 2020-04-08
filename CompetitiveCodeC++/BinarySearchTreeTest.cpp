#include <bits/stdc++.h>
using namespace std;
int N, M;
struct Node{
    int key = 0;
    Node* left = NULL;
    Node* right = NULL;
    int height = 1;
    int totalLeft = 0, totalRight = 0;
    int appearances = 1;
};

Node* root = NULL;

int getHeight(Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int getBalance(Node* node){
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotation(Node* z){//Returns new root
    Node* y = z->left;
    z->left = y->right;
    y->right = z;

    //Updating number of nodes on right and left
    z->totalLeft = y->totalRight;
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
    z->totalRight = y->totalLeft;

    y->totalLeft = z->appearances + z->totalRight + z->totalLeft;

    //Updating heights of subtrees    
    z->height = 1 + max(getHeight(z->right), getHeight(z->left));
    y->height = 1 + max(getHeight(y->right), getHeight(y->left));

    return y;
}

Node* insertUtil(Node* root, int val){//Returns pair of the root currently and if the inserted element was unique
    if(root == NULL){
        Node* n = new Node();
        n->key = val;
        return n;
        //Inserting node will not make same node imbalanced
    } else if(val > root->key){
        root->totalRight++;
        root->right = insertUtil(root->right, val);
    } else if(val < root->key){
        root->totalLeft++;
        root->left = insertUtil(root->left, val);
    } else {
        root->appearances++;
        return root;
    }

    int rightHeight = getHeight(root->right);
    int leftHeight = getHeight(root->left);
    root->height = 1 + max(rightHeight, leftHeight);

    int balanceFac = getBalance(root);
    if(balanceFac > 1 && val < root->left->key){//Val was inserted going left then left  (LL)
        return rightRotation(root);
    } else if(balanceFac < -1 && val > root->right->key){//Val was inserted going right then right (RR)
        return leftRotation(root);
    } else if(balanceFac > 1 && val > root->left->key){ //Val was inserted going left then right (LR)
        root->left = leftRotation(root->left);
        return rightRotation(root);
    } else if(balanceFac < -1 && val < root->right->key){//Val was inserted right then left (RL)
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void insert(int val){
    root = insertUtil(root, val);
}

Node* minNode(Node* root){
    if(root->left == NULL){
        return root;
    }

    return minNode(root->left);
}

bool wasDeleted;
Node* deleteUtil(Node* root, int val){//Returns pair of current node and whether or not the last node was deleted
    if(root == NULL){
        wasDeleted = false;
        return NULL;
    } else if(val > root->key){
        root->right = deleteUtil(root-> right, val);
        if(wasDeleted){
            root->totalRight--;
        }
    } else if(val < root->key){
        root->left = deleteUtil(root->left, val);
        if(wasDeleted){
            root->totalLeft--;
        }
    } else {
        wasDeleted = true;
        root->appearances--;
        if(root->appearances == 0){//Node actually deleted
            if(root->left == NULL && root->right == NULL){ //No child
                root = NULL;
                free(root);
            } else if (root->left != NULL && root->right == NULL){//Left child
                Node* temp = root->left;
                *root = *temp;
                free(temp);
            } else if (root->right != NULL && root->left == NULL){//Right child
                Node* temp = root->right;
                *root = *temp;
                free(temp);
            } else {//Two childs
                Node* inOrderSuccesor = minNode(root->right);
                root->key = inOrderSuccesor->key;
                root->appearances = inOrderSuccesor->appearances;
                root->totalRight -= inOrderSuccesor->appearances;

                inOrderSuccesor->appearances = 1;

                root->right = deleteUtil(root->right, inOrderSuccesor->key);
            }
        } else {
            return root;
        }
    }

    if(root == NULL){
        return NULL;
    }

    int rightHeight = getHeight(root->right);
    int leftHeight = getHeight(root->left);
    root->height = 1 + max(rightHeight, leftHeight);

    int balanceFac = getBalance(root);

    if(balanceFac > 1 && getBalance(root->left) >= 0){//Left left
        return rightRotation(root);
    } else if(balanceFac < -1 && getBalance(root->right) < 0){//Right right
        return leftRotation(root);
    } else if(balanceFac > 1 && getBalance(root->left) < 0){//Left right
        root->left = leftRotation(root->left);
        return rightRotation(root);
    } else if(balanceFac < -1 && getBalance(root->right)>=0){//Right left
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void del(int val){
    root = deleteUtil(root, val);
}

int nSmallest(Node* root, int n){
    if(n >= root->totalLeft + 1 && n<= root->totalLeft + root->appearances){
        return root->key;
    } else if(n > root->totalLeft + root->appearances){
        return nSmallest(root->right, n-(root->totalLeft+ root->appearances));
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

    for(int i = 0; i<root->appearances; i++){
        printf("%d ", root->key);
    }
    //printf("%d %d %d %d\n", root->key, root->appearances, root->totalLeft, root->totalRight);

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


    for(int i = 0; i<M; i++){
        scanf(" %c %d", &o, &a);
        a = a^prevAns;
        if(o == 'S'){
            prevAns = nSmallest(root, a);
            printf("%d\n", prevAns);
        } else if(o == 'I'){
            insert(a);
            //output(root);
        } else if(o == 'R'){
            del(a);
            //output(root);

        } else {
            prevAns = firstOccur(root, a, 1);
            printf("%d\n", prevAns);
        }
    }

    output(root);


}