#include<iostream>
#include<queue>
using namespace std;

int N, M;

int tomato[1001][1001];
// 1은 익은 토마토, 0 안익은 토마토, -1 빈칸

queue<pair<pair<int, int>,int> > ripeTomato;
int noripe = 0;

int answer = 0;

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
			{
				ripeTomato.push({ { j,i } , 0});
			}
			else if (tomato[i][j] == 0)
			{
				noripe++;
			}
		}
}

void process() {

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };

	while (!ripeTomato.empty())
	{
		int x	= ripeTomato.front().first.first;
		int y	= ripeTomato.front().first.second;
		int day = ripeTomato.front().second;

		ripeTomato.pop();

		for (int i = 0; i < 4; i++)
		{
			int tempx = x + dx[i];
			int tempy = y + dy[i];

			if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= M)
				continue;

			if ( tomato[tempy][tempx] == 0 )
			{
				answer = day + 1;
				noripe--;
				tomato[tempy][tempx] = 1;
				ripeTomato.push({ { tempx,tempy } , day + 1 });
			}			
		}
	}

	if (noripe > 0)
		answer = -1;
}

void output() {
	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	input();
	process();
	output();
}