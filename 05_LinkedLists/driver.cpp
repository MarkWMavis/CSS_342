#include <iostream>
#include <cstdio>
using namespace std;

class Node {
private:
	int _data;		//Data member holding data
	Node* _next;	//Data member holding the address to the next node

public:
	//Default Node Constructor
	Node() {
		this->_data = 0;
		this->_next = nullptr;
	}
	//Node Constructor that takes a data parameter and defaults the _next field to nullptr
	Node(int data) {
		this->_data = data;
		this->_next = nullptr;
	}
	//Node Constructor that takes a data parameter and assigns it to the node passed in.
	Node(int data, Node* other) {
		this->_data = data;
		this->_next = other;
	}
	//Function return the address of the next node
	Node* getNext() {
		return _next;
	}
	//Function that has access to setting the address of the next node
	void setNext(Node* other) {
		_next = other;
	}
	//Function that returns the data value of the node
	int getData() {
		return _data;
	}
	//Function that finds and returns the length of the current list
	int length() {
		//Base case: when the end of the list is reached, return +1
		if (_next == nullptr) {
			return 1;
		}
		//Until the end of the list is reached, keep recursively calling and adding 1
		else {
			return 1 + _next->length();
		}
	}
	
	//Function that takes a data field and recursively walks itself down the list to the end (which is the base case), once 
	//the end is reached, the node creates itself and links it onto the end
	void append(int data) {
		//Recursive Append Method
		if (_next == nullptr) {
			//Creating new node and linking it onto the end of the list
			_next = new Node(data);		
		}
		else {
			//Recursively calling the function and passing the data
			_next->append(data);		
		}
	}

	//Function that takes a pos and data variable as arguments.  
	void insert(int pos, int data) {
		//Recursive Insert Method
		if (pos == 1) {
			_next = new Node(data, _next);
		}else {
			_next->insert(pos - 1, data);
		}
	}
	
	//Function responsible for removing a node at a user specific position
	void remove(int pos) {
		//Base case:
		//If currently at the corrent position
		if(pos == 1) {
			//Create new node and assign to null
			Node* newNext = NULL;
			//if the 
			if (_next != nullptr) {
				//Assign newNext node to the next node
				newNext = _next->getNext();
				//Clear memory of the next node
				delete _next;
			}
			//assign the next node to the newNext node
			_next = newNext;
		}
		//Recursive case:
		//If not at the corrent position passing pos-1
		else {
			_next->remove(pos - 1);
		}
	}

	//Function responsible for printing the list
	void printList() {
		//Base case: Once the end is reached, stop and print the last nodes data
		if (_next == nullptr) {
			cout << getData() << "->";
			return;
		}
		//Recursive case: print the data and then recursively call the print function on the next node
		else {
			cout << getData() << "->";
			_next->printList();
		}
	}

	//Function that is responsible for recursively reversing the nodes in the current list
	Node* reverseRecursive(Node* prev) {
		//Base case: one the end is reached
		if (_next == nullptr) {
			//return the address of the last node and connect to the previously connected nodes
			_next = prev;
			return this;
		}
		else {
			//Recursive case: create a temp node and point it at the next node of the current node object
			Node* temp = _next;
			//assign the current objects next field to null (disconnect the node)
			_next = prev;
			//recursively call on the temp object and repeat the process
			return temp->reverseRecursive(this);
		}
	}
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() {
		head = NULL;
	}

	// Assume shallow copy constructor required
	LinkedList(const LinkedList& obj) {
		head = obj.head;
	}


	//Function checks whether there is a list or not, if so, call the node classes length function and return that value
	int length() {
		//if there is a list
		if (head != nullptr) {
			//call the node class length method, find the number of items in the list and return the value
			return head->length();
		}
		//The list must be empty
		else {
			return 0;
		}
	}
	//Function responsible for checking if there is anything in the list
	void append(int data) {
		//if the list is not empty
		if (head != nullptr) {
			//call the node classes append method on the head and pass the value the user wants to append
			head->append(data);
		}
		//The list must be empty so create a new node with the passed data and assign it to the head
		else {
			head = new Node(data);
		}
	}

	//Function is responsible for checking to see if the user requested an appropriate position location within the existing
	//list, and if so, either create a new Node for the empty list or tell the Node class insert to place a node in the position
	//requested by the user

	int insert(int pos, int data) {
		//Checking to see if the position fits within the bounds of the current list. If so, return true (1)
		if ((pos < 0) || (pos > length())) {
			return 1;
		}
		//If there is a list, Execute inside statements
		if (head != nullptr) {
			//If the position requested to insert is 0, create new node and assign the head to it
			if (pos == 0) {
				head = new Node(data, head);
			}
			//Pass the position and the data to the insert function of the node class
			else {
				head->insert(pos, data);
			}
		}
		else {
			//Assign empty list to a newly creaded node
			head = new Node(data);
		}
		return 0;
	}
	//Function responsible for reversing the list in a iterative fasion
	void reverseIterative() {
		//If the list was 1 or less, there would be nothing to rearrange so check the list is greater than 1
		if (length() > 1) {
			//Create a new node named "prev" and assign it to head
			Node* prev = head;
			//Create a new node named "curr" and assign it to the next node after head. This node Holds the list while we pluck
			//out the previous node
			Node* curr = head->getNext();
			//Disconnect the pointer of the Node that the "prev" node points too
			prev->setNext(NULL);
			//Keep going until the "curr" node has reached the end of the list
			while (curr != nullptr) {
				//Create a temp node to hold the "curr" next node
				Node* temp = curr->getNext();
				//assign the "curr" node to the previous node
				curr->setNext(prev);
				//point the previous node to the curr node
				prev = curr;
				//point the curr node at the temp node
				curr = temp;
			}
			//assign head to the rearrangment of nodes
			head = prev;
		}
	}
	//Function responsible for checking to make sure there is a list of size greater then 1
	void reverseRecursive() {
		//If there is a list greater than 1
		if (length() > 1) {
			//Call the Node class reverse method on the head and assign the head to the reversed returned list
			head = head->reverseRecursive(NULL);
		}
	}

	//Function responsible for making sure the user requested a valid position in the existing list, and if so, calling 
	// to recursively remove the data at that position through the Node class
	int remove(int pos) {
		//Test if the user requested a position outside the bounds of the existing linked list
		if ((pos < 0) || (pos >= length())) {
			cout << "There is nothing to delete in that position" << endl;
			return 1;
		}
		//If asking for a valid positon, execute inside block
		else {
			//if asking to remove the first position
			if (pos == 0) {
				//Assign temp node to hold the following list
				Node* temp = head->getNext();
				//clear up memory of the head node
				delete head;
				//reassign head to the temp list being held by temp variable
				head = temp;
			}
			//If asking to remove any other position other than the first position
			else {
				//Call the node classes remove method on the head
				head->remove(pos);
			}
			return 0;
		}
	}
	//Function responsible for testing whether there is data in the list to print and if not, tell the user it is
	//empty, and if so, call the Node classes printList function
	void printList() {
		if (head != nullptr) {
			head->printList();
		}
		//if empty list, tell the user
		else {
			cout << "The list is empty" << endl;
			return;
		}
	}
};

int main()
{
	LinkedList* myList = new LinkedList();
	
	
	for (int i = 0; i < 15; i++) {
		auto v1 = rand() % 100;
		myList->printList();
		printf("\n");
		printf("Appending %d\n", v1);
		myList->append(v1);
	}
	myList->printList();
	printf("\n");
	printf("Inserting Data 4 at position 4\n");
	myList->insert(4, 4);
	myList->printList();
	printf("\n");
	printf("Inserting Data 5 at position 2\n");
	myList->insert(2, 5);
	myList->printList();
	printf("\n");
	printf("Reversing the list Iteratively\n");
	myList->reverseIterative();
	myList->printList();
	printf("\n");
	printf("Reversing the list Recursively\n");
	myList->reverseRecursive();
	myList->printList();
	printf("\n");
	printf("Remove position 7\n");
	myList->remove(7);
	myList->printList();
	printf("\n");
	printf("Remove position 20\n");
	myList->remove(20);
	myList->printList();
	printf("\n");
	printf("Remove position 2\n");
	myList->remove(2);
	myList->printList();

	return 0;
}
