#include <stdio.h>
#include <stdlib.h>

#define	COUNT 				4

#define	IN_ORDER			0
#define PRE_ORDER			1
#define POST_ORDER			2
#define REVERSE_IN_ORDER	3
#define DEFAULT_ORDER		0

struct node  
{ 
  int data; 
  struct node *left; 
  struct node *right; 
};

typedef struct node node_t;


void new_node(node_t** tree, int data) {

	if ((*tree) == NULL) {
		//printf("Tree null, malloccing.\n");
		(*tree) = malloc(sizeof(node_t));
		(*tree)->data = data;
		//printf("Temp->data = %d\n", (*tree)->data);
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
}

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtilRev(node_t *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtilRev(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtilRev(root->left, space); 
} 

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(node_t *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process left child 
    print2DUtil(root->left, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process right child first 
    print2DUtil(root->right, space); 
} 

// Function to print binary tree in 2D 
// It does preorder traversal 
// Used to make a copy of the tree
void print2DUtilPre(node_t *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtilPre(root->left, space); 
  
    // Process right child first 
    print2DUtilPre(root->right, space); 
} 
  
// Function to print binary tree in 2D 
// It does preorder traversal 
// Used to delete tree
void print2DUtilPost(node_t* root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process left child 
    print2DUtilPost(root->left, space); 
  
    // Process right child first 
    print2DUtilPost(root->right, space); 

    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
}

void delete_tree(node_t** root) {
	if ((*root) == NULL)
		return;
	
	delete_tree(&((*root)->left));
	delete_tree(&((*root)->right));
	
	printf("Freeing %d.\n", (*root)->data);
	free((*root));
	(*root) = NULL;
}

void copy_tree(node_t* root, node_t** copy) {
	if (root == NULL)
		return;
	
	printf("Copying node %d\n", root->data);
	new_node(copy, root->data);

	copy_tree(root->left, &((*copy)->left));
	copy_tree(root->right, &((*copy)->right));

}

// Wrapper over print2DUtil() 
void print2D(node_t *root, int type) 
{ 
   // Pass initial space count as 0
   if (type == IN_ORDER) 
   	 print2DUtil(root, 0); 
   else if (type == PRE_ORDER) 
   	 print2DUtilPre(root, 0); 
   else if (type == POST_ORDER) 
   	 print2DUtilPost(root, 0); 
   else if (type == REVERSE_IN_ORDER) 
   	 print2DUtilRev(root, 0); 
} 

int find_size(node_t* root) {
	int sizel = 0;
	int sizer = 0;

	if (root == NULL)
		return 0;

    // Process left child 
    sizel = 1 + find_size(root->left); 
  
    // Process right child first 
    sizer = 1 + find_size(root->right); 

    return ((sizel > sizer)?sizel:sizer);
}

void main() {
	/* build tree structure, insert, delete, sort */
	node_t* tree = NULL;

	print2D(tree, IN_ORDER);

	new_node(&tree, 1);

	printf("Reversed inorder:\n");
	print2D(tree, DEFAULT_ORDER);
	printf("-------------------:\n");

	new_node(&(tree->left), 1);
	new_node(&(tree->right), 2);

	printf("Reversed inorder:\n");
	print2D(tree, DEFAULT_ORDER);
	printf("-------------------:\n");

	new_node(&(tree->left->left), 4);
	new_node(&(tree->right->left), 5);
	new_node(&(tree->left->right), 3);
	new_node(&(tree->right->right), 17);

	// Reversed inorder traversal
	printf("Reversed inorder:\n");
	print2D(tree, DEFAULT_ORDER);
	printf("-------------------:\n");

	// Inorder traversal
	printf("In order:\n");
	print2D(tree, IN_ORDER);
	printf("-------------------:\n");

	// Preorder traversal
	printf("Pre order:\n");
	print2D(tree, PRE_ORDER);
	printf("-------------------:\n");

	// Post traversal
	printf("Post order:\n");
	print2D(tree, POST_ORDER);
	printf("-------------------:\n");

	// Rev inorder traversal
	printf("Reverse inorder:\n");
	print2D(tree, DEFAULT_ORDER);
	printf("-------------------:\n");

	printf("Size of tree is: %d\n\n\n", find_size(tree));

	// Make a copy of the tree and traverse the copy to verify it
	node_t* copy = NULL;
	copy_tree(tree, &copy);
	// Rev inorder traversal
	printf("COPY - Reverse inorder:\n");
	print2D(copy, DEFAULT_ORDER);
	printf("-------------------:\n");

	// Deletion of trees
	delete_tree(&tree);
	printf("\n");
	delete_tree(&copy);
	if (tree == NULL)
		printf("Deleted main tree.\n");
	if (copy == NULL)
		printf("Deleted copy tree.\n");

}