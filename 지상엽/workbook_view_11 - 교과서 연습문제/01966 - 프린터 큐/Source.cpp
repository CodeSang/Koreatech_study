#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct dataA {
	int dat;
	int idx;

	dataA(int d, int i): dat(d), idx(i) {}

	bool operator< (const	dataA&  lef) const {
		if (dat == lef.dat)
			return idx > lef.idx;
		else
			return dat > lef.dat;
	}

};

int main() {
	int test_Case;
	cin >> test_Case;

	for (int i = 0; i < test_Case; i++)
	{
		queue<dataA> q;
		vector<dataA> v;
		int m, n;
		cin >> m >> n;

		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			q.push(dataA(temp, j));
			v.push_back(dataA(temp, j));
		}

		int idx = 1;
		sort(v.begin(), v.end());

		while (true)
		{
			if (q.front().dat != v[idx-1].dat)
			{
				q.push(q.front());
				q.pop();
			}
			else {
				if (q.front().idx == n)
				{
					cout << idx << endl;
					break;
				}
				q.pop();
				idx++;
			}

		}

	}
}