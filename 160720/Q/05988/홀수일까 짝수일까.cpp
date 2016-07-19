#include<string>
#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string temp;
		cin >> temp;
		if ((temp[temp.size() - 1] - '0') % 2 == 0)
			cout << "even" << endl;
		else
			cout << "odd" << endl;
	}
}