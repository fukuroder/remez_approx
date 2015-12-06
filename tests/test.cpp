#include<iostream>
#include<fstream>
#include<cmath>
#include"../src/faster_and_better_sin.h"
#include"fastonebigheader.h" // https://code.google.com/p/fastapprox/

using namespace std;

int main()
{
    const int div = 1000;
    {
        ofstream f("faster_and_better_sin_error.dat");
        for( int i = -div; i < div; i++ )
        {
            float x = 2.0*M_PI*i/div;
            f << x
              << ", "
              << fabs(::faster_and_better_sin(x) - sin(x))
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
              << fabs(::fastersin(x) - sin(x))
              << endl;
        }
    }

    return 0;
}
