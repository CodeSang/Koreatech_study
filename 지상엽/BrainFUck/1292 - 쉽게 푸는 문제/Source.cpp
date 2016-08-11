#include<iostream>
using namespace std;

int arr[2020] = { 0 };
int main() {
	int A, B;
	cin >> A >> B;

	int idx = 1;
	int now = 1;
	while (idx < 1001)
	{
		for (int i = idx; i < idx + now; i++)
		{
			arr[i] = now;
		}

		idx += now;
		now++;
	}

	int sum = 0;
	for (int i = A; i <= B; i++)
		sum += arr[i];
	cout << sum << endl;
}