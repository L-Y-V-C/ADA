// Hidalgo Machaca, Diego Alejandro
// Valenzuela Calderon, Luigi Yamil

#include <iostream>
#include <vector>

struct data {
    int beneficio, tiempo, indice;
    data(int in_b, int in_t, int in_in) 
        : beneficio(in_b), tiempo(in_t), indice(in_in) {}
};

void sort(std::vector<data>& A) {
    for (int i = 0; i < A.size(); i++) {
        int swapped = 0;
        for (int j = 0; j < A.size() - i - 1; j++) {
            if (A[j].beneficio < A[j + 1].beneficio) {
                std::swap(A[j + 1], A[j]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int tareas(std::vector<data>& T, std::vector<int>& S) { 
    int suma = 0;
    int size = T.size();
    for (int i = 0; i < T.size(); i++) {
        for (int j = 0; j < T.size(); j++) {
            if (T[i].tiempo >= (size - j) && S[size - j - 1] == 0)
                S[size - j - 1] = 1;
        }
    }
    for (int i = 0; i < T.size(); i++)
        if (S[i])
            suma += T[i].beneficio;
    return suma;
}

int
main()
{
    // numero de tareas
    int n = 4;

    // vector de tareas
    std::vector<data> T;

    // vector solucion
    std::vector<int> S(n);

    int inputG[] = { 50, 10, 15, 30 };
    int inputD[] = { 2, 1, 2, 1 };

    for (int i = 0; i < n; i++)
        T.push_back(data(inputG[i], inputD[i], i));
    sort(T);

    int beneficioTotal = tareas(T, S);

    printf("\nTareas seleccionadas: ");
    for (int i = 0; i < n; i++)
        if (S[i])
            printf("%d ", T[i].indice + 1);
    printf("\n\nBeneficio total: %d\n", beneficioTotal);
}