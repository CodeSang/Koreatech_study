#include <iostream>
#include<algorithm>
using namespace std;


int N;
int mat[1001];
int dp1[1001];
int dp2[1001];


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> mat[i];

	fill(dp1, dp1 + N, 1);
	fill(dp2, dp2 + N, 1);

	for(int i = 0 ; i < N ; i++)
	{ 
		for (int j = 0; j < i; j++)
		{
			if (mat[i] > mat[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (mat[i] > mat[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}

	int value = 0;
	for (int i = 0; i < N; i++)
	{
		value = max(value, dp1[i] + dp2[i] - 1);
	}
	cout << value<<endl;
}