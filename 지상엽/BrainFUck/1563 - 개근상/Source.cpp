#include<iostream>
#define limit 1000000
using namespace std;

int memory[1001][2][3] = { 0 }; // N , 지각 , 결근

int main() {
	int N;

	memory[1][0][0] = 1; // 출근
	memory[1][1][0] = 1; // 지각
	memory[1][0][1] = 1; // 결근
	
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		int temp = 0;
		for (int j = 0; j < 3; j++) // 지금까지 지각한 적 없는 케이스.
			temp = (temp + memory[i - 1][0][j])%limit;

		memory[i][1][0] = temp; // 오늘 지각을 한경우
		//오늘 출석을 한경우. 
		memory[i][0][0] = temp; // 출석을 한 경우 - 지금까지 지각한적없는.
		temp = 0;

		for (int j = 0; j < 3; j++) // 지금까지 지각한 적 있는 케이스.
			temp = (temp + memory[i - 1][1][j]) % limit;

		memory[i][1][0] = (memory[i][1][0] +  temp) % limit; // 지각을 한 경우 - 지금까지 지각한적있는.

		/////////////////////////////////////////// 결근을 한케이스.
		// 오늘이 처음 결근

		// 과거 지각 한적 없음.
		memory[i][0][1] = memory[i - 1][0][0];
		// 과거 지각 있음
		memory[i][1][1] = memory[i - 1][1][0];

		//오늘 두번째

		// 과거 지각 한적 없음.
		memory[i][0][2] = memory[i - 1][0][1];
		// 과거 지각 있음
		memory[i][1][2] = memory[i - 1][1][1];
	}


	int sum = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum = (sum + memory[N][i][j]) % limit;
		}
	}

	cout << sum << endl;


}
