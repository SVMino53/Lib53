// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Source file for 'Functions.h'.
// OBS! Currently unused/unusable because of linker issues.
// Will fix this later.


// TODO: Implement source code and fix to identify symbols.


//#include "Functions.h"
//
//
//
//namespace Lib53
//{
//   template <class T>
//   T Abs(T val)
//   {
//      static_assert(std::is_arithmetic_v<T>,
//                    "Must be integral or floating point");
//
//      if (val >= T(0))
//         return val;
//
//      return -val;
//   }
//
//   template<class T>
//   T Min(T a, T b)
//   {
//      static_assert(std::is_arithmetic_v<T>,
//                    "Must be integral or floating point");
//
//      if (a <= b)
//         return a;
//
//      return b;
//   }
//
//   template<class T>
//   T Max(T a, T b)
//   {
//      static_assert(std::is_arithmetic_v<T>,
//                    "Must be integral or floating point");
//
//      if (a >= b)
//         return a;
//
//      return b;
//   }
//
//   template <typename T>
//   T GCD(T a, T b)
//   {
//      static_assert(std::is_integral_v<T>, "Must be integral.");
//
//      T absA = Abs(a);
//      T absB = Abs(b);
//
//      if (absA == absB)
//         return absA;
//
//      T gcd = Min(absA, absB);
//
//      while (gcd > 1)
//      {
//         if (absA % gcd == 0 && absB % gcd == 0)
//            break;
//
//         for (int i = 2; i < gcd / 2; i++)
//         {
//            if (gcd % i == 0)
//            {
//               gcd /= i;
//               break;
//            }
//         }
//      }
//
//      return gcd;
//   }
//
//   template<typename T>
//   T LCM(T a, T b)
//   {
//      static_assert(std::is_integral_v<T>, "Must be integral.");
//
//      return Abs(a) / GCD(a, b) * Abs(b);
//   }
//
//}