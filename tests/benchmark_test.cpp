// benchmark_test.cpp

#include <iostream>
#include <math.h>
#include <time.h>

#define __DEBUG_AAAAA__
#include "../remez_approx.h"
#include "../tests/fastonebigheader.h"
using namespace std;

static const int DIV = 1000000000;

// fastersin test
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

// remez_sin_float32 test
static void test_remez_sin_float32()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        float x = 2.0f*M_PI*i/DIV;
        sum += remez_sin_float32(x);
    }
    cout << "remez_sin_float32"
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

// remez_sin_float64 test
static void test_remez_sin_float64()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV; i < DIV; i++ )
    {
        double x = 2.0*M_PI*i/DIV;
        sum += remez_sin_float64(x);
    }
    cout << "remez_sin_float64"
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

// fastertan test
static void test_fastertan()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV+100; i < DIV-100; i++ )
    {
        float x = M_PI/2*i/DIV;
        sum += fastertan(x);
    }
    cout << "fastertan"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// tanf test
static void test_tanf()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV+100; i < DIV-100; i++ )
    {
        float x = M_PI/2*i/DIV;
        sum += tanf(x);
    }
    cout << "tanf"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}


// tan test
static void test_tan()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int i = -DIV+100; i < DIV-100; i++ )
    {
        double x = M_PI/2*i/DIV;
        sum += tan(x);
    }
    cout << "tan"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_tan_int32 test
static void test_remez_tan_int32()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int32_t i = -DIV+100; i < DIV-100; i++ )
    {
        int32_t x = INT32_MAX / 2 / DIV * i;
        sum += remez_tan_int32(x);
    }
    cout << "remez_tan_int32"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_tan_int64 test
static void test_remez_tan_int64()
{
    double sum = 0.0;
    clock_t start = clock();
    for( int64_t i = -DIV+100; i < DIV-100; i++ )
    {
        int64_t x = INT64_MAX / 2 / DIV * i;
        sum += remez_tan_int64(x);
    }
    cout << "remez_tan_int64"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

int main()
{
    test_sinf();
    test_sin();
    
    test_fastersin();
    test_remez_sin_float32();
    test_remez_sin_float64();
    test_fastersin();
    test_remez_sin_float32();
    test_remez_sin_float64();

    test_remez_sin_int32();
    test_remez_sin_int64();
    test_remez_sin_int32();
    test_remez_sin_int64();
    
    test_remez_cos_int32();
    test_remez_cos_int64();
    test_remez_cos_int32();
    test_remez_cos_int64();
    
    test_tanf();
    test_tan();
    test_fastertan();
    test_remez_tan_int32();
    test_remez_tan_int64();
    test_fastertan();
    test_remez_tan_int32();
    test_remez_tan_int64();
    
    return 0;
}

/*
g++ -O3 benchmark_test.cpp
./a.out
 
 sinf time:19.4483 sum:-1.67772e+07
 sin time:27.1479 sum:-1.56595e-08
 fastersin time:7.16098 sum:1.50205e+08
 remez_sin_float32 time:6.87041 sum:1.34218e+08
 remez_sin_float64 time:5.6186 sum:-7.98606
 fastersin time:7.37991 sum:1.50205e+08
 remez_sin_float32 time:6.8601 sum:1.34218e+08
 remez_sin_float64 time:5.68558 sum:-7.98606
 remez_sin_int32 time:4.07169 sum:-0.899075
 remez_sin_int64 time:3.80955 sum:-2.92303e-10
 remez_sin_int32 time:3.83168 sum:-0.899075
 remez_sin_int64 time:3.92108 sum:-2.92303e-10
 remez_cos_int32 time:3.87572 sum:1.3737e+08
 remez_cos_int64 time:3.787 sum:0.185218
 remez_cos_int32 time:3.83369 sum:1.3737e+08
 remez_cos_int64 time:3.85773 sum:0.185218
 tanf time:26.3193 sum:-5.13566e+06
 tan time:33.4081 sum:-6.3662e+06
 fastertan time:12.6496 sum:-3.61467e+06
 remez_tan_int32 time:14.3558 sum:-15.6482
 remez_tan_int64 time:14.3061 sum:-6.42169e+06
 fastertan time:12.9819 sum:-3.61467e+06
 remez_tan_int32 time:14.5277 sum:-15.6482
 remez_tan_int64 time:14.5407 sum:-6.42169e+06
*/
