#include<iostream>
using namespace std;

// (1) 막대기들은 끝점을 제외하곤 서로 교차하지 않는다. 
// (2) 세 개 이상의 막대기 끝이 한 점에서 만나지 않는다. 
// (3) 모든 막대기는 연결되어 있다.

int N, L;
int mat[100000][2];

int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		cin >> mat[i][0] >> mat[i][1];



}