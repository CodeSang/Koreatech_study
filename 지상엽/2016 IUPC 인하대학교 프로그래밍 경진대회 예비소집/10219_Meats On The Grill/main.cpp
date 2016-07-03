#include<iostream>
#include<algorithm>
using namespace std;


int H, W;
char grill[12][12];

void input() {
	cin >> H >> W;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> grill[i][j];
}

void process(){

	for (int i = 0; i < H/2; i++)
		for (int j = 0; j < W; j++)
		{
			swap(grill[i][j], grill[H - i - 1][j]);
		}

}

void output() {

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << grill[i][j];
		}
		cout << endl;
	}
}

int main() {

	int T;
	
	cin >> T;

	while(T--)
	{
		input();
		process();
		output();
	}

}