#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 1000;
int n, i;
int p[MAX];
int main(void){
    cin >> n;
    for(int i =0; i<n ;i++){
    	cin >> p[i];	
	}
	
	sort(p, p+n);
    int sum = 0;
	for(int i =0; i<n ;i++){
    	sum += p[i]*(n-i);
	}
	
	cout << sum << endl;
	return 0;
}