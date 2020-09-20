#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;

typedef struct stack* stackpointer;
typedef struct stack {
	element data;
	stackpointer link;
}stack;

typedef struct queue* queuepointer;

typedef struct queue {
	element data;
	queuepointer link;
}queue;
stackpointer top;
queuepointer front, rear;

void stackfile(FILE *ab);
void queuefile(FILE *ab);

int main(void) {
	FILE *ab = fopen("input[16].txt", "r");
	FILE *bc = fopen("input[16].txt", "r");
	stackfile(ab);
	queuefile(bc);
	fclose(ab);
	fclose(bc);
	return 0;
}
void stackfile(FILE *ab) {
	stackpointer input;
	element a;

	if (ab == NULL) {
		printf("file error\n");
		return;
	}
	while (fscanf(ab, "%d", &a.key) != EOF) {
		if (a.key == 0) {
			fscanf(ab, "%d", &a.key);
			input = (stack*)malloc(sizeof(stack));
			input->data.key = a.key;
			input->link = top;
			top = input;
			a.key = 0;

		}
		if (a.key == 1) {
			if (top == NULL);
			else {
				input = top;
				top = top->link;
				free(input);
			}
		}
	}
	while (top != NULL) {
		printf("%d ", top->data.key);
		input = top;
		top = top->link;
		free(input);
	}
	printf("\n");
	
}
void queuefile(FILE *ab) {
	queuepointer input1;
	element a;
	while (fscanf(ab, "%d", &a.key) != EOF) {
		if (a.key == 0) {
			fscanf(ab, "%d", &a.key);
			input1 = (queue*)malloc(sizeof(queue));
			input1->data.key = a.key;
			if (front == NULL)
				front = input1;
			else {
				rear->link = input1;
			}
			rear = input1;
		}
		if (a.key == 1) {
			if (front == NULL);
			else {
				input1 = front;
				if (front == rear) {
					front = NULL;
					free(rear);
					rear = NULL;
				}
				else {
					front = front->link;
					free(input1);
				}
			}
		}
	}

	while (front != rear) {
		printf("%d ", front->data.key);
		input1 = front;
		front = front->link;
		free(input1);
	}
	if (rear != NULL) {
		printf("%d", rear->data.key);
		free(rear);
	}
}