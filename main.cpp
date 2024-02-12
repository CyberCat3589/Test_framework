#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "assert_equal.h"

using namespace std;

vector<int> TakeEvens(const vector<int>& numbers) 
{
    vector<int> evens;
    for (int x : numbers) {
        if (x % 2 == 0) {
            evens.push_back(x);
        }
    }
    return evens;
}

map<string, int> TakeAdults(const map<string, int>& people) 
{
    map<string, int> adults;
    for (const auto& [name, age] : people) {
        if (age >= 18) {
            adults[name] = age;
        }
    }
    return adults;
}

bool IsPrime(int n) 
{
    if (n < 2) 
    {
        return false;
    }
    int i = 2;
    while (i * i <= n) 
    {
        if (n % i == 0) 
        {
            return false;
        }
        ++i;
    }
    return true;
}

set<int> TakePrimes(const set<int>& numbers) 
{
    set<int> primes;
    for (int number : numbers) 
    {
        if (IsPrime(number)) 
        {
            primes.insert(number);
        }
    }
    return primes;
}

int main() 
{
    {
        const set<int> numbers = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        const set<int> expected_primes = {2, 3, 5, 7, 11, 13};
        ASSERT_EQUAL(TakePrimes(numbers), expected_primes);
    }

    {
        const map<string, int> people = {{"Ivan"s, 19}, {"Sergey"s, 16}, {"Alexey"s, 18}};
        const map<string, int> expected_adults = {{"Alexey"s, 18}, {"Ivan"s, 19}};
        ASSERT_EQUAL(TakeAdults(people), expected_adults);
    }

    {
        const vector<int> numbers = {3, 2, 1, 0, 3, 6};
        const vector<int> expected_evens = {2, 0, 6};
        ASSERT_EQUAL(TakeEvens(numbers), expected_evens);
    }
}