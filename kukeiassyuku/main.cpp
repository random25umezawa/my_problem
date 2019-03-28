#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> P;

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n==0) break;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<int> d_arr(n+1);
		for(int i = 0; i < n; i++) {
			d_arr[i+1] = arr[i+1]-arr[i];
		}
		vector<P> ans;
		for(int i = 1; i < n; i++) {
			if(d_arr[i]>0) {
				int d = d_arr[i];
				P temp_ans(i*2,d);
				ans.push_back(temp_ans);
				for(int j = i; j <= n; j+=i) {
					d_arr[j] += d*(((j/i)%2==0)?1:-1);
				}
			}
		}
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	return 0;
}
