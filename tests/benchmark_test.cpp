#include <iostream>
#include <math.h>
#include <time.h>
#include "../src/remez_approx.h"
using namespace std;

static const int DIV = 1000000000;

// remez_sin_f test
static void test_remez_sin_f()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        float x = 2.0f*M_PI*i/DIV;
        sum += remez_sin_f(x);
    }
    cout << "remez_sin_f"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_sin_f2 test
static void test_remez_sin_f2()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        float x = 2.0f*M_PI*i/DIV;
        sum += remez_sin_f2(x);
    }
    cout << "remez_sin_f2"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// sinf test
static void test_sinf()
{
    float sum = 0.0f;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        float x = 2.0f*M_PI*i/DIV;
        sum += sinf(x);
    }
    cout << "sinf"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_sin test
static void test_remez_sin()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        double x = 2.0*M_PI*i/DIV;
        sum += remez_sin(x);
    }
    cout << "remez_sin"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_sin2 test
static void test_remez_sin2()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        double x = 2.0*M_PI*i/DIV;
        sum += remez_sin2(x);
    }
    cout << "remez_sin2"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// sin test
static void test_sin()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        double x = 2.0*M_PI*i/DIV;
        sum += sin(x);
    }
    cout << "sin"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

int main()
{
    test_remez_sin_f();
    test_remez_sin_f2();
    test_remez_sin_f();
    test_remez_sin_f2();
    test_remez_sin_f();
    test_remez_sin_f2();
    test_sinf();
    
    test_remez_sin();
    test_remez_sin2();
    test_remez_sin();
    test_remez_sin2();
    test_remez_sin();
    test_remez_sin2();
    test_sin();
    
    return 0;
}

/*
g++ -O3 benchmark_test.cpp
./a.out
 
remez_sin_f time:6.60271 sum:1.34218e+08
remez_sin_f2 time:6.89346 sum:1.34218e+08
remez_sin_f time:6.48995 sum:1.34218e+08
remez_sin_f2 time:6.90512 sum:1.34218e+08
remez_sin_f time:6.51274 sum:1.34218e+08
remez_sin_f2 time:6.84047 sum:1.34218e+08
sinf time:19.0447 sum:-1.67772e+07
remez_sin time:5.37921 sum:-7.98606
remez_sin2 time:5.69366 sum:-7.98606
remez_sin time:5.41337 sum:-7.98606
remez_sin2 time:5.71997 sum:-7.98606
remez_sin time:5.41559 sum:-7.98606
remez_sin2 time:5.70025 sum:-7.98606
sin time:26.9057 sum:-1.56595e-08
*/
