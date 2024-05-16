#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;

    cin >> n;

    int num_cnt[10] = {0};

    for(char c : n) {
        num_cnt[c-'0']++;
    }

    num_cnt[6] = (num_cnt[6] + num_cnt[9] + 1) / 2;

    int max = num_cnt[0];

    for(int i = 1; i < 9; i++) {
        if(max < num_cnt[i]) max = num_cnt[i];
    }

    cout << max;

    return 0;
}