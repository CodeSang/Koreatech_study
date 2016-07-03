#include<iostream>
#include<vector>
#include<string>
using namespace std;

string str;
vector<int> pos(30, -1);

void input() {
	cin >> str;
}

void process(){

	for (int i = 0; i < str.length(); i++)
	{
		if (pos[str[i] - 'a'] == -1)
			pos[str[i] - 'a'] = i;
	}
}

void output() {

	for (int i = 0; i <= 'z' - 'a'; i++)
		cout << pos[i] << " ";
}

int main() {
	input();
	process();
	output();
}