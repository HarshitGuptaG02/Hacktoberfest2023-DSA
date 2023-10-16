#include<iostream>	//haeder files
using namespace std;

// create node
struct Node
{
  int data;
  struct Node *next;
} *head;

void insertStart (struct Node **head, int data)	//function to create linked list
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  // if its the first node being entered
  if (*head == NULL)
    {
      *head = newNode;		// assigning itself as head
      (*head)->next = *head;	// assigning itself as next node

      cout << newNode->data << " Inserted\n";
      return;
    }

  // if CLL already as >=1 node
  struct Node *curr = *head;

  // traverse till last node in CLL
  while (curr->next != *head)
    {
      curr = curr->next;
    }

  curr->next = newNode;		// last node's next as this new node
  newNode->next = *head;	// new node's next as current head node

  *head = newNode;		// changing head node to this new node
  cout << newNode->data << " Inserted\n";

  // previous head node becomes 2nd node
}

// this function for insert the new node in linked list 

void sortedInsert (struct Node **head, int n)
{
  struct Node *nextNode = (struct Node *) malloc (sizeof (struct Node));
  nextNode->data = n;
  struct Node *thisNode = (struct Node *) malloc (sizeof (struct Node));
  thisNode = *head;

  // Case 1 of the above algo 
  if (thisNode == NULL)
    {
      nextNode->next = nextNode;
      *head = nextNode;
    }

  // Case 2 of the above algo 
  else if (thisNode->data >= nextNode->data)
    {
      /* If value is smaller than head's value then 
         we need to change next of last node */
      while (thisNode->next != *head)
	thisNode = thisNode->next;
      thisNode->next = nextNode;
      nextNode->next = *head;
      *head = nextNode;
    }

  // Case 3 of the above algo 
  else
    {
      /* Locate the node before the point of insertion */
      while (thisNode->next != *head && thisNode->next->data < nextNode->data)
	thisNode = thisNode->next;

      nextNode->next = thisNode->next;
      thisNode->next = nextNode;
    }
}


//this Function to print nodes in a given linked list
void display (struct Node *head)
{

  cout << "\nCircular Linked List : " << endl;

  // if circular linked list is empty currently
  if (head == NULL)
    return;

  struct Node *temp = head;

  // since we need to take care of circular nature of linked list
  do
    {
      cout << temp->data << " ";
      temp = temp->next;

    }
  while (temp != head);
  cout << endl;
}


// main method start
int main ()
{

  struct Node *head = NULL;

  insertStart (&head, 50);
  insertStart (&head, 40);
  insertStart (&head, 30);
  insertStart (&head, 20);
  insertStart (&head, 10);
  cout << "Before insertion ";
  display (head);
  sortedInsert (&head, 33);
  cout << "After insertion ";
  display (head);

  return 0;
}
