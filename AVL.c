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
    avl->size++;
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

int remove_avl(AVL *avl, int element){
    int result;
    avl->root = remove_avl_aux(avl->root, element, &result);
    avl->size--;
    return result;
}

AVLNode *remove_avl_aux(AVLNode *root, int element, int *result){
    if(root == NULL){
        printf("%s\n", "Can't remove element that is not in the AVL data structure");
        exit(EXIT_FAILURE);
    }
    if(element < root->element){
        root->left = remove_avl_aux(root->left, element, result);
        return rebalance_right(root);
    }else if(element > root->element){
        root->right = remove_avl_aux(root->right, element, result);
        return rebalance_left(root);
    }else{
        *result = root->element;
        if(is_leaf_avl(root)){
            free(root);
            return NULL;
        }
        if(node_children_count(root) == 1){
            AVLNode *child = get_unique_child_avl(root);
            free(root);
            return child;
        }else{
            AVLNode *succ = get_succesor_avl(root->right);
            int temp = succ->element;
            succ->element = root->element;
            root->element = temp;
            root->right = remove_avl_aux(root->right, element, result);
            return rebalance_left(root);
        }
    }
}

int is_leaf_avl(AVLNode *root){
    return root->left == NULL && root->right == NULL;
}

int node_children_count(AVLNode *root){
    return (root->left == NULL ? 0 : 1) + (root->right == NULL ? 0
                                                            : 1);
}

AVLNode *get_unique_child_avl(AVLNode *root){
    return root->left == NULL ? root->right : root->left;
}


void preorder_avl(AVL *avl){
    printf("%s", "[");
    preorder_aux_avl(avl->root);
    printf("%s\n", "]");
}

void inorder_avl(AVL *avl){
    printf("%s", "[");
    inorder_aux_avl(avl->root);
    printf("%s\n", "]");
}

void postorder_avl(AVL *avl){
    printf("%s", "[");
    postorder_aux_avl(avl->root);
    printf("%s\n", "]");
}

void preorder_aux_avl(AVLNode *root){
    if(root == NULL)
        return;
    printf("%i,", root->element);
    preorder_aux_avl(root->left);
    preorder_aux_avl(root->right);
}

void inorder_aux_avl(AVLNode *root){
    if(root == NULL)
        return;
    inorder_aux_avl(root->left);
    printf("%i,", root->element);
    inorder_aux_avl(root->right);
}

void postorder_aux_avl(AVLNode *root){
    if(root == NULL)
        return;
    postorder_aux_avl(root->left);
    postorder_aux_avl(root->right);
    printf("%i,", root->element);
}

int contains_avl(AVL *avl, int element){
    return contains_aux(avl->root, element);
}

int contains_aux(AVLNode *root, int element){
    if(root == NULL)
        return 0;
    if(root->element == element)
        return 1;
    if(element > root->element){
        return contains_aux(root->right, element);
    }else if(element < root->element){
        return contains_aux(root->left, element);
    }
}

int find_avl(AVL *avl, int element){
    return find_aux_avl(avl->root, element);
}

int find_aux_avl(AVLNode *root, int element){
    if(root == NULL){
        printf("%s\n", "Could not locate element in AVL data structure");
        exit(EXIT_FAILURE);
    }
    if(root->element == element){
        return root->element;
    }
    if(element < root->element){
        return find_aux_avl(root->left, element);
    }else if (element > root->element){
        return find_aux_avl(root->right, element);
    }
}