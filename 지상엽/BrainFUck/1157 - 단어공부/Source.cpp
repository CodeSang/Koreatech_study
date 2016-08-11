#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> v(40);
int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		int temp = str[i] - 'A';
		if (temp > 30)
			temp = str[i] - 'a';
		v[temp]++;
	}

	int maxX = 0; 
	int idx = 0;


	for (int i = 0; i < 30; i++)
	{
		if (v[i] > maxX)
		{
			maxX = v[i];
			idx = i;
		}
		else if (v[i] == maxX)
		{
			idx = 30;
		}
	}

	if (idx == 30)
		cout << "?" << endl;
	else
	{
		cout << (char)(idx + 'A') << endl;
	}

}