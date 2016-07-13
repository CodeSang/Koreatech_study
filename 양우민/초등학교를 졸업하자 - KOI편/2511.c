#include "header.h"

void _2511() {
	int i;
	int a[10], b[10];
	int score[2] = { 0 };
	int status[10] = { 0 };

	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 10; i++) {
		scanf("%d", &b[i]);
	}

	for (i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			score[0] += 3;
			status[i] = 1;
		}
		else if (a[i] < b[i]) {
			score[1] += 3;
			status[i] = 2;
		}
		else {
			score[0]++;
			score[1]++;
		}
	}

	printf("%d %d\n", score[0], score[1]);
	if (score[0] == score[1]) {
		for (i = 9; i >= 0; i--) {
			if (status[i] == 1) {
				printf("A");
				return;
			}
			else if (status[i] == 2) {
				printf("B");
				return;
			}
		}
		printf("D");
	}
	else {
		if (score[0] > score[1]) {
			printf("A");
		}
		else {
			printf("B");
		}
	}
}