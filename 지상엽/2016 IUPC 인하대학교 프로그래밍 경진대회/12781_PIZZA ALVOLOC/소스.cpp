#include<iostream>
#include<algorithm>
using namespace std;
// FAIL

struct point {
	double x;
	double y;
	//point(double x, double y): x(x),y(y){}
};
int answer = 0;
point p[5];

void input() {
	for (int i = 1; i <= 4; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
}

void process() {

	if ((p[1].x - p[2].x) * (p[3].y - p[4].y) - (p[1].y - p[2].y) * (p[3].x - p[4].x) == 0)
		return;
	
	p[0].x = ((p[1].x * p[2].y - p[1].y * p[2].x)* (p[3].x - p[4].x) - (p[1].x - p[2].x) * (p[3].x * p[4].y - p[3].y * p[4].x)) 
		/ ((p[1].x - p[2].x) * (p[3].y - p[4].y) - (p[1].y - p[2].y) * (p[3].x - p[4].x));

	p[0].y = ((p[1].x * p[2].y - p[1].y * p[2].x)* (p[3].y - p[4].y) - (p[1].y - p[2].y) * (p[3].x * p[4].y - p[3].y * p[4].x))
		/ ((p[1].x - p[2].x) * (p[3].y - p[4].y) - (p[1].y - p[2].y) * (p[3].x - p[4].x));


	if (p[0].x > min(p[1].x, p[2].x) && p[0].x < max(p[1].x, p[2].x)
		&& p[0].x > min(p[3].x, p[4].x) && p[0].x < max(p[3].x, p[4].x))
		answer = 1;

	double a = (p[2].y - p[1].y) / (p[2].x - p[1].x);
	double b = a * p[1].x + p[1].y;

	if ((a * p[3].x + b == p[3].y) || (a * p[4].x + b == p[4].y))
		answer = 0;

	a = (p[4].y - p[3].y) / (p[4].x - p[3].x);
	b = a * p[3].x + p[3].y;

	if ((a * p[1].x + b == p[1].y) || (a * p[2].x + b == p[2].y))
		answer = 0;

}

void output() {
	cout << answer << endl;
}

int main() {
	input();
	process();
	output();
}
