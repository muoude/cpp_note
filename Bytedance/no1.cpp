//输入一个N，1<=N<=10^18，如果它可以开根号就开根号，否则就 -1，问：经过多少次操作这个数变到1。
// 输入 
// 10
// 输出
// 4
// 因为 10->9->3>->2->1


#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long long a;
	while (cin >> a){
		int res = 0;
		while (a != 1){
			int s = sqrt(a);
			if (s*s == a){
				++res;
				a = s;
			}
			else{
				//a-s*s是将a逐渐减1到能都开方，(s != 1)表示开方运算然后在给a赋值开方之后的数字
				res = res + a - s*s + (s != 1);
					a = s;
			}
		}
		cout << res;
	}
	return 0;
}
