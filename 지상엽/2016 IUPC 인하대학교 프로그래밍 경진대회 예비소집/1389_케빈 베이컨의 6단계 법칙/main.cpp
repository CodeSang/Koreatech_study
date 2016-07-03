#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<int > node[101];
pair<int, int> answer;

void input() {
	cin >> N >> M;

	answer = { 0, INT32_MAX };
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;

		node[x].push_back(y);
		node[y].push_back(x);
	}

}

void process() {

	for (int i = 1; i <= N; i++)
	{
		bool check[101] = { false };
		queue<pair<int, int> > q; // dst , length;
		q.push({ i,0 });
		check[i] = true;
		int tempAnswer = 0;

		while (!q.empty())
		{
			auto pos = q.front();
			q.pop();

			for (auto iter : node[pos.first])
			{
				if (!check[iter])
				{
					check[iter] = true;
					q.push({ iter , pos.second + 1 });
					tempAnswer += (pos.second + 1);
				}
			}
		}

		if (answer.second > tempAnswer)
		{
			answer.second = tempAnswer;
			answer.first = i;
		}
	}
}

void output() {
	cout << answer.first << endl;
}

int main() {
	ios_base::sync_with_stdio(false);

	input();
	process();
	output();

}