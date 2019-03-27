#include <iostream>
#include <vector>
using namespace std;

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n==0) break;

		int dp[127][126] = {};
		for(int i = 0; i < n; i++) {
			int x,y,v;
			cin >> x >> y >> v;
			dp[x][y/v]++;
		}

		for(int y = 1; y <= 125; y++) {
			for(int x = 1; x <= 125; x++) {
				dp[x][y] = max(dp[x][y-1],max(dp[x-1][y-1],dp[x+1][y-1]))+dp[x][y];
			}
		}

		int ans = 0;
		for(int x = 1; x <= 125; x++) {
			ans = max(ans,dp[x][125]);
		}
		cout << ans << endl;
	}
	return 0;
}
