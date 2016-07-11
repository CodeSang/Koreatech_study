#include<iostream>
using namespace std;


int N;
int mat[10001];
unsigned long long int money;
int answer = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> mat[i];
	cin >> money;
}

void binarySearch()
{
	int left = 1;
	int right = 0;

	for (int i = 0; i < N; i++)
		if (right < mat[i])
			right = mat[i];

	unsigned long long int temp = 0;
	while (left <= right)
	{
		int center = (right + left) / 2;

		temp = 0;

		for (int i = 0; i < N; i++) {
			if (center > mat[i])
				temp += mat[i];
			else
				temp += center;
		}

		if (money >= temp)
		{
			if (answer < center)
				answer = center;

			left = center + 1;
		}
		else {
			right = center - 1;
		}
	}
}

void proccess()
{
	binarySearch();
}

void output() {
	cout << answer << endl;
}

int main() {

	input();
	proccess();
	output();


}