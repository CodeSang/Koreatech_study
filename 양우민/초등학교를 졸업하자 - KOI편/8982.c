#include "header.h"

void _8982() {
	int i, j;
	int inputNum;
	int **point;
	int drain;
	int **dPoint;

	scanf("%d", &inputNum);
	point = (int**)malloc(sizeof(int*) * inputNum);
	for (i = 0; i < inputNum; i++) {
		point[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &point[i][0], &point[i][1]);
	}
	scanf("%d", &drain);
	dPoint = (int**)malloc(sizeof(int*) * drain);
	for (i = 0; i < drain; i++) {
		dPoint[i] = (int*)malloc(sizeof(int) * 4);
		for (j = 0; j < 4; j++) {
			scanf("%d", &dPoint[i][j]);
		}
	}

	for (i = 0; i < inputNum; i++) {
		printf("%d %d\n", point[i][0], point[i][1]);
		free(point[i]);
	}
	free(point);
}