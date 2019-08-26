/*N瓶放射性液体，每个都一定的质量和一定的体积。液体倒入反应堆时产生一定的能量。现在想让能量输出最大化，限制条件为
液体的总量不能超过临界质量M，反应堆的容量为V
输入六个参数
reactorCap 反应堆的容量
numberOfRadLiquid 现有小瓶的数量N
criticalMass 反应堆的最大临界质量M
volumes 按顺序表示N份放射性液体的体积
masses  按顺序表示N份放射性液体的质量
energies 按顺序表示N份放射性液体产生的能量
*/
/*二维背包问题：比01背包问题多一层循环*/
#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;


int maxEnergy(int reactorCap, int numberOfRadLiquid, int criticalMass,
	vector<int> volumes, vector<int> masses, vector<int> energies){
	vector<vector<int> > energy(reactorCap + 1, (vector<int>)(criticalMass + 1));

	for (int i = 0; i < numberOfRadLiquid; ++i){
		for (int v = reactorCap; v >= volumes[i]; --v){
			for (int m = criticalMass; m >= masses[i]; --m){
				energy[v][m] = energy[v][m]>(energy[v - volumes[i]][m - masses[i]] + energies[i]) ? energy[v][m] : energy[v - volumes[i]][m - masses[i]] + energies[i];
			}
		}
	}
	return energy[reactorCap][criticalMass];
}
int _tmain(int argc, _TCHAR* argv[])
{
	int reactorCap, numberOfRadLiquid, criticalMass;
	while (cin >> reactorCap >> numberOfRadLiquid >> criticalMass){
	vector<int> volumes(numberOfRadLiquid);
	vector<int> masses(numberOfRadLiquid);
	vector<int> energies(numberOfRadLiquid);
	for (int i = 0; i < numberOfRadLiquid; ++i){
		cin >> volumes[i];
	}
	for (int i = 0; i < numberOfRadLiquid; ++i){
		cin >> masses[i];
	}
	for (int i = 0; i < numberOfRadLiquid; ++i){
		cin >> energies[i];
	}
	int res = maxEnergy(reactorCap, numberOfRadLiquid, criticalMass,
		volumes, masses, energies);
	cout << res;
	}
	return 0;
}
