#include <stdio.h>

/*Variables*/
int x1, y1, x2, y2;
int map[100][100];
int count;

/*Functions*/
void process() {
	for (int i = 1; i <= 4; i++) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				if (map[j][k] != 1)
				{
					map[j][k] = 1;
					count++;
				}
			}
		}
	}
	printf("%d", count);
}

int main() {
	process();
	return 0;
}