#include<iostream> 
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int lef, rig;
int M;
int mat[21];
int mem[21][21][21];

int go(int left, int right, int idx)
{
	if (idx >= M) return 0;
	int &temp = mem[left][right][idx];
	if (temp != 0) return temp;	
	temp = min(go(mat[idx], right, idx + 1) + abs(mat[idx] - left), go(left, mat[idx], idx + 1) + abs(mat[idx] - right) );
	return temp;
}

int main() {

	cin >> N;
	cin >> lef >> rig;
	
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> mat[i];

	cout << go(lef, rig, 0) << endl;
