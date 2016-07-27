#include<iostream>
using namespace std;

int N, D, cnt = 0;
int p[100];
int c[100] = { 0 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> p[i];

		if (p[i] != -1)
			c[p[i]]++;
	}
	cin >> D;
}

void process() {
	
	for (int i = 0; i < N; i++)
	{
		if (c[i] != 0 || i == D)
			continue;

		int temp = i;
		bool check = true;
		while (p[temp] != -1)
		{
			temp = p[temp];
			if(temp == D)
			{
				check = false;
				break;
			}
		}

		if (check) cnt++;
	}
}

void output() {
	cout << cnt << endl;
}

int main() { input(); process(); output(); }