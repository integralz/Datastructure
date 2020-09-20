#include <stdio.h>
#include <time.h>

void sort(int* a, int n) {
	int c = 0, d = -1;
	for (int b = 1; b < n; b++)
	{
		c = a[b];

		for (int i = 0; i < b; i++) {
			if (a[i] < a[b]) {
				d = i;
			}
		}
		for (int h = 0; h < b - d - 1; h++) {
			a[b - h] = a[b - h - 1];
		}
		a[d + 1] = c;
	}
	return;
}

int main(void)
{
	int rt;
	int input[10];
	int g = 0, c = 0, d = -1;
	int a[100];
	double duration;
	clock_t start;

	FILE * ab = fopen("lab1.data", "r");

	if (ab == NULL)
	{
		printf("파일이 없음\n");
	}
	while (fscanf(ab, "%d", &rt) != EOF) {
		printf("%d ", rt);
		input[g] = rt;
		g++;
	}
	printf("\n");

	sort(input, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d ", input[i]);
	}
	fclose(ab);
	if (ab == EOF)
	{
		printf("파일 닫기 오류\n");
	}

	printf("\n     n	repetitions	times\n");

	for (int i = 0; i <= 100; i += 10) {

		int rep = 100000;

		for (int n = 0; n < i; n++) {
			a[n] = i - n;
		}
		start = clock();
		for (int k = 0; k < rep/(i+1); k++) {
			sort(a, i);
		}
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		printf("%6d  %d		 %f\n", i,rep/(i+1), duration);

	
	}
	return 0;
}