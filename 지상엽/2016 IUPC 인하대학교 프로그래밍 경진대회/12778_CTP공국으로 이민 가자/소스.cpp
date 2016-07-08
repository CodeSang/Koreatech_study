#include<iostream>
using namespace std;

int M;
char C;


void input() {
	cin >> M >> C;

	if (C == 'C')
	{
		for (int i = 0; i < M; i++)
		{
			char temp;
			cin >> temp;

			cout << (int)(temp - 'A' + 1) << " ";
		}

		cout << '\n';
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			int temp;
			cin >> temp;

			cout << (char)(temp + 'A' - 1) << " ";
		}

		cout << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(false);

	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		input();
	}

}