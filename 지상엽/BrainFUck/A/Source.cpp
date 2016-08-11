#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int A, B, N;
vector<int> v;

void input() {
	cin >> A >> B >> N;
}

void process() {
	for (int i = 0; i < N; i++)
	{
		cout << B + N*A + i*B<< ' ';
	}
}


int main() {
	input();
	process();
}