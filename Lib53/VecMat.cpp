// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Source file for 'VecMat.h'.
// WIP.


#include "VecMat.h"


namespace Lib53
{
   // +-----------------+
   // | Vector2 methods |
   // +-----------------+


   template <typename valType>
   Vector2<valType>::Vector2()
   {
      static_assert(std::is_floating_point_v<valType> ||
         std::is_integral_v<valType>,
         "ERROR: [Vector2] Template must contain floating point or"
         " integral.");

      x = (valType)0;
      y = (valType)0;
   }
   template<typename valType>
   Vector2<valType>::Vector2(const valType& x, const valType& y)
   {
      static_assert(std::is_floating_point_v<valType> ||
         std::is_integral_v<valType>,
         "ERROR: [Vector2] Template must contain floating point or"
         " integral.");

      this->x = x;
      this->y = y;
   };

   template <typename valType>
   Vector2<valType> Vector2<valType>::operator+(const Vector2<valType>& other) const
   {
      return Vector<valType>(x + other.x, y + other.y);
   }

   template <typename valType>
   Vector2<valType> Vector2<valType>::operator-(const Vector2<valType>& other) const
   {
      return Vector<valType>(x - other.x, y - other.y);
   }

   template <typename valType>
   Vector2<valType> Vector2<valType>::operator*(const valType& other) const
   {
      return Vector<valType>(x * other, y * other);
   }

   template <typename valType>
   Vector2<valType> Vector2<valType>::operator/(const valType& other) const
   {
      return Vector2<valType>(x / other, y / other);
   }


   template <typename valType>
   Vector2<valType>& Vector2<valType>::operator=(const Vector2<valType>& other)
   {
      if (this != other)
      {
         x = other.x;
         y = other.y;
      }

      return *this;
   }

   template <typename valType>
   Vector2<valType>& Vector2<valType>::operator+=(const Vector2<valType>& other)
   {
      *this = *this + other;

      return *this;
   }

   template <typename valType>
   Vector2<valType>& Vector2<valType>::operator-=(const Vector2<valType>& other)
   {

      *this = *this - other;

      return *this;
   }

   template <typename valType>
   Vector2<valType>& Vector2<valType>::operator*=(const valType& other)
   {
      *this = *this * other;

      return *this;
   }

   template <typename valType>
   Vector2<valType>& Vector2<valType>::operator/=(const valType& other)
   {
      *this = *this / other;

      return *this;
   }


   template <typename valType>
   bool Vector2<valType>::operator==(const Vector2<valType>& other) const
   {
      return x == other.x && y == other.y;
   }

   template <typename valType>
   bool Vector2<valType>::operator!=(const Vector2<valType>& other) const
   {
      return !(*this == other);
   }


   // +----------+
   // | Vector<> |
   // +----------+

   template <typename valType, uint32_t dim>
   Vector<valType, dim>::Vector()
   {
      values = valType[dim];

      for (int i = 0; i < dim; i++)
      {
         values[i] = (valType)0;
      }
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim>::Vector(valType values[dim])
   {
      this->values = values;
   }

   template<typename valType, uint32_t dim>
   valType Vector<valType, dim>::GetValue(uint32_t index)
   {
      return values[index];
   }

   template<typename valType, uint32_t dim>
   valType* Vector<valType, dim>::GetValues(uint32_t start, uint32_t length)
   {
      try
      {
         int end = 0;

         if (length == -1)
         {
            end = dimensions - start;
         }
         else if (start + length > start && start + length <= dimensions)
         {
            end = length;
         }
         else
         {
            throw "ERROR: [Vector::GetValues()] Request out of range.";
         }

         valType* vals = new valType[end];
         for (int i = 0; i < end; i++)
         {
            vals[i] = values[start + i];
         }

         return vals;
      }
      catch (const std::exception e)
      {
         std::cout << "\nERROR: [Vector::GetValues()] Failed to get values.\n"
                   << e.what();
      }
      return nullptr;
   }

   template<typename valType, uint32_t dim>
   uint32_t Vector<valType, dim>::GetDim()
   {
      return dimensions;
   }

   template<typename valType, uint32_t dim>
   bool Vector<valType, dim>::FindValue(valType value, uint32_t& index,
                                        uint32_t begin)
   {
      for (int i = begin; i < dimensions; i++)
      {
         if (values[i] == value)
         {
            index = i;
            return true;
         }
      }

      return false;
   }

   template<typename valType, uint32_t dim>
   bool Vector<valType, dim>::FindEveryValue(valType value, uint32_t*& indexes)
   {
      uint32_t* inds = nullptr;
      int amount = 0;
      for (int i = 0; i < dimensions; i++)
      {
         if (values[i] == value)
         {
            amount++;
            uint32_t* temp = inds;
            inds = new uint32_t[amount];

            if (temp != nullptr)
            {
               for (int j = 0; j < amount - 1; j++)
               {
                  inds[j] = temp[j];
               }
            }
            inds[amount - 1] = i;
         }
      }

      if (amount == 0)
      {
         return false;
      }
      else
      {
         indexes = inds;
         return true;
      }
   }

   template<typename valType, uint32_t dim>
   valType* Vector<valType, dim>::ToArray()
   {
      return values;
   }

   template<typename valType, uint32_t dim>
   double Vector<valType, dim>::Distance(Vector other)
   {
      Vector between = other - *this;

      return between.Length();
   }

   template<typename valType, uint32_t dim>
   double Vector<valType, dim>::Angle(Vector other)
   {
      double dotProd = (double)Dot(*this, other);
      double denom = Length() + other.Length();
      return acos(dotProd / denom);
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim> Vector<valType, dim>::Toward(Vector other)
   {
      Vector vec = other - *this;
      vec.Normalize();
      return vec;
   }

   template<typename valType, uint32_t dim>
   double Vector<valType, dim>::Length()
   {
      double sqrSum = 0.0;
      for (valType val : values)
      {
         sqrSum += pow((double)val, 2.0);
      }

      return sqrt(sqrSum);
   }

   template<typename valType, uint32_t dim>
   void Vector<valType, dim>::Normalize()
   {
      valType len = (valType)Length();
      for (int i = 0; i < dimensions; i++)
      {
         values /= len;
      }
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim> Vector<valType, dim>::operator+(const Vector& other) const
   {
      valType vals[dim]{};
      for (int i = 0; i < dimensions; i++)
      {
         vals[i] = values[i] + other[i];
      }

      return Vector(vals);
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim> Vector<valType, dim>::operator-(const Vector& other) const
   {
      valType vals[dim]{};
      for (int i = 0; i < dimensions; i++)
      {
         vals[i] = values[i] - other[i];
      }

      return Vector(vals);
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim> Vector<valType, dim>::operator*(const valType& other) const
   {
      valType vals[dim]{};
      for (int i = 0; i < dimensions; i++)
      {
         vals[i] = values[i] * other;
      }

      return Vector(vals);
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim> Vector<valType, dim>::operator/(const valType& other) const
   {
      valType vals[dim]{};
      for (int i = 0; i < dimensions; i++)
      {
         vals[i] = values[i] / other;
      }

      return Vector(vals);
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim>& Vector<valType, dim>::operator=(const Vector& other)
   {
      for (int i = 0; i < dimensions; i++)
      {
         values[i] = other[i];
      }

      return *this;
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim>& Vector<valType, dim>::operator+=(const Vector& other)
   {
      for (int i = 0; i < dimensions; i++)
      {
         values[i] = values[i] + other[i];
      }

      return *this;
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim>& Vector<valType, dim>::operator-=(const Vector& other)
   {
      for (int i = 0; i < dimensions; i++)
      {
         values[i] = values[i] - other[i];
      }

      return *this;
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim>& Vector<valType, dim>::operator*=(const valType& other)
   {
      for (int i = 0; i < dimensions; i++)
      {
         values[i] = values[i] * other;
      }

      return *this;
   }

   template<typename valType, uint32_t dim>
   Vector<valType, dim>& Vector<valType, dim>::operator/=(const valType& other)
   {
      for (int i = 0; i < dimensions; i++)
      {
         values[i] = values[i] / other;
      }

      return *this;
   }

   template<typename valType, uint32_t dim>
   bool Vector<valType, dim>::operator==(const Vector& other) const
   {
      if (&*this == &other)
      {
         return true;
      }
      for (int i = 0; i < dimensions; i++)
      {
         if (values[i] != other[i])
         {
            return false;
         }
      }

      return true;
   }

   template<typename valType, uint32_t dim>
   bool Vector<valType, dim>::operator!=(const Vector<valType, dim>& other) const
   {
      return !(*this == other);
   }

   template<typename valType, uint32_t dim>
   valType& Vector<valType, dim>::operator[](int index)
   {
      return values[index];
   }


}