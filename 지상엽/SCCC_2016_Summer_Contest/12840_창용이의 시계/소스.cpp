#include<cstdio>

int main() {
	int h, m, s, day = 3600*24,now;
	scanf("%d %d %d", &h, &m, &s);
	now = h * 3600 + m * 60 + s;
	int test_case, time_;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++)
	{
		int q;
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d", &time_);
			time_ = time_ % day;
			now += time_;
			now = now % day;
		}
		else if (q == 2) {
			scanf("%d", &time_);
			time_ = time_ % day;
			now -= time_;
			if (now < 0)
				now += day;
		}
		else if (q == 3)
			printf("%d %d %d\n", now / 3600, (now % 3600) / 60 ,now % 60);
	}
	return 0;
}