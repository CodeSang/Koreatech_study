#include<iostream>
#include<vector>
using namespace std;

int N;
vector<pair<long long, long long> > v;
long long C; // 물건 가격의 최대 값.
long long maxValue = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long temp, temp1;
		cin >> temp >> temp1;
		v.push_back({temp, temp1});
	}
	cin >> C;
}

void process() {
	long long weight = 0;
	long long value = 0;

	for (int i = v.size() - 1; i > 0; i--)
	{
		if (weight + v[i].first > C)
			break;
		weight += v[i].first;
		value  += v[i].second;
	}

	maxValue = value;





}


void output() {
	cout << maxValue << endl;
}

int main() {
	input();
	process();
	output();
}