#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> sorry;
int main() {
	int test_case;
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		sorry.clear();
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);
			sorry.push_back(temp);
		}
		sort(sorry.begin(), sorry.end());
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);
			auto iter = lower_bound(sorry.begin(), sorry.end(), temp);

			if (iter == sorry.end())
			{
				printf("0\n");
				continue;
			}

			if(*iter == temp)
				printf("1\n");
			else
				printf("0\n");
		}
	}

}