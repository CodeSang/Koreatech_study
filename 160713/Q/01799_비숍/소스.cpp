#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N; 
int chess[11][11];

int max_value = 0;

vector<pair<int, int>> black;
vector<pair<int, int>> white;

bool checkM[30] = { false };
bool checkP[30] = { false };

int black_search(int idx, int n) {
	if (idx >= n) return 0;

	int x = black[idx].first;
	int y = black[idx].second;

	int A = 0, B;

	if (!checkM[x - y + 15] && !checkP[x + y])
	{
		checkM[x - y + 15]	= true;
		checkP[x + y]		= true;

		A = black_search(idx + 1, n) + 1;

		checkM[x - y + 15]	= false;
		checkP[x + y]		= false;

	}
	
	B = black_search(idx + 1, n);

	return max(A, B);
}

int white_search(int idx, int n) {
	if (idx >= n) return 0;

	int x = white[idx].first;
	int y = white[idx].second;

	int A = 0, B;

	if (!checkM[x - y + 15] && !checkP[x + y])
	{
		checkM[x - y + 15] = true;
		checkP[x + y] = true;

		A = white_search(idx + 1, n) + 1;

		checkM[x - y + 15] = false;
		checkP[x + y] = false;

	}

	B = white_search(idx + 1, n);

	return max(A, B);
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> chess[i][j];
			if (chess[i][j] == 1)
			{
				if ((i + j) % 2)
					black.push_back({ j,i });
				else
					white.push_back({ j,i });
			}
		}

	max_value = black_search(0,black.size()) + white_search(0, white.size());

	cout << max_value << endl;
	return 0;
}