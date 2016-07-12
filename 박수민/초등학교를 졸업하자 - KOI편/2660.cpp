#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

/*Variables*/
int node, a, b, maxDepth;
int map[51][51];
int ck[51], leng[51], leng2[51];
queue<int> Que;

/*Functions*/
void init();
void process();
void printResult();
void init() {
	scanf("%d", &node);
	do{
		scanf("%d%d", &a, &b);
		if (a != -1) {
			map[a][b] = map[b][a] = 1;
		}
		else {
			break;
		}
	} while (true);
}

void process() {
	int count, task, depth;
	for (int i = 1; i <= node; i++) {
		depth = maxDepth = 0;
		Que.push(i);
		Que.push(0);	// ±íÀÌ
		ck[i] = 1;
		while (!Que.empty()) {
			task = Que.front();
			Que.pop();
			depth = Que.front();
			Que.pop();
			if (maxDepth <= depth)
				maxDepth = depth;
			for (int j = 1; j <= node; j++) {
				if (map[task][j] == 1 && ck[j] != 1) {
					Que.push(j);
					Que.push(depth+1);
					ck[j] = 1;
				}
			}
		}
		leng[i] = leng2[i]= maxDepth;
		for (int j = 1; j <= node; j++) {
			ck[j] = 0;
		}
	}

	sort(leng2, leng2 + node);
}

void printResult() {
	int depth = leng2[1], number = 0;
	for (int j = 1; j <= node; j++) {
		if (depth == leng2[j])
			number++;
	}
	printf("%d %d\n", depth, number);
	for (int j = 1; j <= node; j++) {
		if(depth == leng[j])
			printf("%d ", j);
	}
}

int main() {
	init();
	process();
	printResult();
	return 0;
}