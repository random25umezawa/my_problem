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

int calc(vector<int> &x, vector<int> &y, vector<int> &v) {
	if(x.size()==y.size()&&y.size()==v.size()) {
		cout << x.size() << endl;
		for(int i = 0; i < x.size(); i++) {
			printf("%d %d %d\n",x[i],y[i],v[i]);
		}
	}
}

int main() {
	int seed;
	cin >> seed;
	rnd = mt19937(seed);

	for(int i = 0; i < 5; i++) {
		int n = 1+get_rand(25);
		vector<int> x(n),y(n),v(n);
		for(int j = 0; j < n; j++) {
			x[j] = 1+get_rand(25);
			v[j] = 1+get_rand(25);
			y[j] = v[j]*(1+get_rand(25));
		}
		calc(x,y,v);
	}

	for(int i = 0; i < 20; i++) {
		int n = 125;
		vector<int> x(n),y(n),v(n);
		for(int j = 0; j < n; j++) {
			x[j] = get_rand(10000+1);
			v[j] = 1+get_rand(10000);
			y[j] = v[j]*(get_rand(10001/v[j]));
		}
		calc(x,y,v);
	}

	cout << 0 << endl;
}
