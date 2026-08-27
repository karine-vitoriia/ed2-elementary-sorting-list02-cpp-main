
#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int is_sorted(const vector<int>& vetor, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (vetor[i] > vetor[i + 1]) {
            return 0; // falso interromp na hora
        }
    }
    return 1; // verdadeiro
}


int main() {
    FAST_IO;

    int n;
    if (cin >> n) {
        vector<int> vetor(n);
        for (int i = 0; i < n; ++i) cin >> vetor[i];

        if (is_sorted(vetor, n)) cout << "SORTED\n";
        else cout << "UNSORTED\n";
    }
    return 0;
}
