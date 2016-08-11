#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;


map<string, int> mm;
int p[200001];
int num[200001];
int F, fNum = 0;

int Find_(int A) {
	if (A == p[A]) return A;
	return p[A] = Find_(p[A]);
}

void union_(int A, int B) {
	A = Find_(A);
	B = Find_(B);

	int cnt = 0;
	if (A == B) {
		cout << num[A] << '\n';
		return;
	}

	p[A] = B;
	num[B] += num[A];
	cout << num[B] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		fNum = 0;
		cin >> F;
		mm.clear();
		memset(num, 0, sizeof(num));
		for (int j = 0; j < F; j++)
		{

			string str1, str2;
			int A, B;
			cin >> str1 >> str2;

			if (mm.count(str1))
			{
				A = mm[str1];
			}
			else
			{
				A = fNum;
				p[fNum] = fNum;
				num[fNum] = 1;
				mm[str1] = fNum++;
			}
			if (mm.count(str2))
			{
				B = mm[str2];
			}
			else
			{
				B = fNum;
				p[fNum] = fNum;
				num[fNum] = 1;
				mm[str2] = fNum++;
			}

			if (A < B) swap(A, B);

			union_(A, B);
		}
	}
}