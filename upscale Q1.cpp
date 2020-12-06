#include <iostream> 
#include<bits/stdc++.h>
using namespace std; 

struct node 
{ 
    int data; 
    struct node *l, *r; 
}; 
  
void printkdistanceNodeDown(node *root, int k) 
{ 
    
    if (root == NULL || k < 0)  return; 
  
    if (k==0) 
    { 
        cout << root->data << endl; 
        return; 
    } 
  
    
    printkdistanceNodeDown(root->l, k-1); 
    printkdistanceNodeDown(root->r, k-1); 
} 
   
int printkdistanceNode(node* root, node* target , int k) 
{ 
    
    if (root == NULL) return -1; 
    if (root == target) 
    { 
        printkdistanceNodeDown(root, k); 
        return 0; 
    } 
    int dl = printkdistanceNode(root->l, target, k); 
    if (dl != -1) 
    { 
 
         if (dl + 1 == k) 
            cout << root->data << endl; 
  
         else
            printkdistanceNodeDown(root->r, k-dl-2); 
  
        
         return 1 + dl; 
    } 
    int dr = printkdistanceNode(root->r, target, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            cout << root->data << endl; 
         else
            printkdistanceNodeDown(root->l, k-dr-2); 
         return 1 + dr; 
    } 
    return -1; 
} 
  
node *newnode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->l = temp->r = NULL; 
    return temp; 
} 
  
int main() 
{ 
    node * root = newnode(20); 
    root->l = newnode(8); 
    root->r = newnode(22); 
    root->l->l = newnode(4); 
    root->l->r = newnode(12); 
    root->l->r->l = newnode(10); 
    root->l->r->r = newnode(14); 
    node * target = root->l->r; 
    printkdistanceNode(root, target, 2); 
    return 0; 
}
