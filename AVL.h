#ifndef A_V_L_H
#define A_V_L_H
#include <stdlib.h>
#include <stdio.h>


typedef struct AVLNode
{
    int element;
    struct AVLNode *left, *right;
} AVLNode;

typedef struct AVL
{
    AVLNode *root;
    int size;
}AVL;

AVL *get_avl();
void insert_avl(AVL *avl, int element);
int remove_avl(AVL *avl, int element);
AVLNode *insert_avl_aux(AVLNode *root, int element);
AVLNode *get_succesor_avl(AVLNode *root);
AVLNode *remove_avl_aux(AVLNode *root, int element, int *result);
void preorder_avl(AVL *avl);
void inorder_avl(AVL *avl);
void postorder_avl(AVL *avl);
void preorder_aux_avl(AVLNode *root);
void inorder_aux_avl(AVLNode *root);
void postorder_aux_avl(AVLNode *root);
int contains_avl(AVL *avl, int element);
int contains_aux(AVLNode *root, int element);
int find_avl(AVL *avl, int element);
int find_aux_avl(AVLNode *root, int element);
int height_avl(AVL *avl);
int height_aux_avl(AVLNode *root);
int node_children_count(AVLNode *root);
AVLNode *get_unique_child_avl(AVLNode *root);
int is_leaf_avl(AVLNode *root);
void clear_avl(AVL *avl);
void clear_aux_avl(AVLNode *root);
void free_avl(AVL *avl);
int internal_count_avl(AVL *avl);
int internal_count_aux_avl(AVLNode *root);
int leaf_count_avl(AVL *avl);
int leaf_count_aux_avl(AVLNode *root);
int node_count_avl(AVL *avl);
int node_count_aux(AVLNode *root);
int get_size_val(AVL *avl);
int is_empty_avl(AVL *avl);
AVLNode *rebalance_left(AVLNode *root);
AVLNode *rebalance_right(AVLNode *root);
AVLNode *rotate_left(AVLNode *root);
AVLNode *rotate_right(AVLNode *root);

#endif