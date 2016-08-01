#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int sumA = 0;
priority_queue<int > pq;
vector<int> node[10010];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int value, day;
		cin >> value >> day;
		node[day].push_back(value);
	}
}


void process() {
	for (int i = 10000; i > 0; i--)
	{
		if (!node[i].empty())
		{
			for (auto iter : node[i])
				pq.push(iter);
		}

		if (!pq.empty()) {
			sumA += pq.top();
			pq.pop();
		}
	}
}

void output() {
	cout << sumA << endl;
}

int main() {

	input();
	process();
	output();

}