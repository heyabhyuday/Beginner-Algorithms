#include <iostream>
#include <vector>
using namespace std;

vector<int> v1;

class node {
public:
  int key;
  node *left, *right;
  node *insert(node *n, int k);
  node() {
    key = 0;
    left = NULL;
    right = NULL;
  }
  node(int val) {
    key = val;
    left = NULL;
    right = NULL;
  }
};

node *insert(node *root, int key) {

  if (root == NULL) {
    root = new node(key);
  }

  else if (key < root->key) {
    root->left = insert(root->left, key);
  } else {
    root->right = insert(root->right, key);
  }
  return root;
}

struct node *leftmostNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

node *deleteNode(node *root, int key) {
  if (root == NULL) {
    return root;
  }
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = leftmostNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }

  return root;
}

void inorder(node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
  }
}

bool flag = false;

bool search(node *root, int key) {
  if (root->key == key) {
    flag = true;
  }
  else if (root->key > key){
    search(root->left, key);
  }
  else{
    search(root->right, key);
  }
  return flag;
}

vector<int> arr_creator(node *root) {
  if (root != NULL) {
    arr_creator(root->left);
    v1.push_back(root->key);
    arr_creator(root->right);
  }
  return v1;
}

vector<int> pop_val(vector<int> v1, int val) {
  vector<int> v2;
  for (int i = 0; i < v1.size(); i++) {
    if (v1[i] != val) {
      v2.push_back(v1[i]);
    }
  }
  return v2;
}

node *balancing( vector<int> v) {
  int mid;
  node *root = NULL;
  while (v.size() != 0) {
    if (v.size() % 2 != 0) {
      mid = ((v.size() + 1) / 2)-1;
      root = insert(root, v[mid]);
      v = pop_val(v, v[mid]);
    } else {
      mid = v.size() / 2;
      root = insert(root, v[mid]);
      v = pop_val(v, v[mid]);
    }
  }
  return root;
}

int main() {
  node *root = NULL;
  root = insert(root, 15);
  root = insert(root, 14);
  root = insert(root, 13);
  root = insert(root, 12);
  root = insert(root, 8);
  root = insert(root, 12);

  cout << "Inorder : ";
  inorder(root);
  cout << endl;
  cout<< "Root points to : " << root->key << endl;
  
  int pos_val;
  cout << endl << "What tree value do you want to search : ";
  cin >> pos_val;
  if (search(root, pos_val)){
    cout << "It is there" << endl;
  }
  else{
    cout << "Not there" << endl;
  }

  cout << endl << "What tree value do you want to delete : ";
  int val;
  cin >> val;
  root = deleteNode(root, val);
  
  cout << endl << "Inorder after deleting : ";
  inorder(root);
  cout << endl;
  cout<< "Root points to : " << root->key << endl;
  
  vector<int> v = arr_creator(root);
  root = balancing(v);
  
  cout << endl << "Inorder after balancing : ";
  inorder(root);  
  cout << endl;
  cout<< "Root points to : " << root->key << endl;
  
}