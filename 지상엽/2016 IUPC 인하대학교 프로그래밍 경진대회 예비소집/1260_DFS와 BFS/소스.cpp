#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> node[1001];
bool D[1001] = { false };
bool B[1001] = { false };

int N, M, V;

void input() {
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}

	for (int i = 1; i <= N; i++)
		sort(node[i].begin(), node[i].end());

}

void DFS(int pos) {
	D[pos] = true;
	cout << pos << " ";
	for (auto iter : node[pos])
	{
		if(!D[iter])
			DFS(iter);
	}

}

void BFS() {

	queue<int > q;
	q.push(V);
	B[V] = true;

	while (!q.empty())
	{
		int dst = q.front();
		cout << dst << " ";
		q.pop();

		for (auto iter : node[dst])
		{
			if (!B[iter])
			{
				B[iter] = true;
				q.push(iter);
			}
		}

	}

}

void output() {
	DFS(V);
	cout << endl;
	BFS();
	cout << endl;
}

int main() {
	input();
	output();
}