/*玩游戏：第一行输入case数T（0<T<20）,对于每一个case，第一行输入游戏的数目N（0<N<11），总时间X（0<X<1000）用空格分割。
从第二行到第N + 1行输入的是每个游戏的成就值Ai（0<Ai<10000）, 所需时间Bi(0<Bi<10000) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*1、递归，组合。思路：与剑指上的组合问题相似，在给出的游戏中选择几个时间总和小于等于总时间X的游戏，比较其成就值的和*/ 
void Match(vector<pair<int, int> > game, int time_sum, int index, int &ans, int &max){
	if (index == game.size() && time_sum>=0){
		      if (ans > max)
		           	max = ans;
		     return;
	}
	if (index == game.size() && time_sum < 0)
	       	return;
 	ans += game[index].first;
  Match(game, time_sum - game[index].second, index + 1, ans, max);
	ans -= game[index].first;
	Match(game, time_sum, index + 1, ans, max);
}

/*
背包问题（动态规划）
f[i][v]表示放入第i个时恰好放入背包中
问题拆分成两种情况：一种是第i个不放入背包中，即f[i-1][v]，第二种是第i个放入背包即为f[i-1][v-c[i]]
因此此时价值的最大值即为f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}
为了同时可以得到f[i-1][v]，与f[i-1][v-c[i]],可以从大递减
根据画的基本表进行分析从上到下从右到左
*/
int Match1(vector<pair<int, int> > game, int time_num, int game_num){
	vector<int> value_sum(time_num + 1);
	for (int i = 0; i < game_num; ++i){
		int cost = game[i].second;
		int value = game[i].first;
		for (int j = time_num; j >= cost;--j){
			value_sum[j]=max(value_sum[j], value_sum[j - cost] + value);
		}
	}
	return value_sum[time_num];
}

int main(){
	int case_num;
	cin >> case_num;
	for (int i = 0; i < case_num; ++i){
		int game_num, time_num;
		cin >> game_num >> time_num;
		vector<pair<int, int> > game(game_num);
		for (int j = 0; j < game_num; ++j){
			cin >> game[j].first >> game[j].second;
		}
		//int max = 0, ans = 0;
		//Match(game, time_num, 0, ans, max);
    int max= Match1(game, time_num, game_num);
		cout << max << endl;
	}
//	while (1);
	return 0;
}
