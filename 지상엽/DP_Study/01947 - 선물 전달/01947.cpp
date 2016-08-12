#include<iostream>
#define LIMIT  1000000000
using namespace std;

int main() {
	unsigned long long mem[2] = { 0 };
	int N;
	cin >> N;
	mem[0] = 1;
	for (int i = 3; i <= N; i++)
		mem[i%2] = (i-1) * (mem[(i - 1)%2] + mem[(i - 2)%2]) % LIMIT;
	cout << mem[N%2] << endl;
}