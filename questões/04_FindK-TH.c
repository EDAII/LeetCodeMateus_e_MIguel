#include <stdlib.h>

// Função de comparação usada no qsort
int comparar(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Conta quantos pares têm distância <= dist
int contar_pares(int* nums, int n, int dist) {
    int total = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && nums[j] - nums[i] <= dist) {
            j++;
        }
        total += j - i - 1;
    }

    return total;
}

// Retorna o k-ésimo menor par de distância
int smallestDistancePair(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), comparar);

    int menor = 0;
    int maior = nums[numsSize - 1] - nums[0];

    // Busca binária para encontrar a menor distância
    while (menor < maior) {
        int meio = menor + (maior - menor) / 2;

        if (contar_pares(nums, numsSize, meio) >= k) {
            maior = meio;
        } else {
            menor = meio + 1;
        }
    }

    return menor;
}
