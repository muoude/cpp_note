/*公司有N名员工，财务人员按照特定的顺序排列员工的工资。现在按照工资的频次降序排列，给定清单中所有频次
较高的工资将在频次较低的工资之前出现。如果相同数量的员工都有相同的工资，即按照给定清单中该工资第一次
出现的顺序排序   
输入：
num 一个整数，表示员工的人数
salaries 一个正整数列表，表示N名员工的工资
*/

#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	while (cin >> num){
		map<int, int> res;
//		pair<map<int, int>::iterator, bool> ret;
		int salary;
		for (int i = 0; i < num; ++i) {
			cin >> salary;
/*	此时将当前输入工资和1组成pair，若当前map中已经含有当前工资，则不进行操作，但是会返回迭代器和false
	若当前map中不含有当前工资则会进行插入操作，并返回该节点的迭代器和true		
          ret=res.insert(pair<int, int>(salary, 1));
			if (!ret.second){
			  //已经存在的当前的工资则将相应工资的频次加1；
				++res[salay];
*/
			if (res.find(salary) == res.end()){
				res.insert(pair<int, int>(salary, 1));
			}
			else{
				++res[salary];
			   }
			}
		vector<int> result;
		int max = 0;
		map<int, int>::iterator iter;
		int index=0;
		while (res.size()){
			for (iter = res.begin(); iter != res.end(); ++iter){
				if (iter->second > max){
					max = iter->second;
					index = iter->first;
				}
			}
			while (max--){
				result.push_back(index);
			}
			res.erase(index);
		}
		for (int i = 0; i < num; ++i){
			cout << result[i]<<" ";
		}
	}
	return 0;
}
