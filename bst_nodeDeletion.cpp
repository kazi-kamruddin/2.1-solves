#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *root = NULL;
node *curr_node = NULL;
node *prev_node = NULL;

void BST_insert(int value){
    node *temp=new node();
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)
        root=temp;
    else{
      curr_node=root;
      prev_node=root;

      while(curr_node!=NULL){
          prev_node=curr_node;
          if(curr_node->data < value)
              curr_node=curr_node->right;
          else
              curr_node=curr_node->left;
      }

      if(prev_node->data < value)
          prev_node->right=temp;
      else
          prev_node->left=temp;
    }
}

void preOrder(node*root){
    if(root!=NULL){
      cout<<root->data<<" ";
      preOrder(root->left);
      preOrder(root->right);
    }
}

void deleteNode(int val){
  node *curr = root,*prev = root;

  while(curr != NULL){
    if(curr->data == val)
      break;

    prev = curr;
    if(val > curr->data)
      curr = curr->right;
    else
      curr = curr->left;
  }

  if(curr == NULL){
    return;
  }
  // leaf node
  else if(curr->left == NULL && curr->right == NULL){
    if(prev->right == curr)
      prev->right = NULL;
    else
      prev->left = NULL;
  }
  // ekta child
  else if(curr->left == NULL || curr->right == NULL){
    node *child = new node();

    if(curr->left == NULL)
      child = curr->right;
    else
      child = curr->left;

    if(prev == NULL){
      root = child;
    }
    else if(prev->right == curr){
      prev->right = child;
    }
    else{
      prev->left = child;
    }
  }
  //duita child
  else if (curr->left != NULL || curr->right != NULL){
     node *temp = curr;
     prev = curr;
     curr = curr->left;

     while(curr->right != NULL){
       prev = curr;
       curr = curr->right;
     }

     temp->data = curr->data;
     if(prev->left == curr){
       prev->left = curr->left;
     }
     else
       prev->right = curr->left;
  }
  else{
    cout << "bruh" << endl;
  }
}

int main(){
    int x,y;
    cout << "num of nodes: ";
    cin >> x;
    cout << endl << "insert " << x << " values in the tree: ";

    for(int i=1; i<=x; i++){
      cin>>y;
      BST_insert(y);
    }

    cout << endl << "pre order before deletion: ";
    preOrder(root);

    deleteNode(75);

    cout << endl << endl << "pre order after deletion: ";
    preOrder(root);
    cout << endl << endl;
}

/*
13
50 75 25 60 22 15 40 44 64 30 80 33 63
*/