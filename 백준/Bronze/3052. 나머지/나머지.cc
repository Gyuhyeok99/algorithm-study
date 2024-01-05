#include <iostream>
#include <algorithm> //sort() 함수를 사용을 위해 헤더에 추가
using namespace std;

int main() {
	int arr[10];
	int ans = 10;
	int x;
	for (int i = 0; i < 10; i++) {
		cin >> x;
		arr[i] = x % 42;
	}
	sort(arr, arr + 10); //배열 순서대로 정렬하는 함수
	for (int i = 0; i < 10; i++) {
		if (arr[i] == arr[i + 1]) {
			ans--;
		}
	}
	cout << ans;
	

	return 0;
}