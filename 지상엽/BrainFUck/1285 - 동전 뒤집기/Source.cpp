#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int mat[21][21];

int minCnt = 0;
void input() {

	scanf("%d", &N);
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			char temp;
			scanf(" %1c", &temp);
			if (temp == 'H')
			{
				mat[i][j] = 1;
			}
			else
			{
				mat[i][j] = -1;
				cnt++;
			}
		}

	minCnt = cnt;

}

void cntNow(int n) {
	int cnt = 0; 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (mat[i][j] == -1)
				cnt++;	

	minCnt = min(minCnt, cnt);
}

void flip(int n) {

	if (n >= N)
	{
		int totalCnt = 0;

		for (int i = 0; i < N; i++)
		{
			int cnt = 0;
			for (int j = 0; j < N; j++)
			{
				if (mat[i][j] == -1)
					cnt++;
			}

			if (cnt > N / 2)
			{
				totalCnt = totalCnt + ( N  - cnt);
			}
			else
			{
				totalCnt = totalCnt + cnt;
			}
		}

		minCnt = min(minCnt, totalCnt);
		return;
	}
	
	flip(n + 1);

	for (int i = 0; i < N; i++)
		mat[i][n] *= -1;

	flip(n + 1);

}

void process() {
	flip(0);
}

void output() {
	printf("%d\n", minCnt);
}

int main() {
	input();
	process();
	output();
}