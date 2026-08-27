

#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

void insert_sorted(vector<int>& vetor, int n, int chave) {
    vetor.push_back(0);
    int j = n - 1;
    while (j >= 0 && vetor[j] > chave) {
        vetor[j + 1] = vetor[j];
        j = j - 1;
    }
    vetor[j + 1] = chave;
}

int main() {
    FAST_IO;

    int n, chave;
    if (cin >> n >> chave) {
        vector<int> vetor(n);
        for (int i = 0; i < n; ++i) cin >> vetor[i];

        insert_sorted(vetor, n, chave);

        for (int i = 0; i <= n; ++i) {
            cout << vetor[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}