#include "AVL.h"

AVL *get_avl(){
    AVL *avl = (AVL *) malloc(sizeof(AVL));
    if(avl == NULL){
        printf("%s\n", "Could not allocate memory for avl data structure");
        exit(EXIT_FAILURE);
    }
    avl->root = NULL;
    avl->size = 0;
    return avl;
}

void insert_avl(AVL *avl, int element){
    avl->root = insert_avl_aux(avl->root, element);
}

AVLNode *insert_avl_aux(AVLNode *root, int element){
    if(root == NULL){
        root = (AVLNode *)malloc(sizeof(AVLNode));
        root->left = root->right = NULL;
        return root;
    }
    if( element < root->element){
        root->left = insert_avl_aux(root->left, element);
        return rebalance_left(root->left);
    }else if(element > root->element){
        root->right = insert_avl_aux(root->right, element);
        return rebalance_right(root->right);
    }
}

AVLNode *get_succesor_avl(AVLNode *root){
    if(root->left == NULL){
        return root;
    }else{
        return get_succesor_avl(root->left);
    }
}