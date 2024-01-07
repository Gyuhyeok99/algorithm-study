#include <iostream>


using namespace std;

int main() {
	int size;
	cin >> size;
	double* arr = new double[size];
	int max = 0;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	double sum = 0;
	for (int i = 0; i < size; i++) {
		arr[i] = arr[i] / max * 100;
		sum += arr[i];
	}
	double average = sum / size;
	cout << average;
	

	
	return 0;

}