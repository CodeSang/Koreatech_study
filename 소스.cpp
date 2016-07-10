#include<iostream>
using namespace std;

int main() {
	int N;
	cin>>N;

	int rslt = 0;

	for (int i = 0; i < N; i++) {
		int student;
		int apple;

		cin>>student>>apple;
		int count = 0;
		int temp = apple;
		//if (apple % student == apple) temp = apple;

		while ((apple / (student * ++count)) != 0) {
			if (apple % (student * count) < temp)
				temp = apple % (student * count);
		}
		rslt += temp;
	}
	cout<<rslt;
	return 0;
}