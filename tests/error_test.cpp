#include <fstream>
#include <cmath>
#include "../remez_approx.h"
#include "fastonebigheader.h" // https://code.google.com/p/fastapprox/
using namespace std;

int main()
{
    const int div = 1000;
    {
        ofstream f("remez_sin_error.dat");
        for( int i = -div; i < div; i++ )
        {
            float x = 2.0*M_PI*i/div;
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
            float x = 2.0*M_PI*i/div;
            f << x
              << ", "
              << ::fabs(::fastersin(x) - ::sinf(x))
              << endl;
        }
    }
    
    {
        ofstream f("remez_sin_int32_error.dat");
        for( int i = -4*div; i < 4*div; i++ )
        {
            double x = M_PI*i/div;
            f << x
            << ", "
            << ::fabs(::remez_sin_int32(INT32_MAX/div*i) - ::sin(x))
            << endl;
        }
    }

    return 0;
}
