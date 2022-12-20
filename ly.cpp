#include <iostream>
using namespace std;
struct AVLNode{
    int key;
    AVLNode *pLeft;
    AVLNode *pRight;
    int height;
};

//create a node
AVLNode *createNode(int key){
    AVLNode *p = new AVLNode;
    if(p==nullptr){
        return nullptr;
    }
    p->key = key;
    p->pLeft = nullptr;
    p->pRight = nullptr;
    p->height = 1;
    return p;
}
//insert node
void insertNode(AVLNode *&root, int key){
    if(root == nullptr){
        AVLNode *p = createNode(key);
        root = p;
    }
    else{
        if(key < root->key){
            insertNode(root->pLeft, key);
        }
        else if(key > root->key){
            insertNode(root->pRight, key);
        }
    }
}
//create avltree from int array

AVLNode *createAVL(int* arr, int n){
    AVLNode *root = nullptr;
    for(int i=0; i<n; i++){
        insertNode(root, arr[i]);
    }
    return root;
}
bool removeNode(AVLNode* &root, int x){
    if(root == nullptr){
        return false;
    }
    else{
        if(x < root->key){
            removeNode(root->pLeft, x);
        }
        else if(x > root->key){
            removeNode(root->pRight, x);
        }
        else{
            AVLNode *p;
            if(root->pLeft == nullptr){
                p = root->pRight;
                delete root;
                root = p;
            }
            else if(root->pRight == nullptr){
                p = root->pLeft;
                delete root;
                root = p;
            }
            else{
                p = root->pRight;
                while(p->pLeft != nullptr){
                    p = p->pLeft;
                }
                root->key = p->key;
                removeNode(root->pRight, p->key);
            }
        }
    }
    return true;
}
// create a tree avl using the pointer

bool isAVL(AVLNode*root) {
  if (root == nullptr) {
    return true;
  }
  int leftHeight = 0;
  int rightHeight = 0;
  if (root->pLeft != nullptr) {
    leftHeight = root->pLeft->height;
  }
  if (root->pRight != nullptr) {
    rightHeight = root->pRight->height;
  }
  if (abs(leftHeight - rightHeight) > 1) {
    return false;
  }
  return isAVL(root->pLeft) && isAVL(root->pRight);
}

//print Node
void printNode(AVLNode *root){
    if(root != nullptr){
        cout << root->key << " ";
        printNode(root->pLeft);
        printNode(root->pRight);
    }
}
int main(){

    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(arr)/sizeof(int);
    AVLNode *root = createAVL(arr, n);
    
    removeNode(root,20);
    
    if(isAVL(root)){
        cout << "This is AVL tree" << endl;
    }
    else{
        cout << "This is not AVL tree" << endl;
    }
    return 0;
    printNode(root);
    
    
}