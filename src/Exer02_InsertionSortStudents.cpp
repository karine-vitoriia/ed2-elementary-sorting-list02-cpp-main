

#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

struct Student {
    int id;
    int grade;
};
    void insertion_sort_students(vector<Student>& vetor, int n) {
        for (int i = 1; i < n; ++i) {
            Student chave = vetor[i];
            int j = i - 1;
            while (j >= 0 && vetor[j].grade > chave.grade) {
                vetor[j + 1] = vetor[j];
                j = j - 1;
            }
            vetor[j + 1] = chave;
        }
    }



int main() {
    FAST_IO;

    int n;
    if (cin >> n) {
        vector<Student> estudantes(n);
        for (int i = 0; i < n; ++i) cin >> estudantes[i].id >> estudantes[i].grade;

        insertion_sort_students(estudantes, n);

        for (int i = 0; i < n; ++i) cout << estudantes[i].id << " " << estudantes[i].grade << "\n";

        return 0;
    }
}
