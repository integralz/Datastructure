#include <stdio.h>

typedef struct {
	int col;
	int row;
	int value;
}term;

void read(term* b) {
	int i = 1;
	int row1 = 0;
	int col1 = 0;
	FILE * ab = fopen("a[3].txt", "r");

	if (ab == NULL) {
		printf("file error\n");
		return;
	}
	fscanf(ab, "%d", &b[0].row);
	fscanf(ab, "%d", &b[0].col);
	while (fscanf(ab, "%d", &b[i].value) != EOF) {
		if (b[i].value == 0) {
			col1++;
			if (col1 > (b[0].col - 1)) {
				col1 = col1 - b[0].col;
				row1++;
			}
		}
		else {
			b[i].row = row1;
			b[i].col = col1;
			col1++;
			if (col1 > (b[0].col - 1)) {
				col1 = col1 - b[0].col;
				row1++;
			}
			i++;


		}
		b[0].value = i - 1;
	}

}
void transpose(term* a, term *b) {
	int start[100], number[100];
	int c, i;
	c = a[0].row;
	b[0].row = a[0].col;
	b[0].col = c;
	b[0].value = a[0].value;
	for (i = 0; i < a[0].col; i++)
		start[i] = 0;
	for (i = 1; i <= a[0].value; i++)
		start[a[i].col]++;
	for (i = 0; i < a[0].col; i++)
		number[i] = 0;
	for (i = 1; i <= a[0].value; i++) {
		int k = 0;
		for (int u = 0; u < a[i].col; u++) {
			k += start[u];
		}
		k += number[a[i].col];
		b[k + 1].col = a[i].row;
		b[k + 1].row = a[i].col;
		b[k + 1].value = a[i].value;
		number[a[i].col]++;
	}

}
int main(void) {
	term num[100];
	term num1[100];
	read(num);
	transpose(num, num1);

	for (int i = 0; i <= 28; i++) {
		printf("%d %d %d\n", num1[i].row, num1[i].col, num1[i].value);
	}

	return 0;
}