#include<cstdio>
#include<algorithm>
#include<deque>
#include<iostream>
#include<vector>
using namespace std;


int N;
int mat[26][26];
bool check[26][26] = { false };

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &mat[i][j]);
}

int party[900];
int num = 0;

void process() {

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	deque<pair<int, int>> dq;
	

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] == 1 && !check[i][j])
			{
				dq.push_back({ j,i });
				check[i][j] = true;
				num++;
				party[num]++;

				while (!dq.empty())
				{
					int x = dq.front().first;
					int y = dq.front().second;
					dq.pop_front();

					for (int k = 0; k < 4; k++)
					{
						int tempX = x + dx[k];
						int tempY = y + dy[k];

						if(tempX >= 0 && tempX < N && tempY >= 0 && tempY <N)
						if (!check[tempY][tempX])
						{
							check[tempY][tempX] = true;

							if (mat[tempY][tempX] == 1)
							{
								dq.push_back({ tempX,tempY });
								party[num]++;
							}

						}

					}

				}

			}
		}
}

void output() {
	printf("%d\n", num);
	sort(party, party + num + 1);

	for (int i = 1; i <= num; i++)
		printf("%d\n", party[i]);
}

int main() {
	input();
	process();
	output();
}