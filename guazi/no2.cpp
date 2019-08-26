/*
输入一个字符串，看大写字母的用法是否正确
如果字符全部是小写字母则正确
如果第一个字符是大写字母，则继续判断，若后面的都是大写字母或者小写字母则正确
*/

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

bool judge1(string &s,int begin,int end){
	bool res1 = true;
	for (int i = begin; i <= end; ++i){
		if ((s[i] - 'A') < 0 || (s[i] - 'A') >= 26)
			return false;
	}
	return res1;
}
bool judge2(string &s, int begin, int end){
	bool res2 = true;
	for (int j = begin; j <= end; ++j){
		if ((s[j] - 'a') < 0 || (s[j] - 'a') >= 26)
			return false;
	}
	return res2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
	while (cin >> s){
		bool res = true;
		int len = s.length();
		if (len > 1 && (s[0] - 'A') >= 0 && (s[0] - 'A') < 26){
			res = judge1(s, 1, len - 1) || judge2(s, 1, len - 1);
		}
		if (len > 1 && (s[0] - 'a') >= 0 && (s[0] - 'a') < 26){
			res = judge2(s, 0, len - 1);
		}
		cout << res;	
	}
	return 0;
}
