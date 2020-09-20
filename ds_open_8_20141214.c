#include <stdio.h>

#define MAX_TERMS 100
typedef struct treeNode* treePtr;
typedef struct treeNode {
	treePtr lchild;
	int data;
	treePtr rchild;
}treeNode;
void inorder(treePtr ptr);
void preorder(treePtr ptr);
void insert(treePtr* node, int k);
treePtr modifiedSearch(treePtr ptr, int a);

void main() {
	int i, n, A[MAX_TERMS];
	int u = 0;
	treePtr tree = NULL;

	FILE* ab = fopen("input.txt", "r");
	fscanf(ab, "%d", &n);
	while (fscanf(ab, "%d", &i) != EOF) {
		A[u] = i;
		u++;
	}

	for (i = 0; i < n; i++)
		insert(&tree, A[i]);
	inorder(tree);
	printf("\n");
	preorder(tree);
	return 0;
}

void inorder(treePtr ptr) {
	if (ptr) {
		inorder(ptr->lchild);
		printf("%d ", ptr->data);
		inorder(ptr->rchild);
	}
}
void preorder(treePtr ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void insert(treePtr* node, int k) {
	treePtr ptr, temp = modifiedSearch(*node, k);
	if (temp != NULL) {
		ptr = (treeNode*)malloc(sizeof(treeNode));
		ptr->data = k;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
		if (temp->data > k)
			temp->lchild = ptr;
		else temp->rchild = ptr;
	}
	else{
		if (*node == NULL) {
			ptr = (treeNode*)malloc(sizeof(treeNode));
			ptr->data = k;
			ptr->lchild = ptr->rchild = NULL;
			*node = ptr;
		}
	}
}
treePtr modifiedSearch(treePtr ptr, int a) {

	treePtr temp = NULL;

	while (ptr != NULL) {
		if (ptr->data == a)
			return NULL;
		else if (ptr->data > a) {
			temp = ptr;
			ptr = ptr->lchild;
		}
		else {
			temp = ptr;
			ptr = ptr->rchild;
		}
	}

	return temp;
}
