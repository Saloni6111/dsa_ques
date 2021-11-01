// c++ codes for Inorder traversal of binary tree

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
  cout << root-> data<< " ";
  recur( root->right );
  
  
}



// Iterative

void iterative( node* root ){
     
    stack< node* > s;
    
        while( !s.empty() || root){
             
            while( root ){
                s.push(root);
                root = root->left;
            }
            
            node* temp = s.top();
            s.pop();
            cout << (temp->data) << " ";
            root = temp->right;
     }
}



// Morris 

void morris( node* root){
     
     node* temp;
        
        while(root){
            if(!root->left){
                cout << (root->data) << " ";
                root= root->right;
            }
            else{
                temp = root->left;
                
                while(temp->right && temp->right!=root) temp = temp->right;
                
                if(!temp->right){
                   temp->right = root;
                   root = root->left;
                    
                }else{
                    temp->right = NULL;
                    cout << (root->data) << " ";
                    root = root->right;
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
    morris(root);
    return 0;
}
