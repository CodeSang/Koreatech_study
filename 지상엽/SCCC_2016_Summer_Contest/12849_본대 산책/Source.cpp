#include<iostream>
#define INF 1000000007
using namespace std;

int D; // 100,000 มฆวั
int mat[2][10] = { 0 };

void input() {
	cin >> D;
}

int sum(int a, int b) {
	return ((a + b) % INF);
}

int sum(int a, int b, int c) {
	return ((((a + b) % INF) + c) % INF);
}

int sum(int a, int b, int c, int d) {
	return ((sum(a, b) + sum(c, d)) % INF);
}

void process() {

	mat[0][0] = 1;

	for (int i = 1; i <= D; i++)
	{
		mat[i % 2][0] = sum(mat[(i + 1) % 2][1], mat[(i + 1) % 2][2]);
		mat[i % 2][1] = sum(mat[(i + 1) % 2][0], mat[(i + 1) % 2][2], mat[(i + 1) % 2][3]);
		mat[i % 2][2] = sum(mat[(i + 1) % 2][0], mat[(i + 1) % 2][1], mat[(i + 1) % 2][3], mat[(i + 1) % 2][4]);
		mat[i % 2][3] = sum(mat[(i + 1) % 2][1], mat[(i + 1) % 2][2], mat[(i + 1) % 2][4], mat[(i + 1) % 2][5]);
		mat[i % 2][4] = sum(mat[(i + 1) % 2][2], mat[(i + 1) % 2][3], mat[(i + 1) % 2][5], mat[(i + 1) % 2][7]);
		mat[i % 2][5] = sum(mat[(i + 1) % 2][3], mat[(i + 1) % 2][4], mat[(i + 1) % 2][6]);
		mat[i % 2][6] = sum(mat[(i + 1) % 2][5], mat[(i + 1) % 2][7]);
		mat[i % 2][7] = sum(mat[(i + 1) % 2][4], mat[(i + 1) % 2][6]);
	}
}

void output() {
	cout << mat[D % 2][0] << endl;
}

int main() {
	input();
	process();
	output();
}