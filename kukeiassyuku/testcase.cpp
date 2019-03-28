#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

mt19937 rnd;

int get_rand(int a) {
	if(a<=0) return 0;
	return rnd() % a;
}

void set_combination(vector<int> &v, int a, int b, int amt) {
	int len = b-a;
	if(len<amt) return;
	vector<int> cda(len);
	for(int i = 1; i <= len; i++) cda[i-1] = i;
	for(int i = 0; i < amt; i++) {
		int rand_index = get_rand(cda.size());
		v.push_back(cda[rand_index]);
		//cout << cda[rand_index] << endl;
		cda.erase(cda.begin()+rand_index);
	}
	sort(v.begin(),v.end());
}

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

	/*
	cout << num.size() << endl;
	for(int i = 0; i < num.size(); i++) {
		cout << (num[i]*2) << " " << amt[i] << endl;
	}
	*/
}

int main() {
	int seed;
	cin >> seed;
	rnd = mt19937(seed);

	for(int i = 0; i < 5; i++) {
		vector<int> ls;
		vector<int> ts;
		int n = 2+get_rand(25);
		int amt = 1+get_rand((n-2)/2);
		set_combination(ls,1,n,amt);
		for(int i = 0; i < amt; i++) {
			ts.push_back(1+get_rand(5));
		}
		calc(n,ls,ts);
	}

	for(int i = 0; i < 19; i++) {
		vector<int> ls;
		vector<int> ts;
		int n = 1+get_rand(100000);
		int amt = 1+get_rand((n-2)/2);
		set_combination(ls,1,n,amt);
		for(int i = 0; i < amt; i++) {
			ts.push_back(1+get_rand(3125));
		}
		calc(n,ls,ts);
	}

	{
		vector<int> num(50000);
		vector<int> amt(50000);
		for(int i = 0; i < 50000; i++) {
			num[i] = ((seed&0b01)!=0)?i+1:50000-i;
			amt[i] = ((seed&0b10)!=0)?i+1:50000-i;
		}
		calc(50000,num,amt);
	}

	cout << 0 << endl;
}
