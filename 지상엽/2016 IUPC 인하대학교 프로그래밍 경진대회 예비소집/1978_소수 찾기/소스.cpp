#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> num;
int cnt = 0;

void input(){
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);

	}
}
void process(){
	
	for (auto iter : num)
	{
		bool check = true;
		if (iter == 1) continue;
		for (int i = 2; i*i <= iter; i++)
			if (iter % i == 0)
			{
				check = false;
				break;
			}

		if(check)
			cnt++;
	}

}

void output() {
	cout << cnt << endl;
}

int main() {
	input();
	process();
	output();
}