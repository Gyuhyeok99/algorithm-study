#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int a, b, v;
	int day;
	std::cin >> a >> b >> v;

	day = (v - a) / (a - b) + 1;
	if ((v - a) % (a - b) != 0) {
		day += 1;
	}
	std::cout << day;
	return 0;
}