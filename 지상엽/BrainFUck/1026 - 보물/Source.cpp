#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> A;
vector<int> B;

int main() {
	int N;
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	long long sum = 0;
	for (int i = 0; i < N; i++)
		sum += A[i] * B[N-i-1];
	cout << sum << endl;
}