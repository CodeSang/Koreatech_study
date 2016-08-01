#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;
	vector<int> v(N);
	long long tip = 0;
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end(), [](const int &l, const int &r) {return l > r;});
	for (int i = 0; i < N; i++) tip += max(0, v[i] - i);
	cout << tip << endl;
}
