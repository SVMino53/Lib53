// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Source file for 'Fraction.h'.


#include "Fraction.h"


namespace Lib53
{
   // +----------------------+
   // | Fraction constructos |
   // +----------------------+

   Fraction::Fraction()
   {
      num = 0;
      den = 1;
   }

   Fraction::Fraction(int val)
   {
      num = val;
      den = 1;
   }

   Fraction::Fraction(float val)
   {
      num = int(val);
      den = 1;
      while (Abs(float(den) * val - float(num)) > 0.000001f)
      {
         den++;
         num = Round<int>(val * float(den));
      }
   }

   Fraction::Fraction(double val)
   {
      num = int(val);
      den = 1;
      while (Abs(double(den) * val - double(num)) > 0.000001)
      {
         den++;
         num = Round<int>(val * double(den));
      }
   }

   Fraction::Fraction(int num, uint32_t den)
   {
      this->num = num;
      this->den = den;
   }


   // +--------------------+
   // | Fraction operators |
   // +--------------------+

   Fraction Fraction::operator+() const
   {
      return *this;
   }

   Fraction Fraction::operator-() const
   {
      return Fraction(-num, den);
   }

   Fraction Fraction::operator+(const Fraction& other) const
   {
      Fraction fra(num * other.den + other.num * den, den * other.den);
      fra.Simplify();

      return fra;
   }

   Fraction Fraction::operator-(const Fraction& other) const
   {
      Fraction fra(num * other.den - other.num * den, den * other.den);
      fra.Simplify();

      return fra;
   }

   Fraction Fraction::operator*(const Fraction& other) const
   {
      Fraction fra(num * other.num, den * other.den);
      fra.Simplify();

      return fra;
   }

   Fraction Fraction::operator/(const Fraction& other) const
   {
      Fraction fra(Sgn(other.num) * num * other.den,
                   Sgn(other.num) * other.num * den);
      fra.Simplify();

      return fra;
   }

   Fraction& Fraction::operator=(const Fraction& other)
   {
      if (*this != other)
      {
         this->num = other.num;
         this->den = other.den;
      }

      return *this;
   }

   Fraction& Fraction::operator+=(const Fraction& other)
   {
      *this = *this + other;

      return *this;
   }

   Fraction& Fraction::operator-=(const Fraction& other)
   {
      *this = *this - other;

      return *this;
   }

   Fraction& Fraction::operator*=(const Fraction& other)
   {
      *this = *this * other;

      return *this;
   }

   Fraction& Fraction::operator/=(const Fraction& other)
   {
      *this = *this / other;

      return *this;
   }

   bool Fraction::operator==(const Fraction& other) const
   {
      if (this == &other)
         return true;

      return num == other.num && den == other.den;
   }

   bool Fraction::operator!=(const Fraction& other) const
   {
      return !(*this == other);
   }

   bool Fraction::operator<(const Fraction& other) const
   {
      return double(*this) < double(other);
   }

   bool Fraction::operator>(const Fraction& other) const
   {
      return double(*this) > double(other);
   }

   bool Fraction::operator<=(const Fraction& other) const
   {
      return *this < other || *this == other;
   }

   bool Fraction::operator>=(const Fraction& other) const
   {
      return *this > other || *this == other;
   }

   Fraction::operator int() const
   {
      return num / int(den);
   }

   Fraction::operator float() const
   {
      return float(num) / float(den);
   }

   Fraction::operator double() const
   {
      return double(num) / double(den);
   }

   void Fraction::Simplify()
   {
      int gcd = GCD(num, int(den));
      num /= gcd;
      den /= gcd;
   }


   // +--------------------+
   // | External operators |
   // +--------------------+

   //std::istream& operator>>(std::istream& lhs, const Fraction& rhs)
   //{
   //   // TODO: Finish this operator.

   //   return lhs;
   //}

   std::ostream& operator<<(std::ostream& lhs, const Fraction& rhs)
   {
      lhs << rhs.num;
      if (rhs.den != 1)
         lhs << '/' << rhs.den;

      return lhs;
   }

   Fraction operator""_F(long double rhs)
   {
      Fraction fra = Fraction(int(rhs), 1);
      while (abs(long double(fra.den) * rhs - long double(fra.num)) > 0.000001)
      {
         fra.den++;
         fra.num = Round<int>(rhs * long double(fra.den));
      }

      return fra;
   }

   Fraction operator""_F(unsigned long long rhs)
   {
      return Fraction(int(rhs), 1);
   }

}