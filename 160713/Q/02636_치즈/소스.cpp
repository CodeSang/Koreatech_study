#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int N, M;
int		mat[111][111];
bool	check[111][111] = { false };

int tt = 0;
int cnt[111] = { 0 };

void input() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> mat[i][j];
}

void process() {

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

		deque<pair<pair<int, int>, int>> q;
		q.push_back({ { 0,0 }, 0});
		check[0][0] = true;

		while (!q.empty()) {

			int x		= q.front().first.first;
			int y		= q.front().first.second;
			int tempCnt = q.front().second;
			q.pop_front();


			if (tt < tempCnt)
				tt = tempCnt;


			for (int i = 0; i < 4; i++)
			{

				int tempX = x + dx[i];
				int tempY = y + dy[i];

				if( tempX >= 0 && tempX <= M + 1 && tempY >= 0 && tempY <= N + 1)
					if (!check[tempY][tempX])
					{
						check[tempY][tempX] = true;

						if (mat[tempY][tempX] == 1)
						{
							mat[tempY][tempX] = 0;
							cnt[tempCnt + 1]++;

							q.push_back({ { tempX , tempY }, tempCnt + 1 });

						}
						else
						{
							q.push_front({ { tempX , tempY }, tempCnt });
						}

					}
				
			}

		}

}

void output() {
	cout << tt << endl;
	cout << cnt[tt] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);

	input();
	process();
	output();
}