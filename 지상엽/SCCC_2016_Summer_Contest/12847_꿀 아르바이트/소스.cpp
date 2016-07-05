#include<iostream>
using namespace std;


int pay[100001];
int main() {
	int N, D;
	scanf("%d %d", &N, &D);

	for (int i = 0; i < N; i++)
		scanf("%d", &pay[i]);

	long long maxPay = 0;
	long long sum = 0; 

	for (int i = 0; i < D; i++)
		sum += pay[i];

	maxPay = sum;


	for (int i = D; i < N; i++)
	{
		sum += pay[i];
		sum -= pay[i - D];

		if (sum > maxPay)
			maxPay = sum;
	}

	printf("%lld\n", maxPay);

}
