
/*第一行输入两个正整数，空格隔开，需要进行映射的数目，调试时发送的语音指令条数M*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	int n, m;
	while (cin >> n){
		cin >> m;
		map<string, string> order;
		for (int i = 0; i < n; ++i){
			string orderc;
			string ordere;
			cin >> orderc >> ordere;
			order[orderc] = ordere;
		}
		vector<string> cmd(m);
		for (int i = 0; i < m; ++i){
			cin >> cmd[i];
		}
		for (auto val : cmd){     //可以这样写，记住
			if (order.find(val) != order.end()){
				auto it = order.find(val);
				cout << it->second << endl;
			}
		}
	}
	//while (1);
	return 0;
}
