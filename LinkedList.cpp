#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *next;
};

struct node *head, *tail = NULL;

void nodeAdder(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void init_list() {
  int n;
  cout << "Enter the size of the list: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    int data;
    cout << "Enter value " << i + 1 << ": ";
    cin >> data;
    nodeAdder(data);
  }
}

void printList() {
  struct node *current = head;

  if (head == NULL) {
    cout << "The list is empty.";
    return;
  }
  cout << "The list currently: \n";
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int insert() {
  int x, pos;

  cout << "\nEnter position you want to insert the node at: ";
  cin >> pos;
  pos = pos - 1;
  cout << "Enter the data: ";
  cin >> x;
  cout << endl;

  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = x;

  struct node *temp = head;

  if (pos == 0) {
    newNode->next = head;
    head = newNode;
    printList();
    return 0;
  }
  for (int i = 1; i < pos; i++) {
    if (temp->next != NULL) {
      temp = temp->next;
    }
  }
  newNode->next = temp->next;
  temp->next = newNode;

  printList();
  return 0;
}

int del() {
  int pos;
  cout << "\nEnter the position you wish to delete: ";
  cin >> pos;
  pos = pos - 1;
  cout << endl;

  struct node *temp = head;

  if (pos == 0) {
    head = temp->next;
    printList();
    return 0;
  }
  for (int i = 1; i < pos; i++) {
    if (temp->next != NULL) {
      temp = temp->next;
    }
  }
  temp->next = temp->next->next;

  printList();
  return 0;
}

int lookup() {
  bool checker = false;
  int val;
  cout << "\nEnter the value you wish to search for: ";
  cin >> val;

  struct node *current = head;

  while (current != NULL) {
    if (current->data == val) {
      checker = true;
      cout << "Value was found.\n";
      return 0;
    }
    current = current->next;
  }
  if (checker == false) {
    cout << "Value was not found.\n";
  }
  return 0;
}

int main() {
  init_list();
  cout << endl;
  printList();
  cout << endl;
  del();
  insert();
  lookup();
}