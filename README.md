### Improve absolute error of the [fastapprox](https://code.google.com/p/fastapprox/) function based on the minimax approximation algorithm.

![figure](https://raw.githubusercontent.com/fukuroder/remez_approx/master/figure.png)

### Available functions

**32bit Floating-point number argument version(x range: -pi ~ pi)**
- float remez_sin_float32(float x)

**64bit Floating-point number argument version(x range: -pi ~ pi)**
- double remez_sin_float64(double x)

**32bit Signed integer argument version(x range: 0 ~ 2^32-1)**
- double remez_sin_uint32(uint32_t x)
- double remez_cos_uint32(uint32_t x)
- double remez_tan_uint32(uint32_t x)

**64bit Signed integer argument version(x range: 0 ~ 2^64-1)**
- double remez_sin_uint64(uint64_t x)
- double remez_cos_uint64(uint64_t x)
- double remez_tan_uint64(uint64_t x)

### Example

```cpp
#include <iostream>
#include "remez_approx.h"

int main()
{
    // sample rate
    double sample_rate = 44100.0;

    // frequency
    double freq = 440.0;

    // delta t
    uint32_t dt = static_cast<uint32_t>(0xFFFFFFFF / sample_rate * freq);

    // current position
    uint32_t t = 0;

    // for each sample...
    for(int i = 0; i < 500; ++i)
    {
        // output
        std::cout
        << remez_sin_uint32(t) + remez_sin_uint32(2*t)/2 + remez_sin_uint32(3*t)/3
        << std::endl;

        // update position
        t += dt;
    }

    return 0;
}
```

![figure](https://raw.githubusercontent.com/fukuroder/remez_approx/master/figure2.png)
