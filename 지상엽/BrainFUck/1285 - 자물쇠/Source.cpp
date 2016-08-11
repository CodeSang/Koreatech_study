#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int N;
int A[111], B[111]; //33
int mem[111][10][10] = { 0 };
int mini = INT32_MAX;

void input() {
	cin >> N;
	string str;
	cin >> str;
	for (int i = 0; i < N; i++)
		A[i] = str[i] - '0';
	cin >> str;
	for (int i = 0; i < N; i++)
		B[i] = str[i] - '0';
}


int rr(int a, int b)
{
	if (a < b) swap(a, b);
	if (a - b <= 5)
	{
		if ((a - b) % 3)
			return (a - b) / 3 + 1;
		else
			return (a - b) / 3;
	}
	else
	{
		if((b+10 - a) % 3)
			return (b + 10 - a) / 3 + 1;
		else
			return (b + 10 - a) / 3;
	}
}

int DP(int n) {

}

void process() {
	mini = DP(0);
}

void output() {
	cout << mini << endl;
}

int main() {
	input();
	process();
	output();
}