#include<iostream>
using namespace std;
int N;
long long leftA[100002] = { 0 };
long long rightA[100002] = { 0 };
int cross[100002] = { 0 };

int minIdx = 0;
long long minDis = INT64_MAX;

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> cross[i];

	for (int i = 2; i <= N; i++)
	{
		cin >> leftA[i];
		leftA[i] += leftA[i - 1];
	}

	for (int i = 1; i < N; i++)
		cin >> rightA[i];

	for (int i = N-1; i > 0; i--)
		rightA[i] += rightA[i+1];;
}

void process() {
	for (int i = 1; i <= N; i++)
	{
		long long temp = leftA[i] + cross[i] + rightA[i];
		if (temp < minDis)
		{
			minIdx = i;
			minDis = temp;
		}
	}
}

void output() {
	cout << minIdx << " " << minDis << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	input();
	process();
	output();
}