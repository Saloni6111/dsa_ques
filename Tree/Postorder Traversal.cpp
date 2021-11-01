// c++ codes for postorder traversal of binary tree

#include <bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node *left, *right;
};
 
node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// recursive 

void recur(node* root)
{
  if( root==NULL ) return;
  
  recur( root->left );
  recur( root->right );
  cout << root-> data<< " ";
  
}

// Iterative

void iterative( node* root ){
     
     stack<node*> s;
        node* last = NULL;
    
        while(root || !s.empty()){
            if(root){
                s.push(root);
                root = root->left;
            }else{
                node* temp = s.top();
                if( temp->right && temp->right!=last) root = temp->right;
                
                else{
                   cout << (temp->data) << " ";
                    last = temp;
                    s.pop();
                }
            }
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
 
    recur(root);
    cout<< '\n';
    iterative(root);
    cout<< '\n';
 
    return 0;
}
