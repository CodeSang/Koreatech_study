#include<iostream>
#include<string>

using namespace std;


// ��� ��� �ٸ� �˰����� �ʿ�� ���� �ʴ°� ����.

string H, N;
int cnt = 0;

int main() {

	cin >> H;
	cin >> N;

	for (int i = 0; i < H.size(); i++)
		for (int j = 0; j < N.size(); j++)
		{
			if (H[j + i] != N[j])
				break;			
			else
				if (j == N.size() - 1)
					cnt++;			
		}
	
	cout <<cnt<<endl;

}