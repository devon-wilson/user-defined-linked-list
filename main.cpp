#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int MAX_STR = 200;
struct nodeType
{
	char data[MAX_STR];
        nodeType *link;
};

void addToList(nodeType* &first, nodeType* &last, char start[], char quit[]);
void printList(nodeType* first, char quit[]);

int main()
{
  	nodeType *first = NULL;
	nodeType *last = NULL;	
	char quit[MAX_STR] = "quit";
	char start[MAX_STR] = {'\0'};
	do
	{
		cout << "Enter data " << endl;
	        cin.getline(start, MAX_STR);	
		addToList(first, last, start, quit);
	}while(strcmp(start , quit) != 0);
	printList(first, quit);
	return 0;
}
 
void addToList(nodeType* &first, nodeType* &last, char start[], char quit[])
{
		nodeType *newNode = new nodeType;
		strcpy(newNode -> data, start);
		newNode -> link = NULL;
		if(first == NULL)
		{
			first = newNode;
			last = newNode;
		}
		else if(strcmp(newNode->data, quit) != 0)
		{
			last -> link = newNode;
			last = newNode;
		}
}

void printList(nodeType *first, char quit[])
{
	nodeType *current = first;	
	while(current)
	{
		cout << " " << endl;
		cout << current -> data << endl;
		current = current -> link;
		
	}
}

