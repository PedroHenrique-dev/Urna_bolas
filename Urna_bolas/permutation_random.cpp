#include <iostream>
#include <vector>
#include <random>
#include <utility>

#include "permutation_random.h"

using namespace std;

double numRandom()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, 1);
    return dist(mt);
}

template <class LIST>
LIST permutation(LIST x)
{
    int n = x.size();
    double u = numRandom();

    int k{n-1};
    while (k > -1)    
    {
        int r = int(u*k)+1;
        swap(x[k], x[r]);
        --k;
    }

    return x;
}
