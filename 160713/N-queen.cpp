#include<iostream>
using namespace std;
 
int N;
int Answer = 0;
void input() {
    cin >> N;
}
 
int xA[20] = { 0 };
int yA[20] = { 0 };
int x_yA[100] = { 0 };
int y_xA[100] = { 0 };
 
 
 
 
void BackTracking(int x_, int y_, int n_)
{
 
    if (n_ == N)
    {
        Answer++;
        return;
    }
     
    if (y_ == N)
        return;
 
    xA[x_] = 1;
    yA[y_] = 1;
    x_yA[x_ - y_ + 50] = 1;
    y_xA[x_ + y_] = 1;
 
    for (int j = 0; j < N; j++)
    {
        if (xA[j] == 1)
            continue;
        if (x_yA[j - (y_+1) + 50] == 1)
            continue;
        if (y_xA[y_+1 + j] == 1)
            continue;
 
        if (xA[j] == 0 &&  yA[y_ + 1] == 0 && x_yA[j - (y_ + 1) + 50] == 0 && y_xA[j+ y_ + 1] == 0)
            BackTracking( j, y_ + 1, n_ + 1);
    }
 
    xA[x_] = 0;
    yA[y_] = 0;
    x_yA[x_ - y_ + 50] = 0;
    y_xA[x_ + y_] = 0;
 
}
 
void proccess() {
    for (int i = 0; i < N; i++)
        BackTracking(i, 0, 1);
 
}
 
void output() {
    cout << Answer << endl;
}
 
int main() {
    input();
    proccess();
    output();
}