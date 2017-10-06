#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "bst.h"


int main (void)
{

	int continue_input; 
	int data;
	node* temp;

	node* root = malloc(sizeof(node));
        if(root == NULL){
            printf("Out of memory \n");
            return 1;
        }
	printf("Enter a data value for root: ");
	scanf("%d", &root->data);
	printf("\n");

	list_node* head = NULL;
	list_node** ptr_to_head = &head;
	
	while(true){
		printf("Would you like to input something into BST "
                "(0:exit, 1:input, 2:search, 3:del, 4:traverse): ");
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
			printf("Value, node deleted, and all children nodes "
                        "deleted \n");
		}

		else if(continue_input == 4){
			printf("Traversing BST and printing out all values. \n");
			traverse_bst(root, ptr_to_head);
			print_list(ptr_to_head);
                        delete_list(ptr_to_head);
		}
	}

        return;
}



		
