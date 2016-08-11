#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int gld(int a, int b) {
	return a*b / gcd(a, b);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << gld(a, b)<<endl;
	}
}