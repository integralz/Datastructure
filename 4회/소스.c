#include <stdio.h>

int failure[101];
int number(char string[]) {
	int num;

	for (num = 0; num < 101; num++) {
		if (string[num] != NULL);
		else { break; }
	}
	return num;
}
int nfind(char string[], char pat[]) {
	int i, j, start = 0;
	int lasts = number(string)-1;
	int lastp = number(pat)-1;
	int endmatch = lastp;
	int count = 0;

	for (i = 0; endmatch <= lasts; endmatch++, start++) {
		count++;

		if (string[endmatch] == pat[lastp])
		{
			for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++) {
				count++;
			}
			if (j == lastp)
				return count;
		}
		
	}
	return count = -1;
}
int fail(char pat[]) {
	int n = number(pat);
	int i, j, num = 0;
	failure[0] = -1;
	for (j = 1; j < n; j++) {
		num++;
		i = failure[j - 1];
		while ((pat[j] != pat[i + 1]) && (i >= 0)) {
			num++;
			i = failure[i];
		}
		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;
		else failure[j] = -1;
	}
	return num;
}

int pmatch(char string[], char pat[]) {
	int i = 0, j = 0, num = 0;
	int lens = number(string);
	int lenp = number(pat);
	while (i < lens && j < lenp) {
		num++;
		if (string[i] == pat[j]) {
			i++; j++;
		}
		else if (j == 0) i++;
		else j = failure[j - 1] + 1;
	}
	return((j == lenp) ? num : -1);
}

int main(void) {
	char string[101], want[101], failure[101];
	int c, d, e;

	printf("입력 : ");
	scanf("%s", string);
	printf("입력 : ");
	scanf("%s", want);
	
	c = nfind(string, want);
	if (c == -1) {
		printf("nfind: no\n");
	}
	else {
		printf("nfind: yes %d\n", c);
	}
	e = fail(want);
	d = pmatch(string, want);
	if (d == -1) {
		printf("kmp: no\n");
	}
	else {
		printf("kmp: yes %d\n", d+e);
	}

	return 0;
}