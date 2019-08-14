//辗转相除法求最大公约数：欧几里得算法
//用较大数除以较小数得到的余数，再将较小的数除以上面的余数如此辗转相除，直到得到的余数为0
//题目给出的难点是输入的数比较大
//用字符串输入
#include <iostream>
#include <string>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
	return b==0? a : gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	string str;//输入较大的一个数
	while(cin >> str){
		unsigned long long a；
		cin >> a;
    //较大的数以字符串的形式输入
    	unsigned long long b=0；
		for(int i=0; i<str.size(); ++i ){
			b = (b*10 + str[i]-'0') % a;    //从高位到低位进行除法计算，最终得到第一个余数
		}
		cout << gcd(a, b) << endl;
	}
	return 0;
}
