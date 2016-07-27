#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct borrow {
	int start;
	int end;

	bool operator< (borrow const &left) const {
		if (end == left.end)
			return start < left.start;
		else
			return end < left.end;
	}
};

int N, cnt;
vector<borrow> v;

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());
}

void process() {

	int now = 0;
	for (auto iter : v)
	{
		if (iter.start >= now)
		{
			now = iter.end;
			cnt++;
		}
	}
}

void output() {
	printf("%d\n", cnt);
}

int main() {
	input();
	process();
	output();
}