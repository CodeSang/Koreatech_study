#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

string str;
int mem[2501];
int mem2[2501][2501];

int isPalin(int s, int e)
{
	if (mem2[s][e] != -1) return mem2[s][e];
	if (s == e) return mem2[s][e] = 1;
	else if (s + 1 == e) {
		if (str[s] == str[e]) return mem2[s][e] = 1;
		else return mem2[s][e] = 0;
	}
	
	if (str[s] == str[e]) return mem2[s][e] = isPalin(s + 1, e - 1);
	else return mem2[s][e] = 0;
}

int Go(int e){

	if (mem[e] != 0) return mem[e];
	if (isPalin(0, e) == 1) return mem[e] = 1;
	int temp = 2500;
	for (int i = 0; i <= e; i++)
		if (isPalin(i,e) == 1)
			temp = min(temp, Go(i-1)+1);	

	return mem[e] = temp;
}

int main() {
	memset(mem2, -1, sizeof(mem2));
	mem[0] = 1;
	cin >> str;
	cout << Go(str.size()-1)<<endl;
}