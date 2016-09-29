/*20160926 cm 重心问题NYOJ 3
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
struct Point
{	
	double x,y;
	Point(): x(0),y(0){}
};
int main()
{
	int pairNum(0);
	cin >> pairNum;
	while (pairNum--)
	{
		int pointNum(0);
		double result(0.0);
		Point resPoint;
		cin >> pointNum;
		Point *tempP = new Point[pointNum];
		for (int i = 0; i != pointNum; i++)
		{
			cin >> tempP[i].x >> tempP[i].y;
		}
		for (int j = 1; j <= pointNum; j++)
		{
			double temp(0.0);
			temp = (tempP[j % pointNum].x * tempP[j - 1].y - tempP[j % pointNum].y * tempP[j - 1].x)/2;
			result += temp;
			resPoint.x += temp * (tempP[j % pointNum].x + tempP[j - 1].x)/3;
			resPoint.y += temp * (tempP[j % pointNum].y + tempP[j - 1].y)/3;
		}
		cout <<setiosflags(ios::fixed);  
		if (result == 0.0)
		{
			cout<<"0.000 0.000"<<endl;
		}
		else
			cout<<setprecision(3)<<fabs(result)<<" "<<(resPoint.x + resPoint.y)/result<<endl;

		delete[] tempP;
	}
	system("pause");
	return 0; 
	

}
*/
