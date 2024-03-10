#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

queue<node *> q;
node *root = NULL;

int inorder(node*root){
    if(root!=NULL){
        cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}

void perfectTreeBuild(int value){
    node *curr=new node();
    curr->data=value;
    curr->left=NULL;
    curr->right=NULL;

    if(root==NULL){
        root=curr;
        q.push(curr);
    }
    else{
        q.push(curr);
        node *fr = q.front();

        if(fr->left == NULL){
            fr->left = curr;
        }
        else if(fr->right == NULL){
           fr->right = curr;
           q.pop();
        }
    }
}

int main(){
    int x;
    for(int i=1; i<=7; i++){
        cin>>x;
        perfectTreeBuild(x);
    }

    inorder(root);
}