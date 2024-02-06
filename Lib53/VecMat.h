// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Structs and functions for vectors and matrixes.
// WIP.


#pragma once

#include <cstdint>
#include <iostream>
#include <cmath>


namespace Lib53
{
   // +---------+
   // | Structs |
   // +---------+

   /**
    * A 2-dimensional vector.
    *
    * @tparam valType: The datatype the values should be.
    */
   template <typename valType>
   struct Vector2
   {
      valType x, y;

      Vector2();
      Vector2(const valType& x, const valType& y);

      Vector2 operator+(const Vector2& other) const;
      Vector2 operator-(const Vector2& other) const;
      Vector2 operator*(const valType& other) const;
      Vector2 operator/(const valType& other) const;

      Vector2& operator=(const Vector2& other);
      Vector2& operator+=(const Vector2& other);
      Vector2& operator-=(const Vector2& other);
      Vector2& operator*=(const valType& other);
      Vector2& operator/=(const valType& other);

      bool operator==(const Vector2& other) const;
      bool operator!=(const Vector2& other) const;
   };

   /**
    * A 3-dimensional vector.
    *
    * @tparam valType: The datatype the values should be.
    */
   template <typename valType>
   struct Vector3
   {
      valType x, y, z;

      Vector3();
      Vector3(const valType& x, const valType& y, const valType& z);

      Vector3 operator+(const Vector3& other) const;
      Vector3 operator-(const Vector3& other) const;
      Vector3 operator*(const valType& other) const;
      Vector3 operator/(const valType& other) const;

      Vector3& operator=(const Vector3& other);
      Vector3& operator+=(const Vector3& other);
      Vector3& operator-=(const Vector3& other);
      Vector3& operator*=(const valType& other);
      Vector3& operator/=(const valType& other);

      bool operator==(const Vector3& other) const;
      bool operator!=(const Vector3& other) const;
   };

   /**
    * A 4-dimensional vector.
    *
    * @tparam valType: The datatype the values should be.
    */
   template <typename valType>
   struct Vector4
   {
      valType x, y, z, w;

      Vector4();
      Vector4(const valType& x, const valType& y, 
              const valType& z, const valType& w);

      Vector4 operator+(const Vector4& other) const;
      Vector4 operator-(const Vector4& other) const;
      Vector4 operator*(const valType& other) const;
      Vector4 operator/(const valType& other) const;

      Vector4& operator=(const Vector4& other);
      Vector4& operator+=(const Vector4& other);
      Vector4& operator-=(const Vector4& other);
      Vector4& operator*=(const valType& other);
      Vector4& operator/=(const valType& other);

      bool operator==(const Vector4& other) const;
      bool operator!=(const Vector4& other) const;
   };

   /**
    * A 2x2 matrix.
    *
    * @tparam valType: The datatype the values should be.
    */
   template <typename valType>
   struct Matrix2x2
   {
      Vector2<valType> x, y;

      Matrix2x2();
      Matrix2x2(const Vector2<valType>& x, const Vector2<valType>& y);
      Matrix2x2(valType xx, valType yx,
                valType xy, valType yy);

      Matrix2x2 operator+(const Matrix2x2& other) const;
      Matrix2x2 operator-(const Matrix2x2& other) const;
      Matrix2x2 operator*(const valType& other) const;
      Matrix2x2 operator/(const valType& other) const;

      Matrix2x2& operator=(const Matrix2x2& other);
      Matrix2x2& operator+=(const Matrix2x2& other);
      Matrix2x2& operator-=(const Matrix2x2& other);
      Matrix2x2& operator*=(const valType& other);
      Matrix2x2& operator/=(const valType& other);

      bool operator==(const Matrix2x2& other) const;
      bool operator!=(const Matrix2x2& other) const;
   };

   /**
    * A 3x3 matrix.
    *
    * @tparam valType: The datatype the values should be.
    */
   template <typename valType>
   struct Matrix3x3
   {
      Vector3<valType> x, y, z;

      Matrix3x3();
      Matrix3x3(const Vector3<valType>& x, const Vector3<valType>& y,
                const Vector3<valType>& z);
      Matrix3x3(valType xx, valType yx, valType zx,
                valType xy, valType yy, valType zy,
                valType xz, valType yz, valType zz);

      Matrix3x3 operator+(const Matrix3x3& other) const;
      Matrix3x3 operator-(const Matrix3x3& other) const;
      Matrix3x3 operator*(const valType& other) const;
      Matrix3x3 operator/(const valType& other) const;

      Matrix3x3& operator=(const Matrix3x3& other);
      Matrix3x3& operator+=(const Matrix3x3& other);
      Matrix3x3& operator-=(const Matrix3x3& other);
      Matrix3x3& operator*=(const valType& other);
      Matrix3x3& operator/=(const valType& other);

      bool operator==(const Matrix3x3& other) const;
      bool operator!=(const Matrix3x3& other) const;
   };

   /**
    * A 4x4 matrix.
    *
    * @tparam valType: The datatype the values should be.
    */
   template <typename valType>
   struct Matrix4x4
   {
      Vector4<valType> x, y, z, w;

      Matrix4x4();
      Matrix4x4(const Vector4<valType>& x, const Vector4<valType>& y,
                const Vector4<valType>& z, const Vector4<valType>& w);
      Matrix4x4(valType xx, valType yx, valType zx, valType wx,
                valType xy, valType yy, valType zy, valType wy,
                valType xz, valType yz, valType zz, valType wz,
                valType xw, valType yw, valType zw, valType ww);

      Matrix4x4 operator+(const Matrix4x4& other) const;
      Matrix4x4 operator-(const Matrix4x4& other) const;
      Matrix4x4 operator*(const valType& other) const;
      Matrix4x4 operator/(const valType& other) const;

      Matrix4x4& operator=(const Matrix4x4& other);
      Matrix4x4& operator+=(const Matrix4x4& other);
      Matrix4x4& operator-=(const Matrix4x4& other);
      Matrix4x4& operator*=(const valType& other);
      Matrix4x4& operator/=(const valType& other);

      bool operator==(const Matrix4x4& other) const;
      bool operator!=(const Matrix4x4& other) const;
   };

   /**
    * A vector of given dimensions.
    * 
    * @tparam valType: The datatype the values should be.
    * @tparam dim: The number of dimensions.
    */
   template <typename valType, uint32_t dim>
   class Vector
   {
      const uint32_t dimensions = dim;
      valType values[];

   public:
      Vector();
      Vector(valType values[dim]);

      valType GetValue(uint32_t index);
      valType* GetValues(uint32_t start = 0, uint32_t length = -1);
      uint32_t GetDim();
      bool FindValue(valType value, uint32_t& index, uint32_t begin = 0);
      bool FindEveryValue(valType value, uint32_t*& indexes);
      valType* ToArray();

      double Distance(Vector other);
      double Angle(Vector other);
      Vector Toward(Vector other);
      double Length();
      void Normalize();

      Vector operator+(const Vector& other) const;
      Vector operator-(const Vector& other) const;
      Vector operator*(const valType& other) const;
      Vector operator/(const valType& other) const;

      Vector& operator=(const Vector& other);
      Vector& operator+=(const Vector& other);
      Vector& operator-=(const Vector& other);
      Vector& operator*=(const valType& other);
      Vector& operator/=(const valType& other);

      bool operator==(const Vector& other) const;
      bool operator!=(const Vector& other) const;

      valType& operator[](int index);
   };

   /**
    * A matrix of given dimensions.
    * 
    * @tparam valType: The datatype the values should be.
    * @tparam m: The height of the matrix.
    * @tparam n: The width of the matrix.
    */
   template <typename valType, uint32_t m, uint32_t n>
   class Matrix
   {
      uint32_t height = m;
      uint32_t width = n;
      valType values[][];

   public:
      Matrix();
      Matrix(Vector<valType, m> values[n]);
      Matrix(valType values[n][m]);

      valType GetValue(uint32_t m_index, uint32_t n_index);
      uint32_t GetHeight();
      uint32_t GetWidth();
      template <uint32_t dim = width>
      Vector<valType, dim> GetRow(uint32_t index);
      template <uint32_t dim = height>
      Vector<valType, dim> GetColumn(uint32_t index);
      uint32_t* FindValue(valType value, uint32_t begin = 0);
      uint32_t** FindEveryValue(valType value);

      void Transpose();
      void ScalarMultiply(valType scalar);
      void Add(Matrix other);
      void Sub(Matrix other);
      template<uint32_t rhs_n, uint32_t shared_dim = width>
      void MatrixMultiply(Matrix<valType, shared_dim, rhs_n> rhs);

      void RowAdd(const uint32_t to, const uint32_t from);
      void RowMultiply(valType scalar);
      void RowSwitch(const uint32_t row1, const uint32_t row2);

      Matrix operator+(const Matrix& other) const;
      Matrix operator-(const Matrix& other) const;
      Matrix operator*(const valType& other) const;
      Matrix operator/(const valType& other) const;

      Matrix& operator=(const Matrix& other);
      Matrix& operator+=(const Matrix& other);
      Matrix& operator-=(const Matrix& other);
      Matrix& operator*=(const valType& other);
      Matrix& operator/=(const valType& other);

      bool operator==(const Matrix& other) const;
      bool operator!=(const Matrix& other) const;
   };


   // +--------------------+
   // | External operators |
   // +--------------------+

   template<typename valType>
   Vector2<valType> operator*(const valType& lhs, 
                              const Vector2<valType>& rhs);
   template<typename valType>
   Vector3<valType> operator*(const valType& lhs, 
                              const Vector3<valType>& rhs);
   template<typename valType>
   Vector4<valType> operator*(const valType& lhs, 
                              const Vector4<valType>& rhs);
   template<typename valType>
   Matrix2x2<valType> operator*(const valType& lhs, 
                                const Matrix2x2<valType>& rhs);
   template<typename valType>
   Matrix3x3<valType> operator*(const valType& lhs, 
                                const Matrix3x3<valType>& rhs);
   template<typename valType>
   Matrix4x4<valType> operator*(const valType& lhs, 
                                const Matrix4x4<valType>& rhs);


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
   template<typename valType>
   bool VecToArr(Vector2<valType> vec, valType arr[2]);
   template<typename valType>
   bool VecToArr(Vector3<valType> vec, valType arr[3]);
   template<typename valType>
   bool VecToArr(Vector4<valType> vec, valType arr[4]);
   template<typename valType, int dim>
   bool VecToArr(Vector<valType, dim> vec, valType arr[dim]);

   /**
    * Convert matrix 'mat' into an array.
    *
    * @param mat Matrix converted into an array.
    *
    * @returns 2-dimensional array.
    */
   template<typename valType>
   bool MatToArr(Matrix2x2<valType> mat, valType arr[2][2]);
   template<typename valType>
   bool MatToArr(Matrix3x3<valType> mat, valType arr[3][3]);
   template<typename valType>
   bool MatToArr(Matrix4x4<valType> mat, valType arr[4][4]);
   template<typename valType, uint32_t m, uint32_t n>
   bool MatToArr(Matrix<valType, m, n> mat, valType arr[n][m]);

   /**
    * Get the length of vector 'vec'.
    *
    * @param vec Vector you get the length of.
    *
    * @returns Length of 'vec' as a double value.
    */
   template<typename valType>
   double Length(Vector2<valType> vec);
   template<typename valType>
   double Length(Vector3<valType> vec);
   template<typename valType>
   double Length(Vector4<valType> vec);
   template<typename valType, uint32_t dim>
   double Length(Vector<valType, dim> vec);

   /**
    * Get the normalized vector of vector 'vec'.
    *
    * @param vec Vector you get normalized.
    *
    * @returns Vector of length 1 with the same direction as 'vec'.
    */
   template<typename valType>
   Vector2<valType> Normalized(Vector2<valType> vec);
   template<typename valType>
   Vector3<valType> Normalized(Vector3<valType> vec);
   template<typename valType>
   Vector4<valType> Normalized(Vector4<valType> vec);
   template<typename valType, uint32_t dim>
   Vector<valType, dim> Normalized(Vector<valType, dim> vec);

   /**
    * Get the dot product of vectors 'lhs' and 'rhs'.
    *
    * @param lhs Vector on the left-hand side of dot.
    * @param rhs Vector on the right-hand side of dot.
    *
    * @returns Dot product of 'lhs' and 'rhs' as a double value.
    */
   template<typename valType>
   valType Dot(Vector2<valType> lhs, Vector2<valType> rhs);
   template<typename valType>
   valType Dot(Vector3<valType> lhs, Vector3<valType> rhs);
   template<typename valType>
   valType Dot(Vector4<valType> lhs, Vector4<valType> rhs);
   template<typename valType, uint32_t dim>
   valType Dot(Vector<valType, dim> lhs, Vector<valType, dim> rhs);

   /**
    * Get the cross product of vectors 'lhs' and 'rhs'.
    * The order of the vectors matters.
    *
    * @param lhs Vector on the left-hand side of cross.
    * @param rhs Vector on the right-hand side of cross.
    *
    * @returns Cross product of 'lhs' and 'rhs'.
    */
   template<typename valType>
   Vector3<valType> Cross(Vector3<valType> lhs, Vector3<valType> rhs);
   template<typename valType>
   Vector<valType, 3> Cross(Vector<valType, 3> lhs, Vector<valType, 3> rhs);

   /**
    * Get the vector from transforming vector 'vec' through transfomation
    * matrix 'mat'.
    *
    * @param vec Vector to transform.
    * @param mat Transformation matrix.
    *
    * @returns The result from transforming 'vec' through 'mat'.
    */
   template<typename valType>
   Vector2<valType> MatrixTransformed(Vector2<valType> vec, 
                                      Matrix2x2<valType> mat);
   template<typename valType>
   Vector3<valType> MatrixTransformed(Vector3<valType> vec, 
                                      Matrix3x3<valType> mat);
   template<typename valType>
   Vector4<valType> MatrixTransformed(Vector4<valType> vec, 
                                      Matrix4x4<valType> mat);
   template<typename valType, uint32_t dim>
   Vector<valType, dim> MatrixTransformed(Vector<valType, dim> vec, 
                                          Matrix<valType, dim, dim> mat);

   /**
    * Get the transposed matrix of matrix 'mat'.
    *
    * @param mat Matrix to transpose.
    *
    * @returns Transposed matrix of 'mat'.
    */
   template<typename valType>
   Matrix2x2<valType> Transposed(Matrix2x2<valType> mat);
   template<typename valType>
   Matrix3x3<valType> Transposed(Matrix3x3<valType> mat);
   template<typename valType>
   Matrix4x4<valType> Transposed(Matrix4x4<valType> mat);
   template<typename valType, uint32_t m, uint32_t n>
   Matrix<valType, n, m> Transposed(Matrix<valType, m, n> mat);

   template <typename valType>
   Matrix2x2<valType> Rotate2DMat(double angle);
   template <typename valType>
   Matrix3x3<valType> RotateXMat(double angle);
   template <typename valType>
   Matrix3x3<valType> RotateYMat(double angle);
   template <typename valType>
   Matrix3x3<valType> RotateZMat(double angle);
   template <typename valType>
   Matrix3x3<valType> Rotate3DMat(Vector3<valType> axis, double angle);

   template <typename valType>
   Matrix2x2<valType> Scale2DMat(valType factor);

   template <typename valType>
   Matrix2x2<valType> HoriShearMat(valType factor);
   template <typename valType>
   Matrix2x2<valType> VertShearMat(valType factor);
   template <typename valType>
   Matrix3x3<valType> ShearXMat(valType factor);
   template <typename valType>
   Matrix3x3<valType> ShearYMat(valType factor);
   template <typename valType>
   Matrix3x3<valType> ShearZMat(valType factor);
   template <typename valType, uint32_t dim>
   Matrix<valType, dim, dim> ShearMat(uint32_t axis, valType factor);

   template <typename valType>
   Matrix2x2<valType> SqueezeMat(valType factor);
}