#include <bits/stdc++.h>   
using namespace std; 
double go(const vector<double>& nums) {
    int n = nums.size();
    double mx = -1e9;  
    for (int start = 0; start < n; ++start) {
        double curr = 1.0; 
        for (int end = start; end < n; ++end) {
            curr *= nums[end];
            mx = max(mx, curr);
        }
    } 
    return mx;
}

int main() { 
    int n;
    cin >> n;
    
    vector<double> nums(n); 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
     
    double ret = go(nums); 
    cout << fixed << setprecision(3) << ret << endl;
    
    return 0;
}