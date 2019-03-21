#include <iostream>
#include <vector>
using namespace std;

void calc(int n, vector<int> &num, vector<int> &amt) {
	if(num.size()!=amt.size()) return;
	int len = num.size();
	vector<int> imos(n+1);
	for(int i = 0; i < len; i++) {
		int _num = num[i];
		int _amt = amt[i];
		for(int j = _num; j <= n; j+=_num) {
			imos[j] += _amt*(((j/_num)%2!=0)?1:-1);
		}
	}
	cout << n << endl;
	cout << imos[0];
	for(int i = 1; i < n; i++) {
		imos[i] += imos[i-1];
		cout << " " << imos[i];
	}
	cout << endl;
}

int main() {
	{
		vector<int> num{2,3,5,7,11};
		vector<int> amt{1,1,1,1,1};
		calc(25,num,amt);
	}
	/*
	{
		vector<int> num(1000);
		vector<int> amt(1000,1000);
		for(int i = 1; i <= 1000; i++) num[i-1] = i;
		calc(100000,num,amt);
	}
	*/
	{
		vector<int> num{2,4,8,16,32};
		vector<int> amt{2,4,8,16,32};
		calc(1024,num,amt);
	}
	{
		vector<int> num{1,5,25,125,625,3125};
		vector<int> amt{5,4,3,2,1,0};
		calc(1024,num,amt);
	}
	cout << 0 << endl;
}
