// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <cstring>  // memset
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair
#include <math.h>

// ------------
// oil_read
// ------------
int n, k;

inline void oil_read (std::istream& r)
{
    r >> n >> k;
}

// ------------
// oil_eval
// ------------

inline int oil_eval (int v) 
{
    int result = 0;
    int dev = v;
    while (dev > 0)
    {
        result += dev;
        dev/=k;
        //std::cout << "result " << result << std::endl;
    }
    //std::cout << "Result: " << result << std::endl;
    return result;
}

// -------------
// oil_print
// -------------

inline void oil_print (std::ostream& w, int i) 
{
    w << i << std::endl;
}

// -------------
// oil_solve
// -------------

inline void oil_solve (std::istream& r, std::ostream& w) 
{
    int high, low, mid;
    int result = 0;
    oil_read(r);
    if(n < k)
    {
        oil_print(w, n);
        return;
    }
    high = n + 1;
    low = k - 1;
    while(result != n)
    {
        if(mid == high)
        {
            oil_print(w, mid);
            break;
        }
        mid = (high - low)/2 + low;
        //std::cout << "High: " << high << " Low: " << low << " Mid: " << mid << std::endl;
        result = oil_eval(mid);
        if(result == n)
        {
            oil_print(w, mid);
            break;
        }
        else if(result > n)
        {
            high = mid - 1;
        }
        else if(result < n)
        {
            low = mid + 1;
        }
    }
    return;
}

// ----
// main
// ----

int main () 
{
    using namespace std;
    oil_solve(cin, cout);
    return 0;
}