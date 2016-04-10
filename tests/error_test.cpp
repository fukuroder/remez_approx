#include <fstream>
#include <cmath>
#include "../src/remez_approx.h"
#include "fastonebigheader.h" // https://code.google.com/p/fastapprox/
using namespace std;

int main()
{
    const int div = 1000;
    {
        ofstream f("remez_sin_error.dat");
        for( int i = -div; i < div; i++ )
        {
            float x = 2.0f*M_PI*i/div;
            f << x
              << ", "
              << ::fabs(::remez_sin_f(x) - ::sin(x))
              << endl;
        }
    }

    {
        ofstream f("fastersin_error.dat");
        for( int i = -div; i < div; i++ )
        {
            float x = 2.0f*M_PI*i/div;
            f << x
              << ", "
              << ::fabs(::fastersin(x) - ::sin(x))
              << endl;
        }
    }

    return 0;
}
