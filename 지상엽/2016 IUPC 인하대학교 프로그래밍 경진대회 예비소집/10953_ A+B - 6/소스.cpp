#include<cstdio>

int main() {
	int T;
	int x, y;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%*c%d", &x, &y);
		printf("%d\n", x + y);
	}
}