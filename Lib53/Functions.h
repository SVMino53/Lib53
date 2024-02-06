// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// List of mathematical functions.


#pragma once

#include <type_traits>
#include <typeinfo>
#include <cmath>
#include "Fraction.h"


namespace Lib53
{
   struct Fraction;

   /**
    * Absolute value.
    *
    * @param val: Initial value.
    * 
    * @returns Absolute value of 'val'.
    */
   template <class T>
   T Abs(T val)
   {
      static_assert(std::is_arithmetic_v<T> || std::is_same_v<T, Fraction>,
                    "ERROR: [Abs()] Must be integral, floating point or "
                    "fraction.");

      if (val >= T(0))
         return val;

      return T(0) - val;
   };

   /**
    * Sign of value.
    *
    * @param val: Value.
    * 
    * @returns -1: Negative value.
    * @returns 0: Zero value.
    * @returns 1: Positive value.
    */
   template <class T>
   int Sgn(T val)
   {
      static_assert(std::is_arithmetic_v<T> || std::is_same_v<T, Fraction>,
                    "ERROR: [Sgn()] Must be integral, floating point or "
                    "fraction.");

      if (val < T(0))
         return -1;
      else if (val == T(0))
         return 0;

      return 1;
   };

   /**
    * Minimum value.
    *
    * @param a: First value.
    * @param b: Second value.
    * 
    * @returns The lesser value of 'a' and 'b'.
    */
   template <class T>
   T Min(T a, T b)
   {
      static_assert(std::is_arithmetic_v<T> || std::is_same_v<T, Fraction>,
                    "ERROR: [Min()] Must be integral, floating point or "
                    "fraction.");

      if (a <= b)
         return a;

      return b;
   };

   /**
    * Maximum value.
    *
    * @param a: First value.
    * @param b: Second value.
    * 
    * @returns The greater value of 'a' and 'b'.
    */
   template <class T>
   T Max(T a, T b)
   {
      static_assert(std::is_arithmetic_v<T> || std::is_same_v<T, Fraction>,
                   "ERROR: [Abs()] Must be integral, floating point or "
                   "fraction.");

      if (a >= b)
         return a;

      return b;
   };

   /**
    * Value rounded to the nearest integer.
    *
    * @param val: Value.
    * 
    * @returns Nearest integral to 'val'.
    */
   template <typename T, class U>
   T Round(U val)
   {
      static_assert(std::is_integral_v<T> && 
                    (std::is_floating_point_v<U> || 
                     std::is_same_v<U, Fraction>),
                    "ERROR: [Round()] 'T' must be integral, and 'U' must be "
                    "floating point or fraction.");

      if (val < U(0) && val - U(int(val)) != U(-0.5))
         return T(val - U(0.5));

      return T(val + U(0.5));
   };

   /**
    * Value rounded down to the nearest integer.
    *
    * @param val: Value.
    * 
    * @returns Nearest lower integral to 'val'.
    */
   template <typename T, class U>
   T Floor(U val)
   {
      static_assert(std::is_integral_v<T> && 
                    (std::is_floating_point_v<U> || 
                     std::is_same_v<U, Fraction>),
                    "ERROR: [Round()] 'T' must be integral, and 'U' must be "
                    "floating point or fraction.");

      if (val < U(0) && val - U(int(val)) != U(0))
         return T(val - U(1));

      return T(val);
   };

   /**
    * Value rounded up to the nearest integer.
    *
    * @param val: Value.
    * 
    * @returns Nearest upper integral to 'val'.
    */
   template <typename T, class U>
   T Ceil(U val)
   {
      static_assert(std::is_integral_v<T> && 
                    (std::is_floating_point_v<U> || 
                     std::is_same_v<U, Fraction>),
                    "ERROR: [Round()] 'T' must be integral, and 'U' must be "
                    "floating point or fraction.");

      if (val > U(0) && val - U(int(val)) != U(0))
         return T(val + U(1));

      return T(val);
   };

   /**
    * Greatest common divisor.
    * 
    * @param a: First integer.
    * @param b: Second integer.
    * 
    * @returns The greatest common divisor of 'a' and 'b'.
    */
   template <typename T>
   T GCD(T a, T b)
   {
      static_assert(std::is_integral_v<T>, "Must be integral.");

      T absA = Abs(a);
      T absB = Abs(b);

      if (absA == absB || absB == 0)
         return absA;
      else if (absA == 0)
         return absB;

      T gcd = Min(absA, absB);

      while (gcd > 1)
      {
         if (absA % gcd == 0 && absB % gcd == 0)
            break;

         gcd--; // May be optimizable!
      }

      return gcd;
   };

   /**
    * Least common multiple.
    *
    * @param a: First whole number.
    * @param b: Second whole number.
    * 
    * @returns The least common multiple of 'a' and 'b'.
    */
   template <typename T>
   T LCM(T a, T b)
   {
      static_assert(std::is_integral_v<T>, "Must be integral.");

      return Abs(a) / GCD(a, b) * Abs(b);
   };
}