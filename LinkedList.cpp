#include "LinkedList.h"
//adds item to the front of the list
void Single_Linked_List::push_front(string item) {
  //if list empty, create the item and set it to head and tail
  if(num_items == 0){
    head = new Node(item);
    tail = head;
  }
  else{
    Node* node = new Node(item);
    node->next = head;
    head = node;  
  }
  num_items++;   
}
//add item to the back of the list
void Single_Linked_List::push_back(string item) {
  //if list is empty, set it to the head and the tail
  if(num_items == 0){
    head = new Node(item);
    tail = head;
  }
  else{
    Node* node = new Node(item);
    tail->next = node;
    tail = node;  
  }
  num_items++;   
}
//removes the first value in the list
void Single_Linked_List::pop_front() {
  Node* node = head;
  head = head->next;
  delete node;
  num_items--;   
}
//removes the last value in the list
void Single_Linked_List::pop_back() {
  int n = 0;
  Node* node = head;
  //while loop to get to the second to last value
  //this way we can set its next value to null so no data leaks.
  while(n != num_items-1){
    node = node->next;
    n++;
  }
  Node* ptr = node->next;
  node->next = NULL;
  tail = node;
  delete ptr;
  num_items--;   
}
//returns value at the beginning of the list
string Single_Linked_List::front(){
  return head->data;
}
//returns the value at the end of the list
string Single_Linked_List::back(){
  return tail->data;
}
//Function to check if the list is empty, if so, returns true
bool Single_Linked_List::empty(){
  if(num_items = 0)
    return true;
  else
    return false;
}
//enter a node into the chosen index
void Single_Linked_List::insert(int index, string item){
  //if first position, just use push_front();
  if(index == 0)
    push_front(item);
  //if last position, just use push_back();
  else if(index >= num_items-1)
    push_back(item);
  //if index is in the middle, iterate through  
  else{
    Node* ptr = head;
    int n = 0;
    while(n != index-1){
      ptr = ptr->next;
      n++;
    }
    //Create the new node
	  Node* node = new Node(item);
    node->next = ptr->next;
    ptr->next = node;
  }
}

bool Single_Linked_List::remove(int index) {
  //if first index, call pop_front
  if (index == 0){
    pop_front();
    return true;
  }
  //if last index, call pop_back
  else if (index == num_items-1){
    pop_back();
    return true;
  }
  //if index is greater than the size of list, return false
  else if (index > num_items-1)
    return false;
  //if index is in the middle, iterate till the value before it.
  else{
    int n = 1;
    Node* ptr = head;
    while(n < index){
      ptr = ptr->next;
      n++;
    }
    //set node to note to delete, then change the ptr of the node before it to the note after it.
    Node* node = ptr->next;
    ptr->next = ptr->next->next;
    delete node;
    num_items--; 
    return true;
  }
}
//returns the index of the item we are looking for, if not found, returns list size.
int Single_Linked_List::find(string item) {
  //loop through list
  Node* ptr = head;
  int n = 0;
  while(n < num_items){
    //if the value matches what we are hunting for, return the index
    if(ptr->data == item)
      return n;
    ptr = ptr->next;
  }
  //if not found, return the size of list
  return num_items;
}