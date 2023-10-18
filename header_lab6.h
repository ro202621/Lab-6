#include <cstdlib>
#include <iostream>

struct node{
     int data;
     node* next;
};

// remove all repeats inside of the list
void remove_repeats(node*& head) {
    if(head == nullptr){
        return;
    }

    node* current = head;

    while(current != nullptr){
        node* runner = current;
        while(runner -> next != nullptr){
            if(runner -> next -> data == current -> data){
                node* tmp;
                tmp = runner -> next;
                runner -> next = runner -> next -> next;
                delete tmp;
            }
            else{
                runner = runner -> next;
            }
        }

        current = current -> next;
    }
}

// split the list at a value present in the list
void split_list(const node* original, node*& lesser, node*& greater, int split_value) {
	const node* current = original;

    lesser = nullptr;
    greater = nullptr;

    node* lTail = nullptr;
    node* gTail = nullptr;

    while(current != nullptr){
        node* newNode = new node{current -> data, nullptr};

        if(current -> data < split_value){
            if(lesser == nullptr){
                lesser = newNode;
                lTail = newNode;
            }
            else{
                lTail -> next = newNode;
                lTail = newNode;
            }
        }
        else{
            if(greater == nullptr){
                greater = newNode;
                gTail = newNode;
            }
            else{
                gTail -> next = newNode;
                gTail = newNode;
            }
        }
        current = current -> next;
    }
}

// builds a linked list of 2000 random integers, all in the range 1 - 500
void build_list(node*& head){
     node* cursor;

     head = new node;
     head -> data = std::rand() % 500 + 1;

     cursor = head;
     for(int i = 0; i < 2000; ++i){
		cursor -> next = new node;
        cursor = cursor -> next;
        cursor -> data = std::rand() % 500 + 1;
     }
     cursor -> next = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
     const node* cursor = head;

     while(cursor !=  NULL){
		std::cout << cursor -> data << "  ";
		cursor = cursor -> next;
	 }
	 std::cout << std::endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor -> next;
	}
	return count;
}
