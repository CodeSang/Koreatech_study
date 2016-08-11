#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int mat[1001];
vector<int> v;

int main() {
	
	cin >> N;	
	for (int i = 0; i < N; i++)
		cin >> mat[i];

	v.push_back(mat[0]);

	for (int i = 1; i < N; i++)
	{
		auto iter = lower_bound(v.begin(), v.end(), mat[i]);

		if (iter == v.end())
			v.push_back(mat[i]);
		else
			*iter = mat[i];
	}

	cout << v.size() << endl;
}