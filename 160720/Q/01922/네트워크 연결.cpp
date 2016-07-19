#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
	int to;
	int cost;
	Edge(int t, int c) : to(t), cost(c) {}

	bool operator< (const Edge& left) const  {
		return cost > left.cost;
	}
};

int v, e;
vector<vector<Edge> > node;
vector<bool > check;
vector<int > weight(1001, INT32_MAX);
long long sumAll = 0;

void input() {
	cin >> v;
	cin >> e;

	node.resize(v + 1);
	check.resize(v + 1);
	weight.resize(v + 1);


	for (int i = 0; i < e; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		node[x].push_back(Edge(y, cost));
		node[y].push_back(Edge(x, cost));

	}
}

void process() {
	// 모든 선을 연결하는 최소의 선이기 때문에 

	priority_queue<Edge> pq;
	pq.push(Edge(1,0));
	weight[1] = 0;

	while (!pq.empty())
	{
		int to = pq.top().to;
		int cost = pq.top().cost;
		pq.pop();

		if (check[to])
			continue;
		else
			check[to] = true;

		sumAll += cost;

		for (auto iter : node[to])
			pq.push(iter);
		
	}
}

void output() {
	cout << sumAll << endl;
}

int main() {
	input();
	process();
	output();
}