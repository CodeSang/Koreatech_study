#include<iostream>
using namespace std;

int N;
int mem[1000011];

int main() {
	mem[0] = 1;
	cin >> N;

	for (int i = 0; (1 << i) <= N; i++)
	{
		int k = (1 << i);
		for (int j = k; j <= N; j++)
			mem[j] = (mem[j] + mem[j - k]) % 1000000000;
	}
	cout << mem[N] << endl;
}