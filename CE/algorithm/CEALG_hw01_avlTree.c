#define _CRT_SECURE_NO_WARNINGS  // For Visual Studio
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    struct AVLNode* left_child;
    struct AVLNode* right_child;
} AVLNode;

/*******************************************
 *	Rotation functions
 *******************************************/
// LL rotation
AVLNode* rotate_LL(AVLNode* parent) {
    AVLNode* child = parent->left_child;
    parent->left_child = child->right_child;
    child->right_child = parent;

    return child;
}

// RR rotation
AVLNode* rotate_RR(AVLNode* parent) {
    AVLNode* child = parent->right_child;
    parent->right_child = child->left_child;
    child->left_child = parent;

    return child;
}

// RL rotation
AVLNode* rotate_RL(AVLNode* parent) {
    AVLNode* child = parent->right_child;
    parent->right_child = rotate_LL(child);

    return rotate_RR(parent);
}

// LR rotation
AVLNode* rotate_LR(AVLNode* parent) {
    AVLNode* child = parent->left_child;
    parent->left_child = rotate_RR(child);

    return rotate_LL(parent);
}

/******************************************
 *	Balance index computation function
 *******************************************/
int get_height(AVLNode* node) {
    int height = 0;
    int left_height = -1, right_height = -1;
    if (node != NULL) {
        left_height = get_height(node->left_child);
        right_height = get_height(node->right_child);
        height = 1 + (left_height > right_height ? left_height : right_height);
    }

    return height;
}

int get_height_diff(AVLNode* node) {
    if (node == NULL)
        return 0;
    return get_height(node->left_child) - get_height(node->right_child);
}

/*******************************************
 *	Rebalance function
 ********************************************/
AVLNode* rebalance(AVLNode** node) {
    int height_diff = get_height_diff(*node);
    if (height_diff > 1) {
        if (get_height_diff((*node)->left_child) > 0)
            *node = rotate_LL(*node);
        else
            *node = rotate_LR(*node);
    }
    else if (height_diff < -1) {
        if (get_height_diff((*node)->right_child) < 0)
            *node = rotate_RR(*node);
        else
            *node = rotate_RL(*node);
    }

    return *node;
}

/*******************************************
 *	Insertion function
 ********************************************/
AVLNode* avl_add(AVLNode** root, int new_key) {
    if (*root == NULL) {
        *root = (AVLNode*)malloc(sizeof(AVLNode));
        if (*root == NULL) {
            printf("Fail to Memory Allocation!!\n");
            exit(1);
        }
        (*root)->data = new_key;
        (*root)->left_child = NULL;
        (*root)->right_child = NULL;
    }
    else if (new_key < (*root)->data) {
        (*root)->left_child = avl_add(&((*root)->left_child), new_key);
        *root = rebalance(root);
    }
    else if (new_key > (*root)->data) {
        (*root)->right_child = avl_add(&((*root)->right_child), new_key);
        *root = rebalance(root);
    }
    else {
        printf("Error: Try to insert the duplicate key!\n");
        exit(1);
    }

    return *root;
}

/*******************************************
 *	Search function
 *******************************************/
AVLNode* avl_search(AVLNode* node, int key) {
    if (node == NULL) return NULL;

    printf("%d -> ", node->data);

    if (key == node->data) {
        printf("Found the key %d! \n", key);
        return node;
    }
    else if (key < node->data)
        return avl_search(node->left_child, key);
    else
        return avl_search(node->right_child, key);
}

/*******************************************
 *	Deletion function (Assignment)
 *******************************************/
AVLNode* avl_delete(AVLNode** root, int key) {
	if (*root == NULL) {
		printf("Error: Root is NULL\n");
		return NULL;
	}

	if (key == (*root)->data) {
        //말단노드
		if (((*root)->left_child == NULL) && ((*root)->right_child == NULL)) {	
			free(*root);
			*root = NULL;
			
			return NULL;
		}
		else if ((*root)->left_child == NULL) {	
			AVLNode* tmp = (*root)->right_child;
			free(*root);
			*root = tmp;
			*root = rebalance(root);
			
			return *root;
		}
		else if ((*root)->right_child == NULL) {	
			AVLNode* tmp = (*root)->left_child;
			free(*root);
			*root = tmp;
			*root = rebalance(root);

			return *root;
		}
		else {	// 2개의 자식 존재

			//오른쪽 서브트리에서 가장 작은 값을 root로
			AVLNode* tmp = (*root)->right_child;
			while (tmp->left_child != NULL)
				tmp = tmp->left_child;

			(*root)->data = tmp->data;
			(*root)->right_child = avl_delete(&((*root)->right_child), tmp->data);
			*root = rebalance(root);

			return *root;
		}
	}
	else if (key < (*root)->data) {
		return avl_delete(&((*root)->left_child), key);
	}
	else if (key > (*root)->data) {
		return avl_delete(&((*root)->right_child), key);
	}
	else {
		printf("Error: Try to delete not existing key!\n");
		exit(1);
	}

	return *root;
}




/*******************************************
 *	Main Function
 *******************************************/
int main(void) {
    AVLNode* root = NULL;

    printf("Assignment #1. AVL 트리의 삭제 연산 20190231 김시현 \n\n");
	int arr[] = {8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, 12};

	for (int i = 0; i < 12; i++) {
		avl_add(&root, arr[i]);
	}

	printf("\nInitial AVL Tree\n");
	avl_search(root, 12);

	printf("\nDelete 12\n");
	avl_delete(&root, 12);
	avl_search(root, 12);

	printf("\nAdd 20\n");
    avl_add(&root, 20);
	avl_search(root, 20);

    for (int i = 0; i < 12; i++) {
        printf("\nSearch %d\n", arr[i]);
        avl_search(root, arr[i]);
    }

	printf("\nDelete 20\n");
	avl_delete(&root, 20);
	avl_search(root, 20);

	return 0;
}
