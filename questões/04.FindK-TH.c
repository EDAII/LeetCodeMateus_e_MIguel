#include <stdio.h>
#include <stdlib.h>


long long calcular_horas(int* pilhas, int tamanho, long long velocidade) {
    long long horas = 0;
    for (int i = 0; i < tamanho; i++) {
        horas += (pilhas[i] + velocidade - 1) / velocidade;
    }
    return horas;
}

// Função q encontra a menor velocidade usando busca binária
int minEatingSpeed(int* piles, int pilesSize, int h) {
    
    long long esquerda = 1; 
    long long direita = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > direita) {
            direita = piles[i];
        }
    }
    
    // Busca binária
    int resultado = direita;
    while (esquerda <= direita) {
        long long meio = esquerda + (direita - esquerda) / 2; // Evita estouro
        long long horas_necessarias = calcular_horas(piles, pilesSize, meio);
        
        if (horas_necessarias <= h) {          
            resultado = meio;
            direita = meio - 1;
        } else {
            
            esquerda = meio + 1;
        }
    }
    
    return resultado;
}
