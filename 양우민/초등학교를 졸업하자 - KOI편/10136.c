#include "header.h"

void _10163() {
	int map[101][101] = { 0 };
	int result[101] = { 0 };
	int inputNum;
	int i, j, k, num = 1;
	int x, y, width, height;
	// int maxX = 0, maxY = 0, minX = 101, minY = 101;

	scanf("%d", &inputNum);
	for (i = 0; i < inputNum; i++) {
		scanf("%d %d %d %d", &x, &y, &width, &height);
		for (j = x; j < x + width; j++) {
			for (k = y; k < y + height; k++) {
				map[j][k] = num;
			}
		}
		num++;
	}

	if (inputNum) {
		for (i = 0; i < 101; i++) {
			for (j = 0; j < 101; j++) {
				if (map[i][j]) {
					result[map[i][j]]++;
				}
			}
		}
		for (i = 1; i <= inputNum; i++) {
			printf("%d\n", result[i]);
		}
	}
	else {
		printf("0\n");
	}
}