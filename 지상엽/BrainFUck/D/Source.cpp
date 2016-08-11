#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N, M, B; // 배팅 금액 비율.  포기 마지노선
vector<pair<int, double> > v; // 확률과 배당률

void input() {
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		int a;
		double b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

}
double ans = 0;
void process() {

	queue<pair<int, pair<double, double> > > q;
	// cycle , money rate
	q.push({ 1,{10000,10000} });
	for (auto iter : v)
	{
		int now = q.front().first;

		int rate = iter.first;
		double m = iter.second;

		while (now == q.front().first)
		{
			if (q.front().second.first < 10000 * B / 100)
			{
				q.pop();
				continue;
			}
			q.push({ now + 1,{ M / 100 * q.front().second.first + (100 - M) / q.front().second.first , q.front().second.second * (M / 100) } });
			q.push({ now + 1,{ -M / 100 * q.front().second.first + (100 - M) / q.front().second.first , q.front().second.second * (M / 100) } });
			q.pop();
		}
	}

	while (!q.empty())
	{
		ans += q.front().second.first;
		q.pop();
	}


}

void output() {
	cout << ans << endl;
}

int main() {
	input();
	process();
	output();
}