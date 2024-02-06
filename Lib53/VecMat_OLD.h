// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Vector and matrix structs and functions.
// OLD VERSION.


#pragma once


namespace Lib53_OLD
{
   // +---------+
   // | Structs |
   // +---------+

   // A 2-dimensional vector with double values.
   struct Vector2
   {
      double x, y;

      Vector2();
      Vector2(double x, double y);

      Vector2 operator+(const Vector2& other) const;
      Vector2 operator-(const Vector2& other) const;
      Vector2 operator*(const double& other) const;
      Vector2 operator/(const double& other) const;

      Vector2& operator=(const Vector2& other);
      Vector2& operator+=(const Vector2& other);
      Vector2& operator-=(const Vector2& other);
      Vector2& operator*=(const double& other);
      Vector2& operator/=(const double& other);

      bool operator==(const Vector2& other) const;
      bool operator!=(const Vector2& other) const;
   };

   // A 3-dimensional vector with double values.
   struct Vector3
   {
      double x, y, z;

      Vector3();
      Vector3(double x, double y, double z);

      Vector3 operator+(const Vector3& other) const;
      Vector3 operator-(const Vector3& other) const;
      Vector3 operator*(const double& other) const;
      Vector3 operator/(const double& other) const;

      Vector3& operator=(const Vector3& other);
      Vector3& operator+=(const Vector3& other);
      Vector3& operator-=(const Vector3& other);
      Vector3& operator*=(const double& other);
      Vector3& operator/=(const double& other);

      bool operator==(const Vector3& other) const;
      bool operator!=(const Vector3& other) const;
   };

   // A 4-dimensional vector with double values.
   struct Vector4
   {
      double x, y, z, w;

      Vector4();
      Vector4(double x, double y, double z, double w);

      Vector4 operator+(const Vector4& other) const;
      Vector4 operator-(const Vector4& other) const;
      Vector4 operator*(const double& other) const;
      Vector4 operator/(const double& other) const;

      Vector4& operator=(const Vector4& other);
      Vector4& operator+=(const Vector4& other);
      Vector4& operator-=(const Vector4& other);
      Vector4& operator*=(const double& other);
      Vector4& operator/=(const double& other);

      bool operator==(const Vector4& other) const;
      bool operator!=(const Vector4& other) const;
   };

   // A 2x2 matrix.
   struct Matrix2x2
   {
      Vector2 x, y;

      Matrix2x2();
      Matrix2x2(const Vector2& x, const Vector2& y);
      Matrix2x2(double xx, double yx,
         double xy, double yy);

      Matrix2x2 operator+(const Matrix2x2& other) const;
      Matrix2x2 operator-(const Matrix2x2& other) const;
      Matrix2x2 operator*(const double& other) const;
      Matrix2x2 operator/(const double& other) const;

      Matrix2x2& operator=(const Matrix2x2& other);
      Matrix2x2& operator+=(const Matrix2x2& other);
      Matrix2x2& operator-=(const Matrix2x2& other);
      Matrix2x2& operator*=(const double& other);
      Matrix2x2& operator/=(const double& other);

      bool operator==(const Matrix2x2& other) const;
      bool operator!=(const Matrix2x2& other) const;
   };

   // A 3x3 matrix.
   struct Matrix3x3
   {
      Vector3 x, y, z;

      Matrix3x3();
      Matrix3x3(const Vector3& x, const Vector3& y, const Vector3& z);
      Matrix3x3(double xx, double yx, double zx,
         double xy, double yy, double zy,
         double xz, double yz, double zz);

      Matrix3x3 operator+(const Matrix3x3& other) const;
      Matrix3x3 operator-(const Matrix3x3& other) const;
      Matrix3x3 operator*(const double& other) const;
      Matrix3x3 operator/(const double& other) const;

      Matrix3x3& operator=(const Matrix3x3& other);
      Matrix3x3& operator+=(const Matrix3x3& other);
      Matrix3x3& operator-=(const Matrix3x3& other);
      Matrix3x3& operator*=(const double& other);
      Matrix3x3& operator/=(const double& other);

      bool operator==(const Matrix3x3& other) const;
      bool operator!=(const Matrix3x3& other) const;
   };

   // A 4x4 matrix.
   struct Matrix4x4
   {
      Vector4 x, y, z, w;

      Matrix4x4();
      Matrix4x4(const Vector4& x, const Vector4& y,
         const Vector4& z, const Vector4& w);
      Matrix4x4(double xx, double yx, double zx, double wx,
         double xy, double yy, double zy, double wy,
         double xz, double yz, double zz, double wz,
         double xw, double yw, double zw, double ww);

      Matrix4x4 operator+(const Matrix4x4& other) const;
      Matrix4x4 operator-(const Matrix4x4& other) const;
      Matrix4x4 operator*(const double& other) const;
      Matrix4x4 operator/(const double& other) const;

      Matrix4x4& operator=(const Matrix4x4& other);
      Matrix4x4& operator+=(const Matrix4x4& other);
      Matrix4x4& operator-=(const Matrix4x4& other);
      Matrix4x4& operator*=(const double& other);
      Matrix4x4& operator/=(const double& other);

      bool operator==(const Matrix4x4& other) const;
      bool operator!=(const Matrix4x4& other) const;
   };


   // +--------------------+
   // | External operators |
   // +--------------------+

   Vector2 operator*(const double& lhs, const Vector2& rhs);
   Vector3 operator*(const double& lhs, const Vector3& rhs);
   Vector4 operator*(const double& lhs, const Vector4& rhs);
   Matrix2x2 operator*(const double& lhs, const Matrix2x2& rhs);
   Matrix3x3 operator*(const double& lhs, const Matrix3x3& rhs);
   Matrix4x4 operator*(const double& lhs, const Matrix4x4& rhs);


   // +-----------+
   // | Functions |
   // +-----------+

   /**
    * Convert vector 'vec' into an array.
    *
    * @param vec Vector converted into an array.
    * @param arr Pointer to store array at.
    *
    * @returns 1-dimensional array.
    */
   bool VecToArr(Vector2 vec, double arr[2]);
   bool VecToArr(Vector3 vec, double arr[3]);
   bool VecToArr(Vector4 vec, double arr[4]);

   /**
    * Convert matrix 'mat' into an array.
    *
    * @param mat Matrix converted into an array.
    *
    * @returns 2-dimensional array.
    */
   bool MatToArr(Matrix2x2 mat, double arr[2][2]);
   bool MatToArr(Matrix3x3 mat, double arr[3][3]);
   bool MatToArr(Matrix4x4 mat, double arr[4][4]);

   /**
    * Get the length of vector 'vec'.
    *
    * @param vec Vector you get the length of.
    *
    * @returns Length of 'vec' as a double value.
    */
   double Length(Vector2 vec);
   double Length(Vector3 vec);
   double Length(Vector4 vec);

   /**
    * Get the normalized vector of vector 'vec'.
    *
    * @param vec Vector you get normalized.
    *
    * @returns Vector of length 1 with the same direction as 'vec'.
    */
   Vector2 Normalized(Vector2 vec);
   Vector3 Normalized(Vector3 vec);
   Vector4 Normalized(Vector4 vec);

   /**
    * Get the dot product of vectors 'lhs' and 'rhs'.
    *
    * @param lhs Vector on the left-hand side of dot.
    * @param rhs Vector on the right-hand side of dot.
    *
    * @returns Dot product of 'lhs' and 'rhs' as a double value.
    */
   double Dot(Vector2 lhs, Vector2 rhs);
   double Dot(Vector3 lhs, Vector3 rhs);
   double Dot(Vector4 lhs, Vector4 rhs);

   /**
    * Get the cross product of vectors 'lhs' and 'rhs'.
    * The order of the vectors matters.
    *
    * @param lhs Vector on the left-hand side of cross.
    * @param rhs Vector on the right-hand side of cross.
    *
    * @returns Cross product of 'lhs' and 'rhs'.
    */
   Vector3 Cross(Vector3 lhs, Vector3 rhs);

   /**
    * Get the vector from transforming vector 'vec' through transfomation
    * matrix 'mat'.
    *
    * @param vec Vector to transform.
    * @param mat Transformation matrix.
    *
    * @returns The result from transforming 'vec' through 'mat'.
    */
   Vector2 MatrixTransform(Vector2 vec, Matrix2x2 mat);
   Vector3 MatrixTransform(Vector3 vec, Matrix3x3 mat);
   Vector4 MatrixTransform(Vector4 vec, Matrix4x4 mat);

   /**
    * Get the transposed matrix of matrix 'mat'.
    *
    * @param mat Matrix to transpose.
    *
    * @returns Transposed matrix of 'mat'.
    */
   Matrix2x2 Transposed(Matrix2x2 mat);
   Matrix3x3 Transposed(Matrix3x3 mat);
   Matrix4x4 Transposed(Matrix4x4 mat);
}