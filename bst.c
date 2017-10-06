#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "bst.h"

//Function for constructing a bst recursively. 
//A pointer to an already allocated root needs to be passed. 
void construct_bst(node* root, int value)
{

    if(root != NULL){

	if(value < root->data){
		
		if(root->low == NULL){
			root->low = malloc(sizeof(node));
                        if(root->low == NULL){
                            printf("Could not allocate memory");
                            return;
                        }
			root->low->data = value;
		}
		else{
			construct_bst(root->low, value);
		}
	}

	else if(value > root->data){
		
		if(root->high == NULL){
			root->high = malloc(sizeof(node));
                        if(root->high == NULL){
                           printf("Could not allocate me");
                           return;
                        }
			root->high->data = value;
		}
		else{
			construct_bst(root->high, value);
		}
	}
	
	else return;
    }

    else{
        printf("Root passed to function was null. BST could not be constructed");
        return;
    }
}


//Function to recursively  search the bst to see \
if the passed value is already in the tree.
//A root to a bst needs to be passed to the function.
//This functions returns the node which holds the value requested. 
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
    
	else return NULL;
    }

    else return NULL;
}


//Function to delete a node with the passed value.
//This functions calls the search function.
//Frees the node returned by the search function.
void  delete_node(node* root, int value)
{
    if(root != NULL){
	//If you delete a parent node all children get deleted.
	node* node_to_del;	
	node_to_del = search_bst(root, value);
 	free(node_to_del);
    }

    else return;
}	


//Function recursively in-order traverses bst.
//After the function is finished a linked-list\
is formed which holds all the values of the bst.
//Each linked list should reflect exactly how a bst was contructed and in \
in what order values were input into the bst.
//*****BUG: Traversing and printing does something weird after a node is\
deleted from the BST.******
void traverse_bst(node* root, list_node** ptr_to_head)
{
        
    if(root != NULL){
	traverse_bst(root->low, ptr_to_head);
	process_node(root->data, ptr_to_head);
	traverse_bst(root->high, ptr_to_head);
    }

    else return;
}	


//Function is passed a value, which is then added on to a linked list.
//A new node is created for each data value. Each new node becomes the new head.
//A pointer to a pointer is passed to the function because \
whenever a new node is added, the new node becomes the head.
void process_node(int data, list_node**  ptr_to_head)
{

    if(ptr_to_head != NULL){

        list_node* head = malloc(sizeof(list_node));
	if(head == NULL){
		printf("Out of memory \n");
		return;
	}

	head->data = data;
	head->next = *ptr_to_head;
	*ptr_to_head = head;
    }

    else return;
}


//Simple print list function. Iterated over the linked list \
and prints it out.
void print_list(list_node** ptr_to_head)
{

    if(ptr_to_head != NULL){

	list_node* current = *ptr_to_head;

	while(current != NULL){
	    printf("%d\n", current->data);
	    current = current->next;
	}
    }

    else return;
}

//Iterates over all linked list nodes and deletes them
void delete_list(list_node** ptr_to_head)
{

    if(ptr_to_head != NULL){

       list_node* current = *ptr_to_head;
       list_node* next = NULL;

       while(current !=  NULL){
           next = current->next;
           free(current);
           current = next;
        }

    }

    else return;
}

           
//In a bst the left most node is alwayd the lowest value.
//Recursively finds the left most node and returns it.
node* min_value_rec(node* root)
{
    if(root != NULL){
        if(root->low == NULL){
		return root;
	}

	else{
		min_value_rec(root->low);
	}
    }

    else return NULL;
}
	

