#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int v, e;
// 도착도시, 비용
vector<pair<int, int>> node[1010];
vector<int> weight(1010, INT32_MAX);
vector<bool> check(1010, false);
int sP, eP;

void input() {
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		node[x].push_back(make_pair(y, z));
	}
	cin >> sP >> eP;

}

void proccess() {
	weight[sP] = 0;
	check[sP] = false;

	while (true) {
		// 선택 되지 않은 그리고 가장 작은 정점 선택.
		int closest = INT32_MAX;
		int here;
		for (int i = 1; i <= v; i++)
		{
			if (weight[i] < closest && !check[i]) {
				here = i;
				closest = weight[i];
			}

		}
		if (closest == INT32_MAX) break;
		check[here] = true;

		for (int i = 0; i < node[here].size(); i++)
		{
			int there = node[here][i].first;
			if (check[there]) continue;
			int nextDist = weight[here] + node[here][i].second;
			weight[there] = min(weight[there], nextDist);
		}

	}
}

void output() {
	cout << weight[eP] << endl;
}

int main() {
	input();
	proccess();
	output();
}