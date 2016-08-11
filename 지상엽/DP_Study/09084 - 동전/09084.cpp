#include<iostream>
#include<cstring>
using namespace std;

int N;
int mat[20];
int M;
int mem[10001];

int main() {
	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		memset(mem, 0, sizeof(mem));
		mem[0] = 1;

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> mat[i];
		cin >> M;

		for (int i = 0; i < N; i++)
			for (int j = mat[i]; j <= M; j++)
				mem[j] += mem[j - mat[i]];
		
		cout << mem[M]<<endl;		
	}

}
