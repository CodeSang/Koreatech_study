#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, K; // °Ç¹° ¼ö, Edge
int W;		// dst;

vector<int> V;
vector<int> line[1001];

int p[1001];
int time_[1001];

void input() {
	
	cin >> N >> K;
	V.clear();
	
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		V.push_back(temp);
		line[i].clear();
		p[i] = 0;
		time_[i] = 0;
	}

	for (int i = 0; i < K; i++)
	{
		int tempx, tempy;
		cin >> tempx >> tempy;
		line[tempx].push_back(tempy);
		p[tempy]++;
	}

	cin >> W;
}

void process() {

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (p[i] == 0)
		{
			q.push(i);
			time_[i] = V[i-1];
		}
	}

	while (!q.empty())
	{
		int dst = q.front();
		q.pop();

		for (auto iter : line[dst])
		{
			p[iter]--;

			time_[iter] = max(time_[iter] , time_[dst] + V[iter-1]);
			if (p[iter] == 0)
			{
				q.push(iter);
			}
		}
	}

}


void output() {
	cout << time_[W] << endl;
}

int main() {

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		input();
		process();
		output();
	}

}