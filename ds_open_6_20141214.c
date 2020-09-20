#include <stdio.h>

void add(FILE *ab); 
void delete(FILE *ab);
void print();
typedef struct stack* stackpointer;
typedef struct stack {
	int data;
	stackpointer link;
}stack;
stackpointer start;
stackpointer node;
stackpointer current = NULL;
int a;
int nodenum=0;

int main(void) {

	FILE *ab = fopen("A.txt", "r");
	add(ab);
	FILE *bc = fopen("B.txt", "r");
	add(bc);
	print();
	FILE *cd = fopen("c.txt", "r");
	delete(cd);
	print();
}
void add(FILE *ab) {
	while (fscanf(ab, "%d", &a) != EOF) {
		node = (stack*)malloc(sizeof(stack));
		node->data = a;
		node->link = NULL;

		if (start == NULL) {
			start = node;
			nodenum++;
		}
		else {
			current->link = node;
			nodenum++;
		}
		current = node;
	}
	current->link = start;
}
void delete(FILE *ab) {
	int num = 0;
	while (fscanf(ab, "%d", &a) != EOF) {
		node = start;
		for (int i = 0; i < nodenum; i++) {
			if (node->data == a) {
				if (node == start) {
					start = start->link;
					current->link = node->link;
					free(node);
					node = current->link;
					num++;
				}
				else {
					current->link = node->link;
					free(node);
					node = current->link;
					num++;
				}
			}
			else {
				current = current->link;
				node = node->link;
			}
		}
		nodenum -= num;
		num = 0;
	}
}
void print() {
	node = start;
	while (node->link != start) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf("%d", node->data);
	printf("\n");
}