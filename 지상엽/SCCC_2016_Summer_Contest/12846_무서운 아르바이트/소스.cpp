#include<cstdio>
int N;
int pay[100001];
// STACK 으로 나중에 재 채점되면 풀어보기.
long long maxPay = 0;

void divide(int left_, int right_) {
	if (left_ >= right_)
		return;

	int min = 1000001;
	int idx = 0;
	for (int i = left_; i < right_; i++)
		if (pay[i] < min)
		{
			min = pay[i];
			idx = i;
		}


	long long  sum = (right_ - left_) * min;

	if (sum > maxPay)
		maxPay = sum;

	divide(left_, idx);
	divide(idx+1, right_);

	return;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &pay[i]);

	divide(0, N);
	printf("%lld\n", maxPay);
}