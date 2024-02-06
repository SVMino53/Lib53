// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Struct and operators for fractions.


#pragma once

#include <cstdint>
#include <iostream>
#include "Functions.h"


namespace Lib53
{
   // +---------+
   // | Structs |
   // +---------+

   /**
    * @brief A mathematical fraction, containing variables for numerator, 'num',
    * and denominator, 'den'.
    */
   struct Fraction
   {
      int num;      // Numerator
      uint32_t den; // Denominator

      Fraction();
      Fraction(int val);
      Fraction(float val);
      Fraction(double val);
      Fraction(int num, uint32_t den);

      Fraction operator+() const;
      Fraction operator-() const;
      Fraction operator+(const Fraction& other) const;
      Fraction operator-(const Fraction& other) const;
      Fraction operator*(const Fraction& other) const;
      Fraction operator/(const Fraction& other) const;

      Fraction& operator= (const Fraction& other);
      Fraction& operator+=(const Fraction& other);
      Fraction& operator-=(const Fraction& other);
      Fraction& operator*=(const Fraction& other);
      Fraction& operator/=(const Fraction& other);

      bool operator==(const Fraction& other) const;
      bool operator!=(const Fraction& other) const;
      bool operator< (const Fraction& other) const;
      bool operator> (const Fraction& other) const;
      bool operator<=(const Fraction& other) const;
      bool operator>=(const Fraction& other) const;

      operator int() const;
      operator float() const;
      operator double() const;

   private:
      void Simplify();
   };


   // +--------------------+
   // | External operators |
   // +--------------------+

   //std::istream& operator>>(std::istream& lhs, const Fraction& rhs);
   std::ostream& operator<<(std::ostream& lhs, const Fraction& rhs);

   Fraction operator""_F(long double rhs);
   Fraction operator""_F(unsigned long long rhs);
}