#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
	int data;
	struct node* previous;
	struct node* next;
} node;


void create_list(node* head, int length);
node* reverse_list(node* head);
void print_list(node* head);
void print_list_reverse(node* tail);

int main(void)
{

	int length;

	node* head;
	head = malloc(sizeof(node));
	if(head == NULL){
		printf("Out of memory. Exiting");
		return 1;
	}
	//head->previous = NULL;

	printf("Input length of linked list: ");
	scanf("%d", &length);
	printf("\n");

	printf("Creating linked list \n");
	create_list(head, length);
	printf("List created \n \n");

	printf("Printing list: \n");	
	print_list(head);

	printf("\nReversing list \n");
	head = reverse_list(head);
	printf("List reversed \n \n");

	printf("Printing reversed list: \n");
	print_list(head);
	
	return 0;
}

void create_list(node *head, int length)
{
	node* current = head;
	node* previous = NULL;
	
	int i;
	for(i = 0; i<=length; i++){

		current->data = i;
		current->previous = previous;

		if(i<length){
			current->next = malloc(sizeof(node));

			if(current->next == NULL){
				printf("Out of memory. Exiting");
				return;
			}
		}
		else current->next = NULL;

		previous = current;
		current = current->next;
	}
}


node* reverse_list(node *head)
{

	node* current = head;
	node* temp;
	node* new_head;

	while(current != NULL){
		
		if(current->next == NULL) new_head = current;
		

		temp = current->next;
		current->next = current->previous;
		current->previous = temp;
		current = temp;
	}
	
	new_head->previous = NULL;
	return new_head;
}


void print_list(node* head)
{

	node* current = head;
		
	while(current != NULL){
		printf("%d \n", current->data);
		if(current->next == NULL) print_list_reverse(current);	
		current = current->next;
	}
}

void print_list_reverse(node* tail)
{

	node* current = tail;
	
	while(current != NULL){
		printf("%d \n", current->data);
		current = current->previous;
	}	
	
}
