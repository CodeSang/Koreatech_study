#include<iostream>
using namespace std;

int N, K;
int mem[1001][1001];

int Go(int n, int k)
{
	if (n == 1)return 1;
	if (n == k || k == 0) return 1;
	int &temp = mem[n][k];
	if (temp != 0) return mem[n][k];	
	temp = (Go(n - 1, k - 1) + Go(n - 1, k) ) % 10007;
	mem[n][n - k] = temp;
	return temp;
}


int main() {
	cin >> N >> K;
	cout << Go(N, K)<<endl;
}