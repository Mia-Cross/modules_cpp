/// Fixed-point Format: 11.5 (16-bit)
// 11 integral bits, 5 fractional bits
#include <tgmath.h>

typedef uint16_t fixed_point_t;

#define FIXED_POINT_FRACTIONAL_BITS 5

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