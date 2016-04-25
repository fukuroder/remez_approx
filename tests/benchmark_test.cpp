// g++ -03 benchmark_test.cpp

#include <iostream>
#include <math.h>
#include <time.h>

#define __DEBUG_AAAAA__
#include "../remez_approx.h"
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

// remez_sin_int32 test
static void test_remez_sin_int32()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int32_t i = -DIV; i < DIV; i++ )
    {
        int32_t x = INT32_MAX / DIV * i;
        sum += remez_sin_int32(20*x);
    }
    cout << "remez_sin_int32"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_sin_int64 test
static void test_remez_sin_int64()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int64_t i = -DIV; i < DIV; i++ )
    {
        int64_t x = INT64_MAX / DIV * i;
        sum += remez_sin_int64(20*x);
    }
    cout << "remez_sin_int64"
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

    test_remez_sin_int32();
    test_remez_sin_int64();
    test_remez_sin_int32();
    test_remez_sin_int64();
    
    return 0;
}

/*
g++ -O3 benchmark_test.cpp
./a.out
 
 remez_sin_f time:6.94617 sum:1.34218e+08
 remez_sin_f2 time:7.37882 sum:1.34218e+08
 remez_sin_f time:7.07748 sum:1.34218e+08
 remez_sin_f2 time:7.29373 sum:1.34218e+08
 remez_sin_f time:6.8518 sum:1.34218e+08
 remez_sin_f2 time:7.09394 sum:1.34218e+08
 sinf time:19.5477 sum:-1.67772e+07
 remez_sin time:5.64708 sum:-7.98606
 remez_sin2 time:5.92724 sum:-7.98606
 remez_sin time:5.58247 sum:-7.98606
 remez_sin2 time:6.12888 sum:-7.98606
 remez_sin time:5.65452 sum:-7.98606
 remez_sin2 time:6.12275 sum:-7.98606
 sin time:27.8118 sum:-1.56595e-08
 remez_sin_int32 time:3.96346 sum:-0.899075
 remez_sin_int64 time:3.8601 sum:-2.92303e-10
 remez_sin_int32 time:3.90944 sum:-0.899075
 remez_sin_int64 time:3.8832 sum:-2.92303e-10
*/
