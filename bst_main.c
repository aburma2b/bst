#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "bst.h"

static node* root = NULL;
static node** root_addr = &root;
static void input_bst(node** root_addr, int data);


int main (void)
{

	int continue_input; 
	int data;
	node* temp;
	list_node* head = NULL;
	list_node** ptr_to_head = &head;
	
	while(true){

		printf("Would you like to input something into BST "
                "(0:exit, 1:input, 2:search, 3:del, 4:traverse): ");
		scanf("%d", &continue_input);

		if(continue_input == 0) {
            printf("Exiting\n");
			break;
		} 
                 
		else if(continue_input == 1){
			printf("Enter an integer: ");
			scanf("%d", &data);
			input_bst(root_addr, data);
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
                        // *****BUG: Traversing and printing does something weird \
                        after a node is deleted from the BST.******
			traverse_bst(root, ptr_to_head);
			print_list(ptr_to_head);
                        delete_list(ptr_to_head);
                        head = NULL;
                        ptr_to_head = &head;
		}
	}

        return 0;
}

static void input_bst(node** root_addr, int data)
{
   if(root == NULL){
	   *root_addr = init_node(root, data);
	   return;
   }

   else{
	   construct_bst(root, data);
	   return;
   }

   return;
}
		
