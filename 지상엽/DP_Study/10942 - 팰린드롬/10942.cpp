#include<cstdio>
#include<cstring>
using namespace std;

int N;
int mat[2001];
int mem[2002][2002];

int Go(int s, int e) {
	
	if (s == e) return 1;
	if (mem[s][e] != -1) return mem[s][e];
	if (mat[s] == mat[e])
	{
		if (e - s > 1)
			mem[s][e] = Go(s + 1, e - 1);
		else
			mem[s][e] = 1;
	}
	else
	{
		mem[s][e] = 0;
	}

	return mem[s][e];
}

int main() {
	memset(mem, -1, sizeof(mem));

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &mat[i]);
	int M;
	scanf("%d", &M);
	while (M--) // 1,000,000
	{
		int S, E;
		scanf("%d %d", &S,&E);
		printf("%d\n", Go(S, E));
	}
}