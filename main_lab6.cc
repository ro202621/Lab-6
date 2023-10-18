/*************************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				
           Patricia Lindner             Spring 2023
*************************************************************************/
#include <iostream>
#include <ctime>
#include "header_lab6.h"
using namespace std;



// These are the three I have implemented for you which are
// available in the header_lab6.h file
//
// void build_list(node*& head);  // note that we are passing by reference
// void show_list(const node* head);
// int size(const node* head);

// These are the two that you are to write, as described in the instructions page.
// Please write them as a part of the header_lab6.h file.
//
// void remove_repeats(node*& head);
// void split_list(const node* original, node*& lesser, node*& greater, int split_value);


// Feel free to edit the main as much as you like for debugging.
// Please run the command 'make run_tests' to test your code before submitting.

int main(){
     int start, stop;
     int split;
     node* head = NULL;
     node* lesser;
     node* greater;

     start = time(NULL);
     build_list(head);
     stop = time(NULL);
     cout << "Time to build list = " << stop - start << " seconds.\n"; 

     cout << "This will be the list before the repeats are removed: " << endl;
     show_list(head);
     cout << "Size of the list = " << size(head) << endl;
     cout << "Time to print list = " << stop - start << " seconds. \n";

     cout << "Now time to remove the repeats! " << endl;

     remove_repeats(head);
     start = time(NULL);
     show_list(head);
     stop = time(NULL);
     cout << "Time to print list = " << stop - start << " seconds.\n";
     cout << "Size of the list = " << size(head) << endl;

     cout << "Now time to split the list using a split value.\n";
     cout << "Input split value (1 - 500): ";
     cin >> split;
     cout << "This is the value you chose: " << split << endl;

     split_list(head, lesser, greater, split);
     start = time(NULL);
     show_list(head);
     show_list(lesser);
     cout << "Size of lesser list: " << size(lesser) << endl;
     show_list(greater);
     cout << "Size of greater list: " << size(greater) << endl;
     stop = time(NULL);
     

     return 0;
}
