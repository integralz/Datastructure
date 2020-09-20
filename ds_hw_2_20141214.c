#include <stdio.h>

typedef struct node* nodeaddress;
typedef struct node {
	int arrival;
	nodeaddress link;
}node;

typedef struct route* routeaddress;
typedef struct route {
	int arrival;
	int start;
	int when;
	nodeaddress link;
}route;

typedef struct heap {
	int datanum;
	int array[10001];
}heap;


void insert(heap *node, int data) {
	int idx = node->datanum + 1;

	if (node->array[1] == -1) {
		node->array[1] = data;
	}

	while (idx != 1) {
		if (data < (node->array[idx / 2])) {
			node->array[idx] = node->array[idx / 2];
			node->array[idx / 2] = data;
			idx = idx / 2;
		}
		else break;
	}
	node->datanum += 1;

}//순서를 정렬하는 함수 시간복잡도가 log(n)이다.

nodeaddress makenode() {
	nodeaddress nody;
	nody = (node*)malloc(sizeof(node));
	nody->arrival = -1;
	nody->link = NULL;

	return nody;
}
routeaddress makehis() {
	routeaddress nody;
	nody = (route*)malloc(sizeof(route));
	nody->arrival = -1;
	nody->start = -1;
	nody->when = -1;
	nody->link = NULL;

	return nody;
}
int main(void) {
	heap *rank;
	int casenum, island, bridge, money1, money2, total;
	nodeaddress map;
	int start, end, point, cpoint, ccpoint, garbage;
	nodeaddress nody, c;
	int *leastmoney, *check, *readyisland;
	routeaddress history, firsthis, midhis;

	FILE* ab = fopen("input.txt", "r");
	rank = (heap*)malloc(sizeof(heap));
	rank->datanum = 0;
	rank->array[1] = -1;
	fscanf(ab, "%d", &casenum);
	leastmoney = (int*)malloc(sizeof(int)*casenum);
	firsthis = makehis();
	firsthis->start = -2;
	midhis = firsthis;
	for (int i = 0; i < casenum; i++) {
		total = 0;
		fscanf(ab, "%d %d %d %d", &island, &bridge, &money1, &money2);
		map = (node*)malloc(sizeof(node)*island);
		check = (int*)malloc(sizeof(int)*island);
		readyisland = (int*)malloc(sizeof(int)*island);
		for (int b = 0; b < island; b++) {
			map[b].link = NULL;
			check[b] = 0;
		}
		if (money2 >= money1) {
			total = money1 * island;
			leastmoney[i] = total;
			insert(rank, total);
			for (int a = 0; a < bridge; a++)
				fscanf(ab, "%d %d", &start, &end);
			if (midhis->start == -2) {
				midhis->start = -3;
				midhis->arrival = -3;
				midhis->when = i;
			}
			else {
				history = makehis();
				history->start = -3;
				history->arrival = -3;
				history->when = i;
				midhis->link = history;
				midhis = history;
			}
		}
		else {
			for (int a = 0; a < bridge; a++) {
				int start1, end1;
				fscanf(ab, "%d %d", &start, &end);
				start1 = start - 1;
				end1 = end - 1;
				if (map[start1].link == NULL) {
					nody = makenode();
					map[start1].link = nody;
				}
				else {
					for (c = map[start1].link; c->link != NULL; c = c->link);
					nody = makenode();
					c->link = nody;
				}
				nody->arrival = end1;
				nody->link = NULL;
				if (map[end1].link == NULL) {
					nody = makenode();
					map[end1].link = nody;
				}
				else {
					for (c = map[end1].link; c->link != NULL; c = c->link);
					nody = makenode();
					c->link = nody;
				}
				nody->arrival = start1;
				nody->link = NULL;
			}
			ccpoint = 0;
			cpoint = 0;
			garbage = 0;
			for (;;) {
				int pp;
				for (point = 0; point < island; point++) {
					if (check[point] == 0) {
						pp = point;
						readyisland[cpoint] = pp;
						check[point] = 1;
						cpoint++;
						garbage++;
						break;
					}
				}
				if (point == island) break;
				for (;;) {
					if (ccpoint >= cpoint)break;
					pp = readyisland[ccpoint];
					for (nody = map[pp].link; nody != NULL; nody = nody->link) {
						if (check[nody->arrival] == 0) {
							check[nody->arrival] = 1;
							readyisland[cpoint] = nody->arrival;
							cpoint++;
							total += money2;
							if (midhis->start == -2) {
								midhis->start = pp;
								midhis->arrival = nody->arrival;
								midhis->when = i;
							}
							else {
								history = makehis();
								history->start = pp;
								history->arrival = nody->arrival;
								history->when = i;
								midhis->link = history;
								midhis = history;
							}
						}
					}
					ccpoint++;

				}

			}
			total += garbage * money1;
			leastmoney[i] = total;
			insert(rank, total);
		}
		
		free(map);
	}
	history = makehis();
	midhis->link = history;
	midhis = history;
	history = firsthis;
	for (int aaa = 0; aaa < casenum; aaa++) {
		if (leastmoney[aaa] == rank->array[1]) {
			printf("%d\n", aaa + 1);
			while (history->when != aaa)
				history = history->link;
			while (history->when == aaa && history->when != -1) {
				if (history->arrival == -3) {
					history = history->link;
				}
				else {
					printf("%d %d\n", history->start + 1, history->arrival + 1);
					history = history->link;
				}
			}

		}
	}
	printf("%d\n", rank->array[1]);
		


	return 0;

}