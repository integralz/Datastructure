#include <stdio.h>

typedef struct threadedTree *threadedPointer;
typedef struct threadedTree {
	short int leftThread;
	threadedPointer leftChild;
	char data;
	threadedPointer rightChild;
	short int rightThread;
}threadedTree;
threadedPointer insucc(threadedPointer tree);
void tinorder(threadedPointer tree);
void insertRight(threadedPointer s, threadedPointer r);
void insertLeft(threadedPointer s, threadedPointer l);
threadedPointer getNewNode(char data);
int main() {
	threadedPointer root = getNewNode('-');
	insertLeft(root, getNewNode('A'));
	insertLeft(root->leftChild, getNewNode('B'));
	insertLeft(root->leftChild->leftChild, getNewNode('D'));
	insertLeft(root->leftChild->leftChild->leftChild, getNewNode('H'));
	insertRight(root->leftChild->leftChild->leftChild, getNewNode('I'));
	insertRight(root->leftChild->leftChild, getNewNode('E'));
	insertRight(root->leftChild, getNewNode('C'));
	insertLeft(root->leftChild->rightChild, getNewNode('F'));
	insertRight(root->leftChild->rightChild, getNewNode('G'));

	tinorder(root);
	return 0;
}
threadedPointer getNewNode(char data) {
	threadedPointer node;
	node = (threadedTree*)malloc(sizeof(threadedTree));
	node->data = data;
	node->leftThread = 0;
	node->leftChild = node;
	node->rightChild = node;
	node->rightThread = 0;

	return node;
}
void insertRight(threadedPointer s, threadedPointer r) {
	threadedPointer right;
	right = r;
	right->rightChild = s->rightChild;
	right->rightThread = 1;
	s->rightChild = right;
	s->rightThread = 0;
	right->leftChild = s;
	right->leftThread = 1;
}
void insertLeft(threadedPointer s, threadedPointer l) {
	threadedPointer left;
	left = l;
	left->leftChild = s->leftChild;
	left->leftThread = 1;
	s->leftChild = left;
	s->leftThread = 0;
	left->rightChild = s;
	left->rightThread = 1;
	
}
threadedPointer insucc(threadedPointer tree) {
	threadedPointer temp;
	temp = tree->rightChild;
	if (!tree->rightThread)
		while (!temp->leftThread)
			temp = temp->leftChild;
	return temp;
}
void tinorder(threadedPointer tree) {
	threadedPointer temp = tree;
	for (;;) {
		temp = insucc(temp);
		if (temp == tree) break;
		printf("%3c", temp->data);
	}
}