#include<cstdio> // FAILED
#include<iostream>
using namespace std;

int N, S, M;
int eat[100002] = { 0 };
int answer = 0;

void input() {
	scanf("%d %d", &N, &S);
	scanf("%d", &M);

	for (int i = 1; i <= M; i++)
		scanf("%d", &eat[i]);
}

void process() {

	long long time_ = 1;
	long long bread = 0;

	while(true)
	{
		for (int i = 1; i <= M; i++)
		{
			if (eat[i] == 1)
				bread++;
			else if(time_ % eat[i] == 1)
				bread++;

			if (bread == N - S)
			{
				answer = i;
				return;
			}
		}
	time_++;
	}
}

void output() {
	printf("%d\n", answer);
}

int main() {
	input();
	process();
	output();
}