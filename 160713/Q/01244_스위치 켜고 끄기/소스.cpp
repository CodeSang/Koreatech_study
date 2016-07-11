#include<iostream>
using namespace std;

int N, student;
int light[101];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> light[i];
	cin >> student;
}

void boy(int index) {
	for (int i = index-1; i < N; i = i +index)
	{
		if (light[i]) light[i] = 0;
		else		  light[i] = 1;
	}

}
void girl(int index) {

	int left  = index - 1;
	int right = index + 1;
	
	while (left >= 0 && right < N)
	{
		if (light[left] == light[right])
		{
			left--; 
			right++;
		}
		else
			break;
	}

	for (int i = left + 1; i < right; i++)
	{
		if (light[i])	light[i] = 0;
		else			light[i] = 1;
	}
}

void process() {

	int gender, idx;
	for (int i = 0; i < student; i++)
	{

		cin >> gender >> idx;

		if (gender == 1)
			boy(idx);
		else
			girl(idx -1);
	}
}

void output() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt++;
		cout << light[i] << " ";
		if ((cnt % 20) == 0)
			cout << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	
	input();
	process();
	output();

}