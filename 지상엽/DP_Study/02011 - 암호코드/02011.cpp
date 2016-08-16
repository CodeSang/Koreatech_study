#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int mem[5011];
string str;


int main() {
	
	cin >> str;

	str = "0" + str;
	mem[0] = 1;

	for (int i =1; i < str.size() ; i++)
	{
		if (str[i] == '0'){
			int temp = (str[i - 1] - '0') * 10 + str[i] - '0';
			if (temp >= 10 && temp <= 26)
				mem[i] = (mem[i - 2]) % 1000000;
		}
		else {
			mem[i] = mem[i - 1];
			int temp = (str[i - 1] -'0')* 10 + str[i] - '0';
			if (temp >= 10 && temp <=26)
				mem[i] = (mem[i - 2] + mem[i - 1]) % 1000000;
		}
	}
	cout << mem[str.size()-1] << endl;
}