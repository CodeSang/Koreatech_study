#include<iostream>
#include<algorithm>
using namespace std;

int M, N;
int minA  = INT32_MAX, sumA;
bool prime[1000000] = { false };

void input() {
	cin >> M >> N;
}

void proccess() {

	prime[1] = true;

	for (int i = 2; i <= N; i++)
	{
		if (!prime[i])
			for (int j = 2; j*i <= N; j++)
			{
				prime[j*i] = true;
			}
	}

	for (int i = M; i <= N; i++)
	{
		if (!prime[i])
		{
			minA = min(minA, i);
			sumA += i;
		}
	}
}

void output() {
	if (sumA == 0){
		cout << "-1" << endl;
		return;
	}
	cout << sumA << endl;
	cout << minA << endl;
}

int main() {
	input();
	proccess();
	output();
}