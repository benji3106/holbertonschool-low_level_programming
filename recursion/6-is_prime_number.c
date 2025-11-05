#include "main.h"

/**
 * check_prime - helper function that checks if n is divisible by i
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int check_prime(int n, int i)
{
	if (i * i > n)
		return (1);           /* aucun diviseur trouvé : n est premier */
	if (n % i == 0)
		return (0);           /* divisible : pas premier */
	return (check_prime(n, i + 1));  /* tester le suivant */
}

/**
 * is_prime_number - returns 1 if n is a prime number, 0 otherwise
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);           /* 0 et 1 ne sont pas premiers */

	return (check_prime(n, 2)); /* on commence à tester à partir de 2 */
}
