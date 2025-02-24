#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//This declares a Node Data Structure
struct Node{
    int data;
    Node* Previous_Node;
    Node* Next_Node;
};

int nodes_freed = 0;

//This function inserts a new node onto the linked list
void insert_node(Node* Node);
//This function creates a random number for a data point
int random_num();
//This function recursively frees the entire doubly linked list
void recursion_free(Node* Node);

//Main Function
int main() {

    int user_choice;
    string user_nochoice;
    cout << "Please choose how many links in the linked list you would like to create!\n";
    cin >> user_choice;
    cout << "Great! Away we go!!!!\n";

    //This is to 'seed' a random number generator for our node-> int data;
    time_t current_time = time(nullptr);
    srand((unsigned) current_time);

    //This Creates the Head of the doubly linked list...
    //allocates a beginning node and assigns data, previous, next values.
    Node* Head = new Node;
    Head->data = random_num();
    Head->Previous_Node = nullptr;
    Head->Next_Node = nullptr;

    //For loop using Custom Function to malloc 4 nodes into a doubly Linked List
    for (int x = 0; x < user_choice; x++) {
        insert_node(Head);
    }

    cout << "Your list is created!\n";
    cout << "Would you like to set the nodes free??\n";
    cin >> user_nochoice;
    //This function recursively frees the entire doubly linked list
    recursion_free(Head);
    cout << nodes_freed-1 << "  Nodes Freed!\n";
    return 0;
}

//this function is used to insert a new node to the doubly linked list
void insert_node(Node* Head) {

//initialize variable to store end of list address
    Node* Prev_End = Head;
    Node* tmp = Head;
    while (tmp->Next_Node != nullptr) {
        tmp = tmp->Next_Node;
        if (tmp->Next_Node == nullptr) {
            Prev_End = tmp;
        }
    }
    Node* New_Node = new Node;
    New_Node->data = random_num();
    New_Node->Previous_Node = Prev_End;
    New_Node->Next_Node = nullptr;

    tmp->Next_Node = New_Node;
    cout << "Node created!\n";
    cout << "Node address!  " << New_Node << "\n";
    cout << "Prior node  " << New_Node->Previous_Node << "\n";
}

int random_num() {
    //This creates a random number
    int random_number = rand() % 10;
    return random_number;
}

void recursion_free(Node* Head) {
    if (Head->Next_Node != nullptr) {
        recursion_free(Head->Next_Node);
    }
    delete Head;
    nodes_freed++;
}
