// c++ codes for preorder traversal of binary tree

#include <bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node *left, *right;
};
 
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// recursive 

void pre1(node* root)
{
  if( root==NULL ) return;
  
  cout << root-> data<< " ";
  pre1( root->left );
  pre1( root->right );
}

// Iterative

void pre2( node* root ){
     if( root==NULL ) return;
     
     stack< node* > s;
     s.push( root );
     
     while(!s.empty()){
          node* temp = s.top();
          s.pop();
          
          cout << temp->data << " ";
          
          if( temp->right ) s.push(temp->right);
          if( temp-> left ) s.push( temp->left );
     }
}

// iterative (space optimised)

void pre3(node* root){
     if( root==NULL ) return;
     
     stack< node* > s;
     node* curr = root;
     
     while(curr || !s.empty()){
          
          while(curr){
               cout << curr->data << " ";
               if( curr->right ) s.push( curr->right );
               
               curr = curr->left;
          }
          
          if(!s.empty()){
               curr = s.top();
               s.pop();
          }
     }
}

// Morris traversal

void pre4(node* root){
     
     if(root==NULL) return;
     
     while(root){
          
          if( !root->left ){
               
               cout << root->data << " ";
               root = root->right;
          }
          else{
               node* temp = root->left;
               while( temp->right && temp->right!= root){
                    temp = temp->right;
               }
               
               if( temp->right==NULL ){
                    cout << root->data << " ";
                    temp->right = root;
                    root = root->left;
               }
               else{
                    temp->right = NULL;
                    root = root->right;
               }
          }
     }
}


void preorder(node* root)
{
    if (root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
 
/* Driver program to test above functions*/
int main()
{
    node* root = NULL;
 
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
 
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
 
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
 
    pre1(root);
    cout<< '\n';
    pre2(root);
    cout<< '\n';
    pre3(root);
    cout<< '\n';
    pre4(root);
    
    cout<< '\n';
    preorder(root);
 
    return 0;
}

/*
   OUTPUT:
    1 2 4 8 9 5 10 11 3 6 7 
    1 2 4 8 9 5 10 11 3 6 7 
    1 2 4 8 9 5 10 11 3 6 7 
    1 2 4 8 9 5 10 11 3 6 7 
    1 2 4 8 9 5 10 11 3 6 7 
    =====
    Used: 0 ms, 1032 KB
*/
