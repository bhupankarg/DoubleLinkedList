#include<iostream>

using namespace std;

class LinkedList
{
private:
	int data;
	LinkedList* previous;
	LinkedList* next;
	LinkedList* head = nullptr;
	LinkedList* tail = nullptr;
	LinkedList(int);

public:
	LinkedList();
	void InsertNewNode(int);
	void displayLinkedList(void);
	int TotalNodes(void);
	void InsertNthNode(int);
	void DeleteAfterNthNode(int);
};

LinkedList :: LinkedList(){}

LinkedList :: LinkedList(int data)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

void LinkedList :: InsertNewNode(int data)
{
	LinkedList* newNode = new LinkedList(data);
	if(head == nullptr)
	{
		head = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->previous = tail;
	}
	tail = newNode;
	cout << data << " is inserted successfully" << endl;
}

void LinkedList :: displayLinkedList(void)
{
	if(head == nullptr)
	{
		cout << "Error: Empty list. Nothing to display." << endl;
		return;
	}
	LinkedList* temp = head;
	cout << "The list is..." << endl;
	while(temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int LinkedList :: TotalNodes()
{
	int count = 0;
	LinkedList* temp = head;
	while(temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void LinkedList :: InsertNthNode(int pos)
{
	if(pos <= TotalNodes() and pos >= 1)
	{
		LinkedList* temp = head;
		int data, currPos = 1;
		cout << "Enter the data..." << endl;
		cin >> data;
		LinkedList* newNode = new LinkedList(data);
		while(true)
		{
			if(currPos == pos)
			{
				if(temp->next != nullptr)
				{
					newNode->next = temp->next;
					temp->next->previous = newNode;
				}
				temp->next = newNode;
				newNode->previous = temp;
				cout << data << " is inserted successfully after position " << pos << endl;
				return;
			}
			temp = temp->next;
			currPos++;
		}
	}
	cout << "Error: Invalid position" << endl;
}

void LinkedList :: DeleteAfterNthNode(int pos)
{
	if(pos <= TotalNodes() and pos >= 1)
	{
		int currPos = 1;
		LinkedList* temp = head;
		while(true)
		{
			temp = temp->next;
			if(currPos == pos)
			{
				if(temp == nullptr)
				{
					cout << "Error: " << pos << " is the last position. Nothing to delete after." << endl;
					return;
				}
				temp->previous->next = temp->next;
				if(temp->next != nullptr)
				{
					temp->next->previous = temp->previous;
				}
				cout << temp->data << " is deleted successfully" << endl;
				cout << "Current total number of nodes: " << TotalNodes() << endl;
				delete temp;
				return;
			}
			currPos++;
		}
	}
	cout << "Error: Invalid position" << endl;
}

int main()
{
	int choice, data, pos;
	LinkedList* linkedList = new LinkedList;
	while(true)
	{
		cout << endl;
		cout << "1: Insert new node" << endl;
		cout << "2: Display linked list" << endl;
		cout << "3: Count total nodes" << endl;
		cout << "4: Insert after Nth node" << endl;
		cout << "5: Delete after Nth node" << endl;
		cout << "0: Exit menu" << endl;
		cout << "Enter your choice..." << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter the data..." << endl;
				cin >> data;
				linkedList->InsertNewNode(data);
				break;
			case 2:
				linkedList->displayLinkedList();
				break;
			case 3:
				cout << "Total number of nodes: " << linkedList->TotalNodes() << endl;
				break;
			case 4:
				cout << "Enter the position..." << endl;
				cin >> pos;
				linkedList->InsertNthNode(pos);
				break;
			case 5:
				cout << "Enter the position..." << endl;
				cin >> pos;
				linkedList->DeleteAfterNthNode(pos);
				break;
			case 0:
				exit(0);
			default:
				cout << "Error: Invalid choice. Enter again." << endl;
				break;
		}
	}
	return 0;
}
