// benchmark_test.cpp

#include <iostream>
#include <math.h>
#include <time.h>

#define __DEBUG_AAAAA__
#include "../remez_approx.h"
#include "../tests/fastonebigheader.h"
using namespace std;

static const int DIV = 1000000000;

// remez_sin_float test
static void test_fastersin()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        float x = 2.0f*M_PI*i/DIV;
        sum += fastersin(x);
    }
    cout << "fastersin"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_sin_float test
static void test_remez_sin_float()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        float x = 2.0f*M_PI*i/DIV;
        sum += remez_sin_float(x);
    }
    cout << "remez_sin_float"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_sin_float2 test
static void test_remez_sin_float2()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        float x = 2.0f*M_PI*i/DIV;
        sum += remez_sin_float2(x);
    }
    cout << "remez_sin_float2"
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


// remez_cos_int32 test
static void test_remez_cos_int32()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int32_t i = -DIV; i < DIV; i++ )
    {
        int32_t x = INT32_MAX / DIV * i;
        sum += remez_cos_int32(3*x);
    }
    cout << "remez_cos_int32"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_cos_int64 test
static void test_remez_cos_int64()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int64_t i = -DIV; i < DIV; i++ )
    {
        int64_t x = INT64_MAX / DIV * i;
        sum += remez_cos_int64(3*x);
    }
    cout << "remez_cos_int64"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

int main()
{
    test_sinf();
    test_sin();
    
    test_fastersin();
    test_remez_sin_float();
    test_remez_sin_float2();
    test_fastersin();
    test_remez_sin_float();
    test_remez_sin_float2();
    
    test_remez_sin();
    test_remez_sin2();
    test_remez_sin();
    test_remez_sin2();

    test_remez_sin_int32();
    test_remez_sin_int64();
    test_remez_sin_int32();
    test_remez_sin_int64();
    
    test_remez_cos_int32();
    test_remez_cos_int64();
    test_remez_cos_int32();
    test_remez_cos_int64();
    
    return 0;
}

/*
g++ -O3 benchmark_test.cpp
./a.out
 
 sinf time:19.7373 sum:-1.67772e+07
 sin time:27.3904 sum:-1.56595e-08
 fastersin time:7.20741 sum:1.50205e+08
 remez_sin_float time:6.86795 sum:1.34218e+08
 remez_sin_float2 time:7.20128 sum:1.34218e+08
 fastersin time:7.23375 sum:1.50205e+08
 remez_sin_float time:6.91967 sum:1.34218e+08
 remez_sin_float2 time:7.19641 sum:1.34218e+08
 remez_sin time:5.71203 sum:-7.98606
 remez_sin2 time:6.03392 sum:-7.98606
 remez_sin time:5.65906 sum:-7.98606
 remez_sin2 time:6.051 sum:-7.98606
 remez_sin_int32 time:3.84663 sum:-0.899075
 remez_sin_int64 time:3.83012 sum:-2.92303e-10
 remez_sin_int32 time:3.84372 sum:-0.899075
 remez_sin_int64 time:3.83421 sum:-2.92303e-10
 remez_cos_int32 time:3.89096 sum:1.3737e+08
 remez_cos_int64 time:3.80383 sum:0.185218
 remez_cos_int32 time:3.82302 sum:1.3737e+08
 remez_cos_int64 time:3.81001 sum:0.185218
*/
