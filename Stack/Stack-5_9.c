#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Item
{
	int val1;
	int val2;
	int id;
	struct Item* next;
	struct Item* prev;
};
struct Item* Head = NULL;
struct Item* Tail = NULL;
int counterID = 1;

//A function that pushes(adds) items to stack
void Push(int val1, int val2)
{
	struct Item* currentItem;
	currentItem = (struct Item*)malloc(sizeof(struct Item));
	if (currentItem == NULL)
	{
		printf("ERROR - Not enough memory");
		return;
	}
	else
	{
		currentItem->val1 = val1;
		currentItem->val2 = val2;

		if (Head == NULL)
		{
			Head = currentItem;
			Tail = currentItem;
			currentItem->next = NULL;
			currentItem->prev = NULL;
		}
		else
		{
			currentItem->prev = NULL;
			currentItem->next = Head;
			Head->prev = currentItem;
			Head = currentItem;
		}

		currentItem->id = counterID;
		counterID++;
	}
}

//A function that prints the linked list-stack
void printList()
{
	struct Item* currentItem = Tail;

	printf("The resulting linked list:\n");
	while (currentItem != NULL)
	{
		printf("val1: %d val2: %d id: %d\n", currentItem->val1, currentItem->val2, currentItem->id);
		currentItem = currentItem->prev;
	}
}

//A function that removes an item from stack 
//FILO-First In, Last OUT
struct Item* Pop()
{
	struct Item* ret = Head;

	if (Head->next != NULL)
	{
		Head = Head->next;
		Head->prev = NULL;
	}

	return ret;
}


int main()
{
	struct Item* popedItem;
	int sum = 0;
	srand(time());

	char userResponse = NULL;
	while (userResponse != 'E')
	{
		printf("\nPlease enter one of the following choices:\n'I'-insert item to the stack\n'P'-pop item from the stack\n'L'-print the stack\n'B'-bulk insert\n'Z'-pop 10 items from stack\n'E'-exit the program\n");
		userResponse = getch();

		switch (userResponse)
		{
		case 'I': //Insert - insert items to linked list-stack
			Push(rand(), rand());
			break;
		case 'P': //Pop - remove item from the stack and print the item that you remove
			popedItem = Pop();
			printf("Item: val1: %d val2: %d id: %d\n", popedItem->val1, popedItem->val2, popedItem->id);
			free(popedItem);
			break;
		case 'L': //Print - print the linked list-stack
				printList(); 
				break;
		case 'B': //Bulk insert - enters 100 items to stack with random numbers
			for (int i = 0; i < 100; i++)
			{
				Push(rand(), rand());
			}
			break;
		case 'Z': //Pop 10 items from stack and claculates the sum of their value

			for (int i = 0; i < 10; i++)
			{
				popedItem = Pop();
				sum = sum + popedItem->val1 + popedItem->val2;
				free(popedItem);
			}
			printf("The sum of the values is: %d\n", sum);
			break;
		case 'E': //Exit - exit the program
			printf("Thank you for using our program\n");
			break;

		default:
			printf("Wrong selection, please try again\n");
			break;
		}
	}

	return 0;
}