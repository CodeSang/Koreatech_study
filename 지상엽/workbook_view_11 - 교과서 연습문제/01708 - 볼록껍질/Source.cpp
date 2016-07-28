#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#define PI 3.14159265358979323846
using namespace std;

//http://59.23.113.171/30stair/convex_hull/convex_hull.php?pname=convex_hull
struct sPoint {
	int x;
	int y;
	double slope;
	sPoint(int x, int y, double slope = 0):x(x),y(y),slope(slope){}

	bool operator< (const sPoint& lef) const
	{
		return slope < lef.slope;
	}
};

int n;
vector<sPoint> v;
stack<sPoint> st;
int cnt = 1;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(sPoint(x, y));
	}
}

double getAngle(sPoint A, sPoint B)
{
	//A 기준으로 만들어진 각도 이다.
	double angle = 0;

	if (A.x == B.x)
		if (A.y > B.y)
			angle = 270;
		else
			angle = 90;
	else{
		angle = atan2(B.y - A.y, B.x - A.x) * 180 / 3.14159265;
		angle = round(angle*1000);
		angle /= 1000;

		if (angle <= 0)
		{
			if (A.x > B.x)
				if (A.y < B.y)
					angle += 180;
				else
					angle += 360;
			else
				angle += 360;
		}
	}
	return angle;
}

void process() {

	int miniY = 40000;
	int miniX = -40000;

	// 가장 우측 하단 점을 구한다.
	for (auto iter : v)
	{
		if (miniY > iter.y)
		{
			miniY = iter.y;
			miniX = iter.x;
		}
		else if (miniY == iter.y)
		{
			if (miniX < iter.x)
				miniX = iter.x;
		}
	}

	// Slope 설정
	for (auto iter = v.begin(); iter != v.end() ; iter++)
	{
		double slope = 0;
		if (iter->x == miniX)
		{
			if (miniY == iter->y) iter->slope = 0;
			else iter->slope = 90;
		}
		else
		{
			iter->slope = atan2((double)(miniY- iter->y ) , (double)( miniX- iter->x )) * 180 / PI;
			if (iter->slope <= 0)
				iter->slope = 180 + iter->slope;
		}
	}

	v.push_back( {miniX, miniY,360} );

	sort(v.begin(), v.end());
	// 여기서 부터는 slope를 그전 점과의 기울기로 사용함.

	st.push(v[0]);
	st.push(v[1]);
	v[0].slope = 0;
	v[1].slope = getAngle(v[0], v[1]);
	for (int i = 2; i < v.size(); i++)
	{
		while(true){
			double tempAngle = getAngle(st.top(), v[i]);
			if (st.top().slope < tempAngle) {
				v[i].slope = tempAngle;
				st.push(v[i]);
				break;
			}
			else {
				st.pop();
			}
		}
	}
}

void output() {
	cout << st.size()-1 << endl;
}

int main() {
	input();
	process();
	output();
}