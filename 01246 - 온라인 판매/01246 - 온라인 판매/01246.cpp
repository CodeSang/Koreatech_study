#include<iostream>
#include<algorithm>
using namespace std;


int N, M;
int P[1001];
long long answer = 0;
long long answeridx = 0;


void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> P[i];
}

void output() {

	sort(P, P + M);

	for (int i = 0; i < M; i++)
	{
		long long sum = 0;
		if (N > M - i)
			sum = P[i] * (M - i);
		else
			sum = P[i] * N;

		if (answer < sum)
		{
			answer = sum;
			answeridx = P[i];
		}
	}

	cout << answeridx <<" "<< answer << endl;
}


int main() {
	input();
	output();
}