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
void fillVessel(int K, std::vector<int>& P, std::vector<int>& S, int& conteinerQuantity) {
    for (int i = 0; i < P.size(); i++) {
        if (P[i] <= K) {
            S[i] += 1;
            conteinerQuantity++;
            K -= P[i];
        }
    }
}
//----------------------------------------------------------------------------------------

int
main()
{
    int K = 50;
    int conteinerQuantity = 0;

    std::vector<int> P;
    P.push_back(20); P.push_back(30); P.push_back(10); P.push_back(20); P.push_back(40); P.push_back(10);
    std::vector<int> S(P.size());
    sort(P);

    fillVessel(K, P, S, conteinerQuantity);
    printf("Peso del buque : %d\n\n", K);
    for (int i = 0; i < S.size(); i++)
        printf("( Peso: %d ) - ( Sol: %d)\n", P[i], S[i]);
    printf("\nCantidad de contenedores: %d", conteinerQuantity);
}