#ifndef BST_AB_OCT2017_H_
#define BST_AB_OCT2017_H_

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
void delete_list(list_node** ptr_to_head);
node* inorder_successor(node* root);
node* min_value_rec(node* root);


#endif //BST_AB_OCT2017_H_
