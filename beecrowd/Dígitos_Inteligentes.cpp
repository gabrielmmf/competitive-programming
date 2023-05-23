#include <iostream>

const int MOD = 1000000007;

long long sumDigitsInRange(long long L, long long R)
{
    long long repetitions = (R - L + 1) / 10; // Número de repetições do padrão
    long long patternSum = repetitions * 45;  // Soma dos dígitos de 1 a 9 repetida

    long long extraSum = 0;
    for (long long i = L; i <= R; i++)
    {
        long long num = i;
        while (num > 0)
        {
            extraSum += num % 10; // Soma dos dígitos individuais
            extraSum %= MOD;      // Mantém a soma módulo 10^9+7
            num /= 10;
        }
    }

    long long totalSum = (patternSum + extraSum) % MOD;
    return totalSum;
}

int main()
{
    long long L, R;
    while (std::cin >> L >> R)
    {
        long long result = sumDigitsInRange(L, R);
        std::cout << result << std::endl;
    }

    return 0;
}