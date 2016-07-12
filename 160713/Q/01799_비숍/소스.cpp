#include<iostream>
#include<algorithm>
using namespace std;

int N; 
int chess[11][11];

int max_value = 0;

bool checkM[30] = { false };
bool checkP[30] = { false };

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> chess[i][j];



	cout << max_value << endl;
	return 0;
}