#include<iostream>
#include<vector>
using namespace std;



int N;
vector<int> parents;
vector<bool> check;
int cnt = 0;

void input() {
	cin >> N;
	cnt = 0;
	parents.clear();
	parents.resize(N + 1);

	check.clear();
	check.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> parents[i];
}

bool dfs(int idx)
{
	int tempIdx = parents[idx];
	check[tempIdx] = true;

	while (tempIdx != idx)
	{
		if (!check[tempIdx]) return false;
		tempIdx = parents[tempIdx];
		check[tempIdx] = true;
	}	

	return true;
}

void process() {

	for (int i = 1; i <= N; i++)
	{
		if (check[i]) continue;
		if (dfs(i)) cnt++;
	}

}

void output() {
	cout << cnt << endl;
}

int main() {
	int test_Case;
	cin >> test_Case;

	while (test_Case--)
	{
		input();
		process();
		output();
	}
}