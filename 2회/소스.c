#include <stdio.h>

typedef struct _point {
	int coe;
	int rank;
}point;
void readPoly(char* a, point* b, int* num) {
	int i = 0;
	FILE * ab = fopen(a, "r");

	if (ab == NULL) {
		printf("file error\n");
		return;
	}
		

	while (fscanf(ab, "%d %d", &b[*num + i].coe, &b[*num + i].rank) != EOF) {

		i++;
		
	}
	*num = *num + i;
}
int padd(point* b, int end1, int end2, int count) {
	int start1 = count;
	int start2 = end1 + 1;
	int new = end2 + 1;
	for (; start1 <= end1 && start2 <= end2;)
	{
		if (b[start1].rank == b[start2].rank) {
			b[new].rank = b[start1].rank;
			b[new].coe = b[start1].coe + b[start2].coe;
			start1++;
			start2++;
			new++;
		}
		else if (b[start1].rank > b[start2].rank)
		{
			b[new].rank = b[start1].rank;
			b[new].coe = b[start1].coe;
			new++;
			start1++;
		}
		else {
			b[new].rank = b[start2].rank;
			b[new].coe = b[start2].coe;
			new++;
			start2++;
		}
	}
	if (start1 > end1) {
		for (start2; start2 <= end2; start2++) {
			b[new].rank = b[start2].rank;
			b[new].coe = b[start2].coe;
			new++;
		}
	}
	else if (start2 > end2) {
		for (start1; start1 <= end1; start1++) {
			b[new].rank = b[start1].rank;
			b[new].coe = b[start1].coe;
			new++;
		}
	}
	return new;
}
void printpoly(point *b, int start, int end) {
	for (start; start <= end; start++) {
		printf("(%d,%d)", b[start].coe, b[start].rank);
	}
}
int main(void) {
	point poly[100];
	int count = 0;
	int end1, end2, end3;
	int plus;
	readPoly("A.txt", poly, &count);
	end1 = count - 1;

	readPoly("B.txt", poly, &count);
	end2 = count - 1;

	count = padd(poly, end1, end2, 0);
	plus = padd(poly, end1, end2, 0);
	
	readPoly("C.txt", poly, &count);
	end3 = count - 1;
	count = padd(poly, plus-1, end3, end2+1);

	printpoly(poly, end3 + 1, count - 1);


	return 0;
}