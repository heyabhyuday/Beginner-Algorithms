
#include<iostream>
//#include<queue>     // to use in insert node
using namespace std;

class Node // Data members, left & right child node pointers, member functions & constructors
{
public:
    int data;  //right and left node pointers
    Node *left;     //To access left child of leaf
    Node *right; //To access right child of leaf

    Node(){
        data  =0; // initializing data to 0
        left = NULL; // initializing left to NULL
        right = NULL; // "
    }
    Node(int); //parameterized constructor

};

Node::Node(int val) {
   data =  val; // initializing data to val
   left = NULL; //Initializing the left child to NULL
   right = NULL; // "
}

void treeInsert(Node * root, int val){

    if(root == NULL){ // checking if root is null
        root = new Node(val);   //initialising new node with the value
        return;
    }
    else{
        Node* temp = new Node(val);     //creating a Node for the value inputted
        //if(temp->data > root->data){}
        Node* cur = root; // Now yall start the loop
        while(true)
        {
            if (cur->data <= val) {
                if (cur->right == NULL) {
                    cur->right = temp;
                    break;
                } else {
                    cur = cur->right; //update the value of current
                }
            } else {
                if(cur->left == NULL){
                    cur->left = temp;
                    break;
                }
                else{
                    cur = cur->left;//"
                }
            }
        }
    }



} // To create a node with the value and insert it into the tree with the root provided.
