// benchmark_test.cpp

#include <iostream>
#include <time.h>

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
        float x = 2.0f*3.141592f/DIV*i;
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
        float x = 2.0f*3.141592f/DIV*i;
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
        float x = 2.0f*3.141592f/DIV*i;
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
        double x = 2.0*M_PI/DIV*i;
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
        double x = 2.0*M_PI/DIV*i;
        sum += remez_sin_float64(x);
    }
    cout << "remez_sin_float64"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}


// remez_sin_uint32 test
static void test_remez_sin_uint32()
{
    double sum = 0.0;
    clock_t start = clock();
    for( uint32_t i = 0; i < 2*DIV; i++ )
    {
        uint32_t x = UINT32_MAX / DIV * i;
        sum += remez_sin_uint32(x*5/3);
    }
    cout << "remez_sin_uint32"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_sin_uint64 test
static void test_remez_sin_uint64()
{
    double sum = 0.0;
    clock_t start = clock();
    for( uint64_t i = 0; i < 2*DIV; i++ )
    {
        uint64_t x = UINT64_MAX / DIV * i;
        sum += remez_sin_uint64(x*5/3);
    }
    cout << "remez_sin_uint64"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_cos_uint32 test
static void test_remez_cos_uint32()
{
    double sum = 0.0;
    clock_t start = clock();
    for( uint32_t i = 0; i < 2*DIV; i++ )
    {
        uint32_t x = UINT32_MAX / DIV * i;
        sum += remez_cos_uint32(x*5/3);
    }
    cout << "remez_cos_uint32"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_cos_uint64 test
static void test_remez_cos_uint64()
{
    double sum = 0.0;
    clock_t start = clock();
    for( uint64_t i = 0; i < 2*DIV; i++ )
    {
        uint64_t x = UINT64_MAX / DIV * i;
        sum += remez_cos_uint64(x*5/3);
    }
    cout << "remez_cos_uint64"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// fastertan test
static void test_fastertan()
{
    float sum = 0.0;
    clock_t start = clock();
    for( int i = 0; i < DIV-100; i++ )
    {
        float x = 3.141592f/2*i/DIV;
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
    for( int i = 0; i < DIV-100; i++ )
    {
        float x = 3.141592f/2/DIV*i;
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
    for( int i = 0; i < DIV-100; i++ )
    {
        double x = M_PI/2/DIV*i;
        sum += tan(x);
    }
    cout << "tan"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_tan_uint32 test
static void test_remez_tan_uint32()
{
    double sum = 0.0;
    clock_t start = clock();
    for( uint32_t i = 0; i < DIV-100; i++ )
    {
        uint32_t x = UINT32_MAX / 4 / DIV * i;
        sum += remez_tan_uint32(x);
    }
    cout << "remez_tan_uint32"
    << " time:" << static_cast<double>(clock()-start)/CLOCKS_PER_SEC
    << " sum:" << sum << endl;
}

// remez_tan_uint64 test
static void test_remez_tan_uint64()
{
    double sum = 0.0;
    clock_t start = clock();
    for( uint64_t i = 0; i < DIV-100; i++ )
    {
        uint64_t x = UINT64_MAX / 4 / DIV * i;
        sum += remez_tan_uint64(x);
    }
    cout << "remez_tan_uint64"
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

    test_remez_sin_uint32();
    test_remez_sin_uint64();
    test_remez_sin_uint32();
    test_remez_sin_uint64();
    
    test_remez_cos_uint32();
    test_remez_cos_uint64();
    test_remez_cos_uint32();
    test_remez_cos_uint64();
    
    test_tanf();
    test_tan();
    test_fastertan();
    test_remez_tan_uint32();
    test_remez_tan_uint64();
    test_fastertan();
    test_remez_tan_uint32();
    test_remez_tan_uint64();
    
    return 0;
}

/*
g++ -O3 benchmark_test.cpp
./a.out
 
 sinf time:12.7313 sum:-1.67772e+07
 sin time:22.5174 sum:1.32338e-08
 fastersin time:4.64401 sum:1.50202e+08
 remez_sin_float32 time:4.35317 sum:1.34218e+08
 remez_sin_float64 time:4.08999 sum:-7.98606
 fastersin time:4.9879 sum:1.50202e+08
 remez_sin_float32 time:4.3618 sum:1.34218e+08
 remez_sin_float64 time:4.16636 sum:-7.98606
 remez_sin_uint32 time:3.9749 sum:1.40528e+09
 remez_sin_uint64 time:4.09153 sum:1.43217e+09
 remez_sin_uint32 time:3.82111 sum:1.40528e+09
 remez_sin_uint64 time:4.21416 sum:1.43217e+09
 remez_cos_uint32 time:5.37748 sum:8.61828e+08
 remez_cos_uint64 time:6.77517 sum:8.27115e+08
 remez_cos_uint32 time:5.37755 sum:8.61828e+08
 remez_cos_uint64 time:6.70168 sum:8.27115e+08
 tanf time:8.96199 sum:7.92169e+09
 tan time:14.383 sum:9.97043e+09
 fastertan time:5.87472 sum:7.87425e+09
 remez_tan_uint32 time:4.04949 sum:1.52581e+09
 remez_tan_uint64 time:4.61796 sum:1.00517e+10
 fastertan time:5.89041 sum:7.87425e+09
 remez_tan_uint32 time:4.06098 sum:1.52581e+09
 remez_tan_uint64 time:4.6505 sum:1.00517e+10
*/
