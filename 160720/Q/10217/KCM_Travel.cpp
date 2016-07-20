#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge {
	int to;
	int cost;
	int time_;
	
	Edge(int t, int c, int d) : to(t), cost(c), time_(d) {}

	bool operator<(const Edge& left) const {
		return time_ > left.time_;
	}
};

int N, M, K;
vector<vector<Edge>> node;
priority_queue<long long> weight;

void input() {
	cin >> N >> M >> K;

	vector<vector<Edge>> temp(N+1);
	swap(temp, node);
	priority_queue<long long> temp2;
	swap(temp2, weight);
	
	for (int i = 0; i < K; i++)
	{
		int x, y, c, d;
		cin >> x >> y >> c >> d;
		node[x].push_back(Edge(y, c, d));
	}
}

void process() {
	// 1 - > N 번 도시까지

	priority_queue<Edge> pq;
	pq.push(Edge(1, 0, 0));

	while (!pq.empty())
	{
		int tTo		= pq.top().to;
		int tCost	= pq.top().cost;
		int tTime	= pq.top().time_;
		pq.pop();

		if (tTo == N) {
			weight.push(-tTime);
			return;
		}


		for (auto iter : node[tTo])
		{
			if (tCost + iter.cost <= M)
			{
				pq.push(Edge(iter.to,iter.cost+tCost,tTime+iter.time_));
			}			
		}
	}
}

void output() {

	if (weight.empty())
		cout << "Poor KCM" << endl;
	else
		cout << -weight.top() << endl;
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
