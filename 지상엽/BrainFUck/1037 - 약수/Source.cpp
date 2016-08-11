#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long answer = v[0] * v[N - 1];
	cout << answer << endl;
}