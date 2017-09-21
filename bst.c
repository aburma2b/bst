#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
	int data;
  	struct node* low;
	struct node* high;
} node;

typedef struct list_node{
	int data;
	struct list_node* next;
} list_node;

void construct_bst(node* root, int value);
node* search_bst(node* root, int value); 
void delete_node(node* root, int value);
void traverse_bst(node* root, list_node** ptr_to_head); 
void process_node(int data, list_node** ptr_to_head);
void print_list(list_node** ptr_to_head);
node* inorder_successor(node* root);
node* min_value_rec(node* root);

int main (void)
{

	int continue_input; 
	int data;
	node* temp;

	node* root = malloc(sizeof(node));
	printf("Enter a data value for root: ");
	scanf("%d", &root->data);
	printf("\n");

	list_node* head = NULL;
	list_node** ptr_to_head = &head;
	
	while(true){
		printf("Would you like to input something into BST (0:exit, 1:input, 2:search, 3:del, 4:traverse): ");
		scanf("%d", &continue_input);
		if(continue_input == 0) break;
		//printf("\n");
                 
		else if(continue_input == 1){
			printf("Enter an integer: ");
			scanf("%d", &data);
			construct_bst(root, data);
			printf("Data successfully entered into BST \n");
		}

		else if(continue_input == 2){
			printf("Enter an integer to search for: ");
			scanf("%d", &data);
			temp = search_bst(root, data);

			if(temp != NULL){
				printf("Value found in BST: %d\n", temp->data);
			}
			else printf("Value not in BST\n");
		}

		else if(continue_input == 3){
			printf("Enter an integer to delete: ");
			scanf("%d", &data);
			delete_node(root, data);
			printf("Value and node deleted\n");
		}

		else if(continue_input == 4){
			printf("Traversing BST and printing out all values. \n");
			traverse_bst(root, ptr_to_head);
			print_list(ptr_to_head);
		}
	}
}


void construct_bst(node* root, int value)
{

    
        if(root == NULL) return;

	if(value < root->data){
		
		if(root->low == NULL){
			root->low = malloc(sizeof(node));
			root->low->data = value;
		}

		else{
			construct_bst(root->low, value);
		}
	}

	else if(value > root->data){
		
		if(root->high == NULL){
			root->high = malloc(sizeof(node));
			root->high->data = value;
		}

		else{
			construct_bst(root->high, value);
		}
	}
	
	else return;
}


node* search_bst(node* root, int value)
{
		
	if(root != NULL){

		if(value ==  root->data){
			return root;
		}

		else if(value < root->data){
			search_bst(root->low, value);
		}

		else if(value > root->data){
			search_bst(root->high, value);
		}
	}

	else{
	
		return NULL;
	}
}


void  delete_node(node* root, int value)
{
        if(root == NULL) return;
	//If you delete a parent node all children get deleted
	node* node_to_del;	
	node_to_del = search_bst(root, value);
	free(node_to_del);
}	

void traverse_bst(node* root, list_node** ptr_to_head)
{

        
	if(root != NULL){
		traverse_bst(root->low, ptr_to_head);
		process_node(root->data, ptr_to_head);
		traverse_bst(root->high, ptr_to_head);
	}

        else return;
}	

void process_node(int data, list_node**  ptr_to_head)
{

        if(ptr_to_head == NULL) return;

	list_node* head = malloc(sizeof(list_node));
	if(head == NULL){
		printf("Out of memory \n");
		return;
	}

	head->data = data;
	head->next = *ptr_to_head;
	*ptr_to_head = head;
}

void print_list(list_node** ptr_to_head)
{

        if(ptr_to_head == NULL) return;

	list_node* current = *ptr_to_head;

	while(current != NULL){
		printf("%d\n", current->data);
		current = current->next;
	}
}

	
node* min_value_rec(node* root)
{

	if(root->low == NULL){
		return root;
	}

	else{
		min_value_rec(root->low);
	}
}
		
