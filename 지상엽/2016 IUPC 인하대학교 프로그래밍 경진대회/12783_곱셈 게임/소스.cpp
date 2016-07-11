#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M;
bool num[10];

void input(){

	cin >> N;

	for (int i = 0; i < 10; i++)
		num[i] = false;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num[temp] = true;
	}

	cin >> M;
}

bool have(int nn) {

	while (nn > 0)
	{
		if (!num[nn % 10])
			return false;
		nn /= 10;
	}
	return true;
}

void process() {
	int K;
	for (int i = 0; i < M; i++)
	{
		cin >> K;

		if (have(K))
		{
			cout << "0" << '\n';
			continue;
		}


	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		input();
		process();		
	}
}