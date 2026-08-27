
#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

void task_scheduling(vector<int>& duracao, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int indice_minimo = i;
        for (int j = i + 1; j < n; ++j) {
            if (duracao[j] < duracao[indice_minimo]) {
                indice_minimo = j;
            }
        }
        swap(duracao[i], duracao[indice_minimo]);
    }

    long long tempo_acumulado = 0;
    long long soma_total = 0;
    for (int i = 0; i < n; ++i) {
        tempo_acumulado += duracao[i];
        soma_total += tempo_acumulado;
    }

    for (int i = 0; i < n; ++i) {
        cout << duracao[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n" << soma_total << "\n";
}


int main() {
    FAST_IO;

    int n;
    if (cin >> n) {
        vector<int> duracao(n);
        for (int i = 0; i < n; ++i) cin >> duracao[i];

        task_scheduling(duracao, n);
    }
    return 0;

}