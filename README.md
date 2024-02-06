# Lib53
#### Created by Isak "Mino53" Forsberg, 2024-01-16

This is a static library I am creating to use for my other projects. It will contain useful classes, structs, constants and functions to help with advanced math.

The library is currently in a very early state and not useful yet. Once it is useful, this document will be updated.

## Latest Version Update

***Version:*** *0.1*  
***Date:*** *2024-02-06*

### Symbol explanation

**+ \[name]**: Added to project.  
**- \[name]**: Removed from project.  
**\* \[name]**: Changed component.  
**/ \[name]**: Bug fixed component.  
*"\[text]"*: Description.  
**\[function](pars1)**: Function overloads.  
	\t**(pars2)**  
	\t**...**  
**T, U, ...**: Template parameters.

### What's New?

**+ Lib53.h** | *"Header file collectively containing all relevant header files."*  
**+ Test.h/.cpp** | *"Files used to run, test and debug library components."*  
	\t**+ bool RunTest()** | *"Function to add code to to test components."*  
**+ Constants.h** | *"List of mathematical constants."*  
	\t**+ constexpr double PI** | *The very common constant pi, ($\pi$).*  
	\t**+ constexpr double TAU** | *The not as common constant tau, ($\tau$), which is equal to $2\pi$.*
**+ Functions.h** | *List of mathematical functions.*  
	\t**+ T Abs(T)** | *"Returns the absolute value of the parameter."*  
	\t**+ int Sgn(T)** | *"Returns the sign of the parameter. Negative: -1, positive: 1, and zero: 0."*  
	\t**+ T Min(T, T)** | *"Returns the minimum value of the two parameters."*  
	\t**+ T Max(T, T)** | *"Returns the maximum value of the two parameters."*  
	\t**+ T Round(U)** | *"Returns the nearest integer to the parameter."*  
	\t**+ T Floor(U)** | *"Returns the nearest lower integer to the parameter."*  
	\t**+ T Ceil(U)** | *"Returns the nearest upper integer to the parameter."*  
	\t**+ T GCD(T, T)** | *"Returns the greatest common divisor of the two parameters."*  
	\t**+ T LCM(T, T)** | *"Returns the least common multiple of the two parameters."*  
**+ Fraction.h/.cpp** | *"Struct and operators for mathematical fractions."*  
	\t**+ struct Fraction** | *"A mathematical fraction"*  
		\t\t**+ int num** | *"Numerator."*  
		\t\t**+ uint32_t den** | *"Denominator."*  
		\t\t**+ Fraction()** | *"Constructors."*  
			\t\t\t**(int)**  
			\t\t\t**(float)**  
			\t\t\t**(double)**  
			\t\t\t**(int, uint32_t)**  
		\t\t**+** ***Operators*** | *"Common C++ operators."*  
	\t**+ std::ostream& operator<<(std::ostream&, const Fraction&)**  
	\t**+ Fraction operator""_F(long double)** | *"Literal operator returning a 'Fraction'."*  
		\t\t**(unsigned long long)**  
**+ VecMat.h/.cpp** | *"Structs and functions for vectors and matrixes."* ***WIP***  
**+ Complex.h/.cpp** | *"Structs and functions for complex numbers in standard and polar form."* ***WIP***
