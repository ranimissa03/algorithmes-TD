Question1:

Entrée: n
Sortie: compteur
Début
compteur←0 
pour i de 2 à n-1 faire
  est_premier←Vrai
  pour j de 2 à racine(i) faire
    si i mod j =0 alors
      est_premier ← Faux
      sortir du boucle
    fin si
   fin pour
   si est_premier ← Vrai alors
    compteur ←compteur+1
écrire ("nombre des nombres premieurs inferieur à ",n "est ",compteur)
Fin
Question2:

Entré: n, est_prmiers tableau qui renvoie des booléen
Sortie: compteur
Début
compteur ←0
pour i de 0 à n-1 faire 
 est_premiers[i] ←Vrai
Fin pour
est_premiers[o] ←Faux
est_premiers[1] ←Faux
pour j de 2 à racine(n) faire 
 si est_premiers[j]=Vrai alors
  pour s de j a n-1 faire
   est_premiers[j*s] ←Faux
  Fin pour
 Fin si
Fin pour 
pour i de 0 à n-1 faire 
  si es_premiers=Vrai alors
   compteur ←compteur+1
  Fin si
Fin pour

Question3:
reformulation des étapes fait dans le deuxième algorithme:
1.On parcourt tous les nombres de 2 jusqu’à √n.
2.Pour chaque nombre premier p, on supprime tous ses multiples (2*p, 3*p, 4*p,etc) jusqu’à n.
3.À la fin, les nombres restants sont premiers.
Pour chaque nombre premier p ≤ n, on marque environ n/p multiples.
Donc le nombre total d’opérations est égal à:∑ p<=n n/p= n∑1/p
de plus on a la constante de Meissel–Mertens:∑1/p<=log(log(n+1))+M
donc le nombre total d'opération <=nlog(log(n+1))+M
alors le nombre maximum des opérations est égal a nloglogn
donc la compléxité temporelle de deuxième algorithme est:O(nloglogn)

Question 4:

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// ---------- Naive algorithm ----------
int count_primes_naive(int n) {
    int count = 0;
    for (int i = 2; i < n; i++) {
        int isPrime = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            count++;
    }
    return count;
}
int count_primes_sieve(int n) {
    if (n <= 2)
        return 0;

    bool isPrime[n];
    for (int i = 0; i < n; i++)
        isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple < n; multiple += p)
                isPrime[multiple] = false;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
        if (isPrime[i])
            count++;

    return count;
}

// ---------- Main ----------
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start, end;
    double time_naive, time_sieve;
     // --- Naive ---
    start = clock();
    int primes_naive = count_primes_naive(n);
    end = clock();
    time_naive = ((double)(end - start)) / CLOCKS_PER_SEC;

    // --- Sieve ---
    start = clock();
    int primes_sieve = count_primes_sieve(n);
    end = clock();
    time_sieve = ((double)(end - start)) / CLOCKS_PER_SEC;

    // --- Results ---
    printf("\nNaive algorithm: %d primes < %d\n", primes_naive, n);
    printf("Runtime: %.6f seconds\n", time_naive);

    printf("\nSieve algorithm: %d primes < %d\n", primes_sieve, n);
    printf("Runtime: %.6f seconds\n", time_sieve);

    return 0;
}
