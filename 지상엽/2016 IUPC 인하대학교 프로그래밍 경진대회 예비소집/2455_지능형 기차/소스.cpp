#include<iostream>
using namespace std;


int main() {
	int now_ = 0; 
	int max_ = 0;
	for (int i = 0; i < 4; i++)
	{
		int out_, in_;
		cin >> out_ >> in_;

		now_ = now_ - out_ + in_;

		if (max_ < now_)
			max_ = now_;
	}

	cout << max_ << endl;
}