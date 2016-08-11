#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;


int main() {

	string str;
	cin >> str;

	int temp = str[0] - '0';
	if (temp == 7) cout << "111";
	else if (temp == 6) cout << "110";
	else if (temp == 5) cout << "101";
	else if (temp == 4) cout << "100";
	else if (temp == 3) cout << "11";
	else if (temp == 2) cout << "10";
	else if (temp == 1) cout << "1";
	
	for (int i = 1; i < str.size(); i++)
	{
		int temp2 = str[i] - '0';
		if (temp2 == 7) cout << "111";
		else if (temp2 == 6) cout << "110";
		else if (temp2 == 5) cout << "101";
		else if (temp2 == 4) cout << "100";
		else if (temp2 == 3) cout << "011";
		else if (temp2 == 2) cout << "010";
		else if (temp2 == 1) cout << "001";
		else if (temp2 == 0) cout << "000";

	}

	cout << endl;
}