typedef int BaseType;

class fixed_point
{
    //const static BaseType factor = 1 << FracDigits;
    const static BaseType factor = 1 << 8;
    BaseType data;

public:
    fixed_point(double d)
    {
        *this = d; // calls operator=
    }
    fixed_point& operator=(double d)
    {
        data = static_cast<BaseType>(d*factor);
        return *this;
    }
    BaseType raw_data() const
    {
        return data;
    }
};

//////////////////////////////////////////////////////////////////////////////
//TESTS POUR TO_FLOAT();
 // const int *src = &this->fixedPoint;
    // char *srcByte = (char *)src;
    //float result = 0;
    // memcpy(&result, &this->fixedPoint, sizeof(float));
    // float *dest = &result;
    // char *destByte = (char *)dest;
    // int i = 0;
    // while (i < 4)
    // {
    //     destByte[i] = srcByte[i];
    //     i++;
    // }
    //return (result);

    //float x = static_cast<float>(this->fixedPoint);
    //float x = this->fixedPoint;
    //const int &y = this->fixedPoint;
    //const int &iRef = this->fixedPoint;
   // int &iRef = const_cast<int &>(icRef);
    //float &fRef = static_cast<float>(this->fixedPoint);
    //float &x = dynamic_cast<float &>(y));
    //float x = (float)this->fixedPoint;
    //std::cout << x << " = toFloat called\n";
    //return fRef;


//////////////////////////////////////////////////////////////////////////////
/// Fixed-point Format: 11.5 (16-bit)
// 11 integral bits, 5 fractional bits
#include <tgmath.h>
#include <stdio.h>
#include <stdint.h>

typedef uint16_t fixed_point_t;

#define FIXED_POINT_FRACTIONAL_BITS 5
//#define FIXED_POINT_FRACTIONAL_BITS 8

/// Converts 11.5 format -> double
double fixed_to_float(fixed_point_t input);

/// Converts double to 11.5 format
fixed_point_t float_to_fixed(double input);

inline double fixed_to_float(fixed_point_t input)
{
    return ((double)input / (double)(1 << FIXED_POINT_FRACTIONAL_BITS));
}

inline fixed_point_t float_to_fixed(double input)
{
    return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
}

// Convert 16-bit fixed-point to double
double fixed16_to_double(uint16_t input, uint8_t fractional_bits)
{
    return ((double)input / (double)(1 << fractional_bits));
}

// Equivalent of our 11.5 conversion function above
//double r = fixed16_to_double(input, 5);

int main()
{
    double d1 = 666.0;
    fixed_point_t fix1 = float_to_fixed(d1);

    fixed_point_t fix2 = 209;
    double d2 = fixed_to_float(fix2);

    printf("Fixed (from float %f) = %u\n", d1, fix1);
    printf("Float (from fixed %u) = %f\n", fix2, d2);
}
