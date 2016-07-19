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



}


void output() {
	cout << cost[dst] << endl;
}

int main() {
	input();
	process();
	output();
}