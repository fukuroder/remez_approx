### Improve absolute error of the [fastapprox](https://code.google.com/p/fastapprox/) function based on the minimax approximation algorithm.

![screenshot](https://raw.githubusercontent.com/fukuroder/remez_approx/master/figure.png)

### Available functions

**32bit Floating-point number argmument version(x range: -pi ~ +pi)**
- float remez_sin_float32(float x)

**64bit Floating-point number argmument version(x range: -pi ~ +pi)**
- double remez_sin_float64(double x)

**32bit Signed integer argmument version(x range: -2^31 ~ 2^31-1)**
- double remez_sin_int32(int32_t x)
- double remez_cos_int32(int32_t x)
- double remez_tan_int32(int32_t x)

**64bit Signed integer argmument version(x range: -2^63 ~ 2^63-1)**
- double remez_sin_int64(int64_t x)
- double remez_cos_int64(int64_t x)
- double remez_tan_int64(int64_t x)
