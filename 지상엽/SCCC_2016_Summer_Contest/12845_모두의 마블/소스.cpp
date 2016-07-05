#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int mat[1001];

	int max = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> mat[i];
		sum += mat[i];
		if (max < mat[i])
			max = mat[i];
	}

	sum += max *(N - 2);

	cout << sum << endl;
}