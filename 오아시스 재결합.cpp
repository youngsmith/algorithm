/* this kind of problem is very famous. there are some questions set at olympiad.
to be aware that stack always is kept in order is a point. */ 

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<unsigned long long> stk;
vector<unsigned long long> stk2;
int n;

int main(void) {
	cin >> n;
	
	unsigned long long a, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		
		int temp = 1;

		while (!stk.empty() && stk.back() <= a) {	
			cnt += stk2.back();
			if (stk.back() == a) temp += stk2.back();
			stk.pop_back();
			stk2.pop_back();
		}
		

		/*int idx;idx = stk.size() - 1;			
		while (idx >= 0 && stk[idx] == a) {
			cnt++, idx--;
		}
		if (idx >= 0) cnt++;
		*/

		if (!stk.empty()) cnt+=1;

		stk.push_back(a);
		stk2.push_back(temp);
	}

	cout << cnt << endl;

}
