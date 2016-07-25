#include<iostream>
#include<cstring>

#define INF 1000000007
using namespace std;

int D; // 100,000 มฆวั
int node[8][8] = {  { 0, 1, 1, 0, 0, 0, 0, 0 } ,
					{ 1, 0, 1, 1, 0, 0, 0, 0 } ,
					{ 1, 1, 0, 1, 1, 0, 0, 0 } ,
					{ 0, 1, 1, 0, 1, 1, 0, 0 } ,
					{ 0, 0, 1, 1, 0, 1, 0, 1 } ,
					{ 0, 0, 0, 1, 1, 0, 1, 0 } ,
					{ 0, 0, 0, 0, 0, 1, 0, 1 } ,
					{ 0, 0, 0, 0, 1, 0, 1, 0 } };

int answer[8][8] = { { 1, 0, 0, 0, 0, 0, 0, 0 } ,
					 { 0, 1, 0, 0, 0, 0, 0, 0 } ,
					 { 0, 0, 1, 0, 0, 0, 0, 0 } ,
					 { 0, 0, 0, 1, 0, 0, 0, 0 } , 
					 { 0, 0, 0, 0, 1, 0, 0, 0 } , 
					 { 0, 0, 0, 0, 0, 1, 0, 0 } , 
					 { 0, 0, 0, 0, 0, 0, 1, 0 } , 
					 { 0, 0, 0, 0, 0, 0, 0, 1 } };

int tmp[8][8] = { 0 };

void input() {
	cin >> D;
}

void matMul( int mat[][8], int mat2[][8]) {

	for(int i = 0 ; i <  8 ; i++)
		for (int j = 0; j < 8; j++)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < 8; k++)
			{
				tmp[i][j] = (tmp[i][j] + (long long)mat[i][k] * mat2[k][j]) % INF;
			}
		}
}

void process() {
	
	while (D) {
		if (D % 2) {
			matMul(answer, node);
			memcpy(answer, tmp, sizeof(tmp));
		}
		matMul(node ,node);
		memcpy(node, tmp, sizeof(tmp));
		D /= 2;
	}

}

void output() {
	cout <<	answer[0][0] << endl;
}

int main() {
	input();
	process();
	output();
}