#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, C;
int back[31];
int cnt = 0;

void input() {
	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> back[i];
}

vector<int> v;
vector<int> v2;
vector<int> c;

void process() {

	v.push_back(0);
	for (int i = 0; i < N/2; i++)
	{
		auto target = upper_bound(v.begin(), v.end(), C - back[i]);
		
		for (auto iter = v.begin(); iter != target; iter++)
			c.push_back(*iter + back[i]);
		
		v.insert(v.end(),c.begin(),c.end());
		c.clear();
		
		sort(v.begin(), v.end());
	}

	v2.push_back(0);
	for (int i = N/2; i < N ; i++)
	{
		auto target = upper_bound(v2.begin(), v2.end(), C - back[i]);

		for (auto iter = v2.begin(); iter != target; iter++)
			c.push_back(*iter + back[i]);

		v2.insert(v2.end(), c.begin(), c.end());
		c.clear();

		sort(v2.begin(), v2.end());
	}

	for (auto iter : v)
	{
		auto target = upper_bound(v2.begin(), v2.end(), C - iter);
		cnt += (target - v2.begin());
	}
}

void output() {
	cout << cnt << endl;
}

int main() {
	input();
	process();
	output();
}