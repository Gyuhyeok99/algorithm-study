#include <iostream>

using namespace std;

struct big {
    int weight;
    int height;
    int rank = 1;
};
int main() {
    big big[51];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> big[i].weight >> big[i].height;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(big[i].weight < big[j].weight && big[i].height < big[j].height) {
                big[i].rank++;
            }
        }
        cout << big[i].rank << endl;
    }
    return 0;
}
