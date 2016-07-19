#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M; //V ,E 
vector<pair<int, int>> node[1001];
vector<bool> check(1001, false);
vector<int>  cost(1001, 100000000);

int src, dst;
 
void input() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y, temp;
		cin >> x >> y >> temp;
		node[x].push_back({ y,temp });
	}
	cin >> src >> dst;
}

void process() {

	priority_queue<pair<int, int>> pq; // Cost , dst
	
	cost[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty())
	{
		int tempSrc  = pq.top().second;
		pq.pop();

		if (check[tempSrc])
			continue;
		else
			check[tempSrc] = true;

		for (auto iter : node[tempSrc])
		{
			int tempDst = iter.first;
			if (cost[tempDst] > cost[tempSrc] + iter.second)
			{
				cost[tempDst] = cost[tempSrc] + iter.second;
				pq.push( make_pair(-cost[tempDst], tempDst) );
			}

		}		
	}
}

void output() {
	cout << cost[dst] << endl;
}

int main() {
	input();
	process();
	output();
}