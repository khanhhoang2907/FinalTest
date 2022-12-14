#include <iostream>
#include <ctime>
using namespace std;
struct AVLNode{
    int key;
    AVLNode *pLeft;
    AVLNode *pRight;
    int height;
};

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
void printNode(AVLNode *root){
    if(root != nullptr){
        cout << root->key << " ";
        printNode(root->pLeft);
        printNode(root->pRight);
    }
}
int main(){
    srand(time(NULL));
    int n = 10;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = rand()%100;
        cout << arr[i] << " ";
    }
    AVLNode *root = createAVL(arr, n);
    cout<<endl;
    int x;
    cout<<"enter number remove: ";
    cin>>x;
    removeNode(root,x);
    if(isAVL(root)){
        cout << "This is AVL tree" << endl;
    }
    else{
        cout << "This is not AVL tree" << endl;
    }
    printNode(root);
    return 0;
    
}