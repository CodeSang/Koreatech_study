#include<iostream>
#include<algorithm>
using namespace std;


int N;
int mat[1511][1511];
int dp[1511][1511];


int Go(int src, int dst) {
	if (src >= dst)return 0;
	int &temp = dp[src][dst];
	if (temp != 0) return temp;
	temp = mat[src][src+1] + Go(src + 1, dst);
	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];

	int value = Go(0, N - 1);
	cout << value << endl;
}