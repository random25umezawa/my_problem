#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n==0) break;
		vector<P> arr(n);
		for(int i = 0; i < n; i++) {
			int x,y,v;
			cin >> x >> y >> v;
			arr[i].first = (y/v);
			arr[i].second = (x);
		}
		sort(arr.begin(),arr.end());

		vector<vector<int> > graph(n);
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				int x1 = arr[i].second;
				int y1 = arr[i].first;
				int x2 = arr[j].second;
				int y2 = arr[j].first;
				if(abs(y1-y2)>=abs(x1-x2)) {
					graph[i].push_back(j);
				}
			}
		}

		vector<int> dp(n,1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j];
				dp[next] = max(dp[next],dp[i]+1);
			}
		}

		int ans = 0;
		for(int i = 0; i < n; i++) {
			ans = max(ans,dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
