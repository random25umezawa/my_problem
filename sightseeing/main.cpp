#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF (1<<25)

using namespace std;
typedef pair<int,int> P;
typedef vector<vector<P> > graph;

int ds[501][501] = {};
int road[501][3] = {};
int spot[2501][2] = {};
int query[12500] = {};

void dijkstra(int s, graph &g) {
	for(int i = 1; i <= 500; i++) {
		ds[s][i] = INF;
	}
	vector<bool> arrived(501);
	priority_queue<P> q;
	P start(0,s);
	ds[s][s] = 0;
	q.push(start);
	while(!q.empty()) {
		P p = q.top();	q.pop();
		int cost = p.first;
		int now = p.second;
		if(arrived[now]) continue;
		arrived[now] = true;
		//if(ds[s][now]==INF || ds[s][now]>cost) {
			//ds[s][now] = cost;
			for(int i = 0; i < g[now].size(); i++) {
				P e = g[now][i];
				int next = e.first;
				int d = e.second;
				int new_cost = cost+d;
				if(ds[s][next]>new_cost) {
					ds[s][next] = new_cost;
					P new_edge(new_cost,next);
					q.push(new_edge);
				}
			}
		//}
	}
}

int main() {
	while(true) {
		int n,m,s;
		cin >> n >> m >> s;
		if(n==0&&m==0&&s==0) break;

		for(int i = 1; i <= n; i++) {
			int l,r,d;
			cin >> l >> r >> d;
			road[i][0] = l;
			road[i][1] = r;
			road[i][2] = d;
		}
		for(int i = 1; i <= m; i++) {
			int p,a;
			cin >> p >> a;
			spot[i][0] = p;
			spot[i][1] = a;
		}

		graph g(501);
		for(int i = 1; i <= n; i++) {
			int l = road[i][0];
			int r = road[i][1];
			int d = road[i][2];
			P p1(r,d);
			P p2(l,d);
			g[l].push_back(p1);
			g[r].push_back(p2);
		}

		for(int i = 1; i <= 500; i++) {
			dijkstra(i,g);
		}

		for(int i = 0; i < s; i++) {
			cin >> query[i];
		}

		int ans = 0;
		int now = query[0];
		for(int i = 1; i < s; i++) {
			int next = query[i];

			int now_p = spot[now][0];
			int now_a = spot[now][1];
			int now_l = road[now_p][0];
			int now_r = road[now_p][1];
			int now_d = road[now_p][2];
			int next_p = spot[next][0];
			int next_a = spot[next][1];
			int next_l = road[next_p][0];
			int next_r = road[next_p][1];
			int next_d = road[next_p][2];

			if(now_p==next_p) {
				ans += abs(now_a-next_a);
			}else {
				int r1 = now_a + ds[now_l][next_l] + next_a;
				int r2 = (now_d-now_a) + ds[now_r][next_l] + next_a;
				int r3 = now_a + ds[now_l][next_r] + (next_d-next_a);
				int r4 = (now_d-now_a) + ds[now_r][next_r] + (next_d-next_a);
				ans += min(min(r1,r2),min(r3,r4));
			}

			now = next;
		}
		cout << ans << endl;
	}
}
