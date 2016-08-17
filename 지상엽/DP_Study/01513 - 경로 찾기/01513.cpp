#include<cstdio>
#include<queue>
#define LIM 1000007
using namespace std;

int  N, M, C;
int  mat[52][2];
int  mem[52][52][52];
bool check[52][52];

void input() {
	scanf("%d %d %d", &N, &M, &C);
	for (int i = 0; i < C; i++)
		scanf("%d %d", &mat[i][0], &mat[i][1]);
}

int isOraksil(int x, int y) {

	for (int i = 0; i < C; i++)
		if (mat[i][0] == x && mat[i][1] == y)
			return i + 1;
	
	return 0;
}

void process() {

	if (isOraksil(1, 1) )
		mem[1][1][1] = 1;
	else
		mem[1][1][0] = 1;

	queue<pair<int, int> > q;
	q.push({ 1, 1 });
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == N & y == M) continue;

		if (x != N)
		{
			if (!check[x + 1][y])
			{
				check[x + 1][y] = true;
				q.push({ x + 1,y });
			}

			int orak = isOraksil(x + 1, y);
			if (orak == 0)
				for (int i = 0; i <= C; i++) mem[x + 1][y][i] = (mem[x + 1][y][i] + mem[x][y][i]) % LIM;
			else
				for (int i = 0; i < orak; i++) mem[x + 1][y][i+1] = (mem[x + 1][y][i+1] + mem[x][y][i]) % LIM;

		}
		
		if (y != M)
		{
			if (!check[x][y+1])
			{
				check[x][y+1] = true;
				q.push({ x,y+1 });
			}

			int orak = isOraksil(x, y+1);
			if (orak == 0)
				for (int i = 0; i <= C; i++) mem[x][y+1][i] = (mem[x][y + 1][i] + mem[x][y][i])%LIM;
			else
				for (int i = 0; i < orak; i++) mem[x][y+1][i + 1] = (mem[x][y + 1][i + 1] + mem[x][y][i])%LIM;

		}
	}
}

void output() {
	for (int i = 0; i <= C; i++)
		printf("%d ", mem[N][M][i]);
}


int main() {
	input();
	process();
	output();
}
