/*公司有N名员工，财务人员按照特定的顺序排列员工的工资。现在按照工资的频次降序排列，给定清单中所有频次
较高的工资将在频次较低的工资之前出现。如果相同数量的员工都有相同的工资，即按照给定清单中该工资第一次
出现的顺序排序   
输入：
num 一个整数，表示员工的人数
salaries 一个正整数列表，表示N名员工的工资
*/

1、稳定的排序方法，将排好序的工资和对应的编号稳定排序
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//定义降序排列
bool cmd(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	while (cin >> num){
		unordered_map<int, int>  val;//用map存放工资以及其对应的频次
		vector<pair<int, int> > res;
		int valary;
		for (int i = 0; i < num; ++i){
			cin >> valary;
			if (val.find(valary) == val.end()){
				val[valary] = 1;
				res.push_back(pair<int, int>(valary, 1));//利用vector的时候先出现先存入，然后按照稳定排序不会破坏其位置
			}
			else{
				++val[valary];
				for (auto &money : res){
					if (money.first == valary)
						++money.second;
				}
				//改变其中的值的时候要使用引用
			}
		}
		stable_sort(res.begin(), res.end(), cmd);//记住这个排序的指令，降序还是升序可以自己进行定义
		for (auto people : res){
			for (int j = 0; j < people.second; ++j){
				cout << people.first << " ";
			}
		}
	}
	return 0;
}
2、这种方法不能保证相同频次的先出现的工资会先输出，不是稳定的排序方法
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
