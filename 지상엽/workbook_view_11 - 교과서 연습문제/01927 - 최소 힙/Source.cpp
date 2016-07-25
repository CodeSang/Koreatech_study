#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp) pq.push(-temp);
		else {
			if (pq.empty()) cout << '0' << '\n';
			else {
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
	}
}