#include <iostream>
using namespace std;

void naiveSearch(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin.ignore();
    getline(cin, text);
    cout << "Enter pattern to search: ";
    getline(cin, pattern);

    naiveSearch(text, pattern);
    return 0;
}
