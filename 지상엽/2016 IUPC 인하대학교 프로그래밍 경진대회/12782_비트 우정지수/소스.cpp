#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str1, str2;
int bitnum;

void input() {
	bitnum = 0;
	cin >> str1 >> str2;
}


int one, zero;

void process() {

	one = 0;
	zero = 0;

	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] == '1')
				one++;
			else
				zero++;
		}
	}


	bitnum  = min(one, zero);
	bitnum += max(one, zero) - min(one, zero);

}

void output() {
	cout << bitnum << endl;
}

int main() {
	int T;
	cin >> T;

	while (T--)
	{
		input();
		process();
		output();
	}
}