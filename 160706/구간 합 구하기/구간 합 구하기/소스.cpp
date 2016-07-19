#include<cstdio>
using namespace std;

long long tree[3000001] = { 0 };
int b = 1;

void update(int idx, long long diff) {
	idx += b;

	tree[idx] += diff;
	while (idx > 1) {
		tree[idx / 2] += diff;
		idx /= 2;
	}
}

long long print(int left, int right) {

	left += b;
	right += b;

	long long ans = 0;

	while (left < right) {
		if (left % 2 == 0)
			left /= 2;
		else {
			ans += tree[left];
			left += 1;
			left /= 2;
		}

		if (right % 2 == 1)
			right /= 2;
		else {
			ans += tree[right];
			right -= 1;
			right /= 2;
		}

	}

	if (left == right)
		ans += tree[left];

	return ans;
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	while (b <= N)
	{
		b *= 2;
	}
	b -= 1;

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		update(i + 1, temp);
	}

	for (int i = 0; i < M + K; i++)
	{
		int test_case, left;
		long long right;
		scanf("%d %d %lld", &test_case, &left, &right);

		if (test_case == 1)
		{
			update(left, right - tree[b + left]);
		}
		else
		{
			printf("%lld\n", print(left, (int)right));
		}
	}

}