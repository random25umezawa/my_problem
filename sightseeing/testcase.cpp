#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

mt19937 rnd;

int get_rand(int a) {
		return rnd() % a;
}

void case_random(int n, int m, int s, int max_road_num, int max_road_len) {
	printf("%d %d %d\n",n,m,s);
	vector<int> roads(n+1);
	vector<int> added_node;
	vector<bool> is_added(n+1);
	for(int i = 0; i < n; i++) {
		int p1;
		if(added_node.size()>0) {
			p1 = added_node[get_rand(added_node.size())];
		}else {
			p1 = 1+get_rand(max_road_num);
		}
		int p2 = p1;
		while(p1==p2) {
			p2 = 1+get_rand(max_road_num);
		}
		int len = 1+get_rand(max_road_len);
		printf("%d %d %d\n",p1,p2,len);
		roads[i+1] = len;
		if(!is_added[p1]) {
			is_added[p1] = true;
			added_node.push_back(p1);
		}
		if(!is_added[p2]) {
			is_added[p2] = true;
			added_node.push_back(p2);
		}
	}
	/*
	for(int i = 0; i < n; i++) {
		int p1 = 1+get_rand(max_road_num);
		int p2 = p1;
		while(p1==p2) {
			p2 = 1+get_rand(max_road_num);
		}
		int len = 1+get_rand(max_road_len);
		printf("%d %d %d\n",p1,p2,len);
		roads[i+1] = len;
	}
	*/
	for(int i = 0; i < m; i++) {
		int road_index = 1+get_rand(n);
		int pos = get_rand(roads[road_index]+1);
		printf("%d %d\n",road_index,pos);
	}
	vector<int> spots(s);
	int pre_spot = -1;
	for(int i = 0; i < s; i++) {
		int spot_index = pre_spot;
		while(pre_spot==spot_index) {
			spot_index = 1+get_rand(m);
		}
		spots[i] = spot_index;
		pre_spot = spot_index;
	}
	cout << spots[0];
	for(int i = 1; i < s; i++) {
		cout << " " << spots[i];
	}
	cout << endl;
}

int main() {
	int seed;
	cin >> seed;
	rnd = mt19937(seed);
	for(int i = 0; i < 5; i++) {
		case_random(2+get_rand(5),2+get_rand(5),2+get_rand(5),5,5);
	}
	for(int i = 0; i < 5+get_rand(11); i++) {
		case_random(25+get_rand(125),125+get_rand(625),625+get_rand(3125),125,625);
	}
	for(int i = 0; i < 5; i++) {
		case_random(500,2500,12500,500,2500);
	}
	cout << "0 0 0" << endl;
}
