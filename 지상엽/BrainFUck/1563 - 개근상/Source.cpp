#include<iostream>
#define limit 1000000
using namespace std;

int memory[1001][2][3] = { 0 }; // N , ���� , ���

int main() {
	int N;

	memory[1][0][0] = 1; // ���
	memory[1][1][0] = 1; // ����
	memory[1][0][1] = 1; // ���
	
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		int temp = 0;
		for (int j = 0; j < 3; j++) // ���ݱ��� ������ �� ���� ���̽�.
			temp = (temp + memory[i - 1][0][j])%limit;

		memory[i][1][0] = temp; // ���� ������ �Ѱ��
		//���� �⼮�� �Ѱ��. 
		memory[i][0][0] = temp; // �⼮�� �� ��� - ���ݱ��� ������������.
		temp = 0;

		for (int j = 0; j < 3; j++) // ���ݱ��� ������ �� �ִ� ���̽�.
			temp = (temp + memory[i - 1][1][j]) % limit;

		memory[i][1][0] = (memory[i][1][0] +  temp) % limit; // ������ �� ��� - ���ݱ��� ���������ִ�.

		/////////////////////////////////////////// ����� �����̽�.
		// ������ ó�� ���

		// ���� ���� ���� ����.
		memory[i][0][1] = memory[i - 1][0][0];
		// ���� ���� ����
		memory[i][1][1] = memory[i - 1][1][0];

		//���� �ι�°

		// ���� ���� ���� ����.
		memory[i][0][2] = memory[i - 1][0][1];
		// ���� ���� ����
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
