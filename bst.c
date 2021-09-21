#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "bst.h"

struct node* init_node(node* bst_node, int value)
{
    if(bst_node == NULL){
        bst_node = (node*) malloc(sizeof(node));
        if(bst_node == NULL){
            fprintf(stderr, "Could not allocate memory\n");
            return NULL;
        }
    }        
    
    if(bst_node != NULL){
        bst_node->data = value;
        bst_node->low = NULL;
        bst_node->high = NULL;
    }

	else{
		fprintf(stderr, "For some reason the pointer is still NULL!\n");
		return NULL;
	}

    return bst_node;
}


//Function for constructing a bst recursively. 
//A pointer to root needs to be passed to the function, the function will allocate\
it automatically if value of root is NULL. 
void construct_bst(node* root, int value)
{
	if(root == NULL){
		root = init_node(root, value);
		return; 
	}
    
    else if(root != NULL){

	    if(value < root->data){
		
		    if(root->low == NULL){
                root->low = init_node(root->low, value);    
		    }
		    else{
			    construct_bst(root->low, value);
		    }
	    }   

	    else if(value > root->data){
		
	       if(root->high == NULL){
		       root->high = init_node(root->high, value);
		    }
		    else{
			    construct_bst(root->high, value);
		    }
	   }
	
	    else return;
    }

    return;

}


/*
//Another implementation of construct_bst, the code lookes cleaner\
but runs a lot slower most probably because it has to access memory\
for every recursive call.
struct node* construct_bst(node* root, int value, int position_of_data)
{
    if(root == NULL){
        return init_node(root, value, position_of_data);  
    }

    else if(value < root->data){
        root->low = construct_bst(root->low, value, position_of_data);
    }

    else if(value > root->data){
        root->high = construct_bst(root->high, value, position_of_data);
    }

    return root;
}
*/


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
	

