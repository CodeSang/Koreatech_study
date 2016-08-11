#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

unsigned char mat[536870913]; // 1G 메모리를 요구하기때문에 사실상 불가능하다. 라고 나만 결론을 
int main() {
	ios_base::sync_with_stdio(false);
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		memset(mat, 0, sizeof(mat));
		int N;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			long long temp2 = temp - INT32_MIN;

			mat[temp2 / 8] |= (1 << (temp2 % 8));
		}

		cin >> N;
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			long long temp2 = temp - INT32_MIN;
			int stamp = (mat[temp2 / 8] & (1 << (temp2 % 8)));
			if (stamp)
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
	}

}