#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <ctime>

#include "permutation_random.h"

using namespace std;

double numRandom()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, 1);
    return dist(mt);
}

double lcg_n1_0_1(int semente)
{
    int a = 163, c = 151, m = 251;

    double aux = (a * semente + c) % m;
    while (aux <= 0 || aux >= 1)
    {
        aux /= 10;
    }

    return aux;
}

template <class LIST>
LIST permutation(LIST x, bool bool_lcg)
{
    int n = x.size();

    double u;
    if (bool_lcg)
    {
        u = lcg_n1_0_1(time(NULL));
    }
    else
    {
        u = numRandom();
    }

    int k{n-1};
    while (k > -1)    
    {
        int r = int(u*k)+1;
        swap(x[k], x[r]);
        --k;
    }

    return x;
}
