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

		while (!stk.empty() && stk.back() <= a) {	// 이러한 작업을 했을 때, 스택 내부는 항상 내림차순으로 유지된다는 확신이 부족했음.
			cnt += stk2.back();
			if (stk.back() == a) temp += stk2.back();
			stk.pop_back();
			stk2.pop_back();
		}
		

		/*int idx;idx = stk.size() - 1;					// 시간 초과의 주요 원인
		while (idx >= 0 && stk[idx] == a) {
			cnt++, idx--;
		}
		if (idx >= 0) cnt++;
		*/

		// 비었거나, 탑보다 작거나. -> 내가 처리해주고 싶은 경우 : 후자만.
		if (!stk.empty()) cnt+=1;

		stk.push_back(a);
		stk2.push_back(temp);
	}

	cout << cnt << endl;

}