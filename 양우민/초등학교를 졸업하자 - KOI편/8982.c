#include "header.h"

void _8982() {
	int i;
	int inputNum;
	int **point;

	scanf("%d", &inputNum);
	point = (int**)malloc(sizeof(int*) * inputNum);
	for (i = 0; i < inputNum; i++) {
		point[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &point[i][0], &point[i][1]);
	}
	for (i = 0; i < inputNum; i++) {
		printf("%d %d\n", point[i][0], point[i][1]);
		free(point[i]);
	}
	free(point);
}