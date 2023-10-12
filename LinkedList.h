#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
	string data;
	Node* next;
  Node(const string& data_item, Node* next_ptr = NULL) : data(data_item), next(next_ptr) {}
};

class Single_Linked_List {
private:
	Node* head;
  Node* tail;
  int num_items;

public:
  Single_Linked_List(){
    head = NULL;
    tail = NULL;
    num_items = 0;
  }
  void push_front(string item);
  void push_back(string item);
  void pop_front();
  void pop_back();
  string front();
  string back();
  bool empty();
	void insert(int index, string item);
	bool remove(int index);
  int find(string item);
};