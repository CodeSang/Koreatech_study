#include<iostream>
using namespace std;

int base[101] = { 0 };
int mat[101][51] = { 0 };
int cnt = 0;
bool check[101] = { false };

int main() {
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> base[i];

	int caseNum;
	cin >> caseNum;

	for (int j = 0; j < caseNum; j++)
		for (int i = 0; i < N; i++)
			cin >> mat[j][i];

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < caseNum; i++)
		{
			if (check[i])
				continue;

			bool checkA = true;

			for (int k = 0; k < N; k++)
			{
				if (base[(k + j) % N] != mat[i][k])
				{
					checkA = false;
					break;
				}
			}

			if (checkA) {
				check[i] = true;
				cnt++;
			}
		}
	}

	// base 뒤집기.
	// 1 오른쪽 2 위 3 왼쪽 4 아래쪽

	int base_temp[101];

	for (int i = N - 1; i >= 0; i--)
	{
		switch (base[i])
		{
		case 1:
			base_temp[N - i - 1] = 3;
			break;
		case 2:
			base_temp[N - i - 1] = 4;
			break;
		case 3:
			base_temp[N - i - 1] = 1;
			break;
		case 4:
			base_temp[N - i - 1] = 2;
			break;
		default:
			break;
		}
	}

	swap(base, base_temp);

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < caseNum; i++)
		{
			if (check[i])
				continue;

			bool checkA = true;

			for (int k = 0; k < N; k++)
			{
				if (base[(k + j) % N] != mat[i][k])
				{
					checkA = false;
					break;
				}
			}

			if (checkA) {
				check[i] = true;
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	for (int i = 0; i < caseNum; i++)
	{
		if (!check[i])
			continue;

		for (int k = 0; k < N; k++)
		{
			cout << mat[i][k] << " ";
		}
		cout << endl;
	}


}