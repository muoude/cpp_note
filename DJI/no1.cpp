/*玩游戏：第一行输入case数T（0<T<20）,对于每一个case，第一行输入游戏的数目N（0<N<11），总时间X（0<X<1000）用空格分割。
从第二行到第N + 1行输入的是每个游戏的成就值Ai（0<Ai<10000）, 所需时间Bi(0<Bi<10000)* /

	/*思路：与剑指上的组合问题相似，在给出的游戏中选择几个时间总和小于等于总时间X的游戏，比较其成就值的和*/

#include<iostream>
#include<vector>
using namespace std;


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
		int max = 0, ans = 0;
		Match(game, time_num, 0, ans, max);
		cout << max << endl;
	}
//	while (1);
	return 0;
}

