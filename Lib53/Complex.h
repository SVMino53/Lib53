// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Structs and functions for complex numbers in standard and polar form.
// WIP.


#pragma once

#include <iostream>


namespace Lib53
{
   struct Polar;

   // +---------+
   // | Structs |
   // +---------+

   // A complex number in standard form.
   // re: Real part.
   // im: Imaginary part.
   struct Complex
   {
      // Variables

      double re;
      double im;


      // Constructors

      Complex();
      Complex(Polar& pol);
      Complex(double re, double im);


      // Methods

      /**
       * Gives the polar form of this complex number.
       *
       * @returns This complex number in polar form.
       */
      Polar ToPolar();

      /**
       * Rotates vector of this complex number around the origin on the
       * complex plane.
       *
       * @param angle: Angle in radians rotated counterclockwise.
       */
      void Rotate(double angle);

      /**
       * Gives the conjugate of this complex number.
       *
       * @returns Conjugate of this complex number in standard form.
       */
      Complex Conjugate();

      /**
       * Gives the length of the vector of this complex number.
       *
       * @returns This complex number's vector length.
       */
      double Len();

      /**
       * Gives the argument/angle of the vector of this complex number.
       *
       * @returns Angle in radians counterclockwise from the x+ axis.
       */
      double Arg();


      // Operators

      Complex operator+(const Complex& other) const;
      Complex operator-(const Complex& other) const;
      Complex operator*(const Complex& other) const;
      Complex operator/(const Complex& other) const;

      Complex& operator=(const Complex& other);
      Complex& operator+=(const Complex& other);
      Complex& operator-=(const Complex& other);
      Complex& operator*=(const Complex& other);
      Complex& operator/=(const Complex& other);

      bool operator==(const Complex& other) const;
      bool operator!=(const Complex& other) const;
   };

   // A complex number in polar form.
   // len: Length of the vector.
   // arg: Angle of the vector in radians.
   struct Polar
   {
      // Variables

      double len;
      double arg;


      // Constructors

      Polar();
      Polar(Complex& com);
      Polar(double len, double arg);


      // Methods

      /**
       * Gives the standard form of this complex number.
       *
       * @returns This complex number in standard form.
       */
      Complex ToComplex();

      /**
       * Rotates vector of this complex number around the origin on the
       * complex plane.
       *
       * @param angle: Angle in radians rotated counterclockwise.
       */
      void Rotate(double angle);

      /**
       * Gives the conjugate of this complex number.
       *
       * @returns Conjugate of this complex number in polar form.
       */
      Polar Conjugate();

      /**
       * Gives the real part of this complex number.
       *
       * @returns This complex number's real part.
       */
      double Re();

      /**
       * Gives the imaginary part of this complex number.
       *
       * @returns This complex number's imaginary part.
       */
      double Im();


      // Operators

      Polar operator+(const Polar& other) const;
      Polar operator-(const Polar& other) const;
      Polar operator*(const Polar& other) const;
      Polar operator/(const Polar& other) const;

      Polar& operator=(const Polar& other);
      Polar& operator+=(const Polar& other);
      Polar& operator-=(const Polar& other);
      Polar& operator*=(const Polar& other);
      Polar& operator/=(const Polar& other);

      bool operator==(const Polar& other) const;
      bool operator!=(const Polar& other) const;
   };


   // +--------------------+
   // | External operators |
   // +--------------------+

   std::ostream& operator<<(std::ostream& lhs, const Complex& rhs);
   std::istream& operator>>(std::istream& lhs, Complex& rhs);


   // +-----------+
   // | Functions | 
   // +-----------+

   /**
    * Gives the polar form of a complex number in standard form.
    * 
    * @param ref: The complex number in standard form.
    * 
    * @returns 'ref' in polar form.
    */
   Polar ComplexToPolar(Complex& ref);

   /**
    * Gives the standard form of a complex number in polar form.
    * 
    * @param ref: The complex number in polar form.
    * 
    * @returns 'ref' in standard form.
    */
   Complex PolarToComplex(Polar& ref);


}