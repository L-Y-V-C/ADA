// Hidalgo Machaca Diego Alejandro
// Valenzuela Calderon Luigi Yamil
#include <iostream>
#include <vector>

void sort(std::vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        int swapped = 0;
        for (int j = 0; j < A.size() - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j + 1], A[j]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

// Metodo solucionador -------------------------------------------------------------------
void fillVessel(int K, std::vector<int>& P, std::vector<float>& S) {
    for (int i = 0; i < P.size(); i++) {
        if (P[i] <= K) {
            S[i] += 1;
            K -= P[i];
        }
        else {
            S[i] += ((float)K / P[i]);
            K -= S[i] * P[i];
            break;
        }
    }
}
//----------------------------------------------------------------------------------------

int
main()
{
    int K = 55;

    std::vector<int> P;
    P.push_back(20); P.push_back(30); P.push_back(10); P.push_back(20); P.push_back(40); P.push_back(10);
    std::vector<float> S(P.size());
    sort(P);

    fillVessel(K, P, S);
    printf("Peso del buque : %d\n\n", K);
    printf("P : [ ");
    for (int i = 0; i < S.size(); i++)
        printf("%d\t", P[i]);
    printf("]\nS : [ ");
    for (int i = 0; i < S.size(); i++)
        printf("%.2f\t", S[i]);
    printf("]\n");
}
