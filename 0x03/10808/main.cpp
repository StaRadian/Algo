#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    int alpa_cnt[26] = {0};

    for(char c : s) {
        alpa_cnt[c - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        cout << alpa_cnt[i] << " ";
    }

    return 0;
}