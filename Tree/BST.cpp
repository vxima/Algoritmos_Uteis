
#include <iostream>

using namespace std;
struct Node{
    int key;
    struct Node *left , *right;
};
struct Node *newNode(int value){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node *insert(struct Node* node , int value){
    if(node == NULL) return newNode(value);

    if(value < node->key){
        node->left = insert(node->left , value);
    }
    else if (value > node->key){
        node->right = insert(node->right , value);
    }
    return node ;
    
}
void preorder(struct Node *root){
    if(root != NULL){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void posorder(struct Node *root){
    if(root != NULL){
        posorder(root->left);
        posorder(root->right);
        cout << root->key << " ";
    }
}
int main()
{   
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    posorder(root);
    return 0;
}
