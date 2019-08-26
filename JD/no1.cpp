/*
现有N名学生编号从1到N，审稿分别为Hi,现可以将这些学生进行分组，同组的学生的编号是连续的，让每组学生从左侧到右
按身高从低到高进行排序，使得最后所有学生同样满足从左到右仍是从低到高，那么最多可以分几组
*/

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	while (cin >> N){
		vector<int> high(N);
		vector<int> ord(N);//必须标记容量，否则后面的赋值语句错误
		unordered_set<int> result;
		for (int i = 0; i < N; ++i){
			cin >> high[i];
			ord[i] = high[i];
		}
		sort(ord.begin(),ord.end());
		int res = 0;
		for (int i = 0; i < N; ++i){
			if (result.find(high[i]) != result.end())
				result.erase(high[i]);
			else
				result.insert(high[i]);
			if (result.find(ord[i]) != result.end())
				result.erase(ord[i]);
			else
				result.insert(ord[i]);
			if (result.size() == 0)
				++res;
		}
		cout << res;
	}
	return 0;
}
