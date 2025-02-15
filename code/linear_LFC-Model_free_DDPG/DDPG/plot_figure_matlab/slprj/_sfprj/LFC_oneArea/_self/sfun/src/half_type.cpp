#include <cmath>
#include <cstring>
#include "half_type.h"

/* Utility function */
uint32_T getBitfieldFromFloat(real32_T a)
{
  uint32_T bitfield;
  memcpy(&bitfield, &a, sizeof(real32_T));
  return bitfield;
}

real32_T getFloatFromBitfield(uint32_T a)
{
  real32_T value;
  memcpy(&value, &a, sizeof(real32_T));
  return value;
}

/* Utility function for half and bit pattern conversion */
uint16_T getBitfieldFromHalf(real16_T a)
{
  return a.getBitPattern();
}

real16_T getHalfFromBitfield(uint16_T a)
{
  real16_T value;
  value.setBitPattern(a);
  return value;
}

/* Convert half to float */
real32_T halfToFloat(real16_T a)
{
  return static_cast<real32_T>(a);
}

real16_T::operator real32_T() const
{
  const real32_T eExp = 5.192296858534828e+33f;/* 2^112 */
  uint16_T aExpComp = (uint16_T)((uint32_T)(~bitPattern) & 0x7C00U);
  uint32_T outSign = ((((uint32_T)bitPattern) & 0x8000U) << 16);
  uint32_T outExpMant = ((((uint32_T)bitPattern) & 0x7FFFU) << 13);
  real32_T ans;
  if (aExpComp != 0U) {
    /* Input is finite */
    uint32_T out = (outSign | outExpMant);
    ans = (getFloatFromBitfield(out) * eExp);
  } else {
    uint32_T out = (outSign | outExpMant | 0x7F800000U);
    ans = getFloatFromBitfield(out);
  }

  return ans;
}

/* Convert float to half */
real16_T floatToHalf(real32_T a)
{
  return static_cast<real16_T>(a);
}

real16_T::real16_T(real32_T a)
{
  uint32_T input = getBitfieldFromFloat(a);
  uint32_T aExponent = (input & 0x7F800000U) >> 23;

  /* Move exponent to the unit place so that it is easier to compute other exponent values */
  uint32_T aMantissa = (input & 0x007FFFFFU);
  uint16_T outSign = (uint16_T)((input & 0x80000000U) >> 16);
  uint16_T outExponent;
  uint16_T outMantissa;
  if (aExponent == 0x7F800000U >> 23) {/* Inf or NaN input */
    outExponent = 0x7C00U;
    outMantissa = (aMantissa == 0) ? 0 : 0x0200U;
  } else if (aExponent < 102U) {
    /* Smaller than 1/2 of the smallest denormal number in half precision */
    outExponent = 0;
    outMantissa = 0;
  } else if (aExponent > 142U) {
    /* Largest exponent in half precision is 2^(15). (142 = 15 + 127) */
    outExponent = 0x7C00U;
    outMantissa = 0;
  } else {
    /* Get sticky and round bit */
    boolean_T sticky;
    boolean_T round;
    if (aExponent < 113U) {            /* Answer is denormal */
      uint32_T shift_length;
      aMantissa |= 0x00800000U;        /* Add hidden bit */
      shift_length = 113U - aExponent;

      /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "(aMantissa << (20 - shift_length) evaluates
         sticky bit. Other bit overflows do not have any effect here." */
      sticky = ((aMantissa << (20 - shift_length)) != 0);/* 32 bit - (12 + shift_length) */
      round = ((aMantissa >> (12 + shift_length) & 0x00000001U) != 0);
      outExponent = 0;
      outMantissa = (uint16_T)((aMantissa >> (13 + shift_length)));
    } else {
      sticky = ((aMantissa & 0x00000FFFU) != 0);
      round = ((aMantissa & 0x00001000U) != 0);
      outExponent = (uint16_T)(aExponent - 112);
      outMantissa = (uint16_T)(aMantissa >>= 13);
    }

    /* Perform rounding to nearest even */
    if (round && (sticky || ((outMantissa & 0x0001U) != 0))) {
      outMantissa++;
    }

    if (outMantissa > 0x03FFU) {       /* Rounding causes overflow */
      outExponent++;
      outMantissa = 0;
    }

    outExponent <<= 10;
  }

  bitPattern = (outSign | outExponent | outMantissa);
}

/* Convert half to double */
real64_T halfToDouble(real16_T a)
{
  return static_cast<real64_T>(a);
}

real16_T::operator real64_T() const
{
  return static_cast<real64_T>(this->operator real32_T());
}

/* Convert double to half */
real16_T doubleToHalf(real64_T a)
{
  return static_cast<real16_T>(a);
}

real16_T::real16_T(real64_T a)
{
  const uint32_T *aBitsPointer;
  uint32_T mostSignificantChunk;
  uint32_T aMantissaFirstChunk;
  uint32_T aMantissaSecondChunk;
  uint16_T aExponent;
  uint16_T outSign;
  uint16_T outExponent;
  uint16_T outMantissa;
  real64_T one = 1.0;
  uint32_T endianAdjustment = *((uint32_T*)&one);
  aBitsPointer = (uint32_T *) &a;      /* Type pun input as an unsigned 32-bit int */
  if (endianAdjustment) {
    mostSignificantChunk = *(aBitsPointer++);
    aMantissaSecondChunk = *aBitsPointer;
  } else {
    aMantissaSecondChunk = *(aBitsPointer++);
    mostSignificantChunk = *aBitsPointer;
  }

  /* Move exponent to the unit place so that it is easier to compute other exponent values */
  aExponent = (uint16_T)((mostSignificantChunk & 0x7FF00000UL) >> (52-32));
  aMantissaFirstChunk = (mostSignificantChunk & 0x000FFFFFU);
  outSign = (uint16_T)((mostSignificantChunk & 0x80000000UL) >> (48-32));
  if (aExponent == (uint16_T)(0x7FF00000UL >> (52-32))) {/* Inf or NaN input */
    outExponent = 0x7C00U;
    outMantissa = (aMantissaFirstChunk == 0 && aMantissaSecondChunk == 0) ? 0 :
      0x0200U;
  } else if (aExponent < 998U) {
    /* Smaller than 1/2 of the smallest denormal number in half precision */
    outExponent = 0;
    outMantissa = 0;
  } else if (aExponent > 1038U) {
    /* Largest exponent in half precision is 2^(15). (1038 = 15 + 1023) */
    outExponent = 0x7C00U;
    outMantissa = 0;
  } else {
    /* Get sticky and round bit */
    boolean_T sticky;
    boolean_T round;
    if (aExponent < 1009U) {           /* Answer is denormal */
      uint16_T shift_length;
      aMantissaFirstChunk |= 0x00100000U;/* Add hidden bit */
      shift_length = 1009U - aExponent;

      /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "(aMantissaFirstChunk << (23 - shift_length))
         evaluates sticky bit. Other bit overflows do not have any effect here." */
      sticky = ((aMantissaFirstChunk << (23 - shift_length)) != 0) &&
        ((aMantissaSecondChunk >> (23 - shift_length)) != 0);
      round = ((aMantissaFirstChunk >> (41 - 32 + shift_length) & 0x00000001UL)
               != 0);
      outExponent = 0;
      outMantissa = (uint16_T)((aMantissaFirstChunk >> (42 - 32 + shift_length)));
    } else {
      sticky = ((aMantissaFirstChunk & 0x000001FFUL) != 0 ||
                aMantissaSecondChunk != 0);
      round = ((aMantissaFirstChunk & 0x00000200UL) !=0);
      outExponent = (uint16_T)(aExponent - 1008);
      outMantissa = (uint16_T)(aMantissaFirstChunk >>= (42-32));
    }

    /* Perform rounding to nearest even */
    if (round && (sticky || ((outMantissa & 0x0001U) != 0))) {
      outMantissa++;
    }

    if (outMantissa > 0x03FFU) {       /* Rounding causes overflow */
      outExponent++;
      outMantissa = 0;
    }

    outExponent <<= 10;
  }

  bitPattern = (outSign | outExponent | outMantissa);
}

/* Basic Arithmetic Operations */
real16_T real16_T::operator+(real16_T a) const
{
  return real16_T(this->operator real32_T() + static_cast<real32_T>(a));
}

real16_T real16_T::operator-(real16_T a) const
{
  return real16_T(this->operator real32_T() - static_cast<real32_T>(a));
}

real16_T real16_T::operator*(real16_T a) const
{
  return real16_T(this->operator real32_T() * static_cast<real32_T>(a));
}

real16_T real16_T::operator/(real16_T a) const
{
  return real16_T(this->operator real32_T() / static_cast<real32_T>(a));
}

real16_T real16_T::operator+() const
{
  return (*this);
}

real16_T real16_T::operator-() const
{
  real16_T tmp;
  tmp.bitPattern = (bitPattern ^ 0x8000U);
  return tmp;
}

real16_T& real16_T::operator++()
{
  real16_T tmp( this->operator real32_T() + 1.0f );
  bitPattern = tmp.bitPattern;
  return (*this);
}

real16_T real16_T::operator++(int)
{
  real16_T old(*this);
  real16_T tmp( this->operator real32_T() + 1.0f );
  bitPattern = tmp.bitPattern;
  return old;
}

real16_T& real16_T::operator--()
{
  real16_T tmp( this->operator real32_T() - 1.0f );
  bitPattern = tmp.bitPattern;
  return (*this);
}

real16_T real16_T::operator--(int)
{
  real16_T old(*this);
  real16_T tmp( this->operator real32_T() - 1.0f );
  bitPattern = tmp.bitPattern;
  return old;
}

/* Relational Operations */
boolean_T real16_T::operator==(real16_T a) const
{
  return (this->operator real32_T() == static_cast<real32_T>(a));
}

boolean_T real16_T::operator!=(real16_T a) const
{
  return (this->operator real32_T() != static_cast<real32_T>(a));
}

boolean_T real16_T::operator>=(real16_T a) const
{
  return (this->operator real32_T() >= static_cast<real32_T>(a));
}

boolean_T real16_T::operator>(real16_T a) const
{
  return (this->operator real32_T() > static_cast<real32_T>(a));
}

boolean_T real16_T::operator<=(real16_T a) const
{
  return (this->operator real32_T() <= static_cast<real32_T>(a));
}

boolean_T real16_T::operator<(real16_T a) const
{
  return (this->operator real32_T() < static_cast<real32_T>(a));
}

/* Assignment operator overloading */
real16_T& real16_T::operator= (const real16_T& a)
{
  bitPattern = a.bitPattern;
  return (*this);
}

void real16_T::operator= (const volatile real16_T& a) volatile
{
  const_cast<real16_T&>(*this) = const_cast<real16_T&>(a);
}
void real16_T::operator=(const real16_T& a) volatile
{
  const_cast<real16_T&>(*this) = const_cast<real16_T&>(a);
}
/* Assignments */
real16_T& real16_T::operator+=(real16_T a)
{
  real16_T tmp(this->operator real32_T() + static_cast<real32_T>(a));
  bitPattern = tmp.bitPattern;
  return (*this);
}
real16_T& real16_T::operator-=(real16_T a)
{
  real16_T tmp(this->operator real32_T() - static_cast<real32_T>(a));
  bitPattern = tmp.bitPattern;
  return (*this);
}
real16_T& real16_T::operator*=(real16_T a)
{
  real16_T tmp(this->operator real32_T() * static_cast<real32_T>(a));
  bitPattern = tmp.bitPattern;
  return (*this);
}
real16_T& real16_T::operator/=(real16_T a)
{
  real16_T tmp(this->operator real32_T() / static_cast<real32_T>(a));
  bitPattern = tmp.bitPattern;
  return (*this);
}
