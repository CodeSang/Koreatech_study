#include<iostream>
#include<cmath>
using namespace std;

long long a, b;
long long n1, n2;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}


int main() {

	cin >> a >> b;

	n1 = b - a;
	n2 = (long long)sqrt(b) - (long long)sqrt(a);
	long long temp = gcd(n2, n1);

	if (n2 == 0)
		cout << "0" << endl;
	else
		cout << n2 / temp << "/" << n1 / temp << endl;
}