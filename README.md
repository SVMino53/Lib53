# Lib53
#### Created by Isak "Mino53" Forsberg, 2024-01-16

This is a static library I am creating to use for my other projects. It will contain useful classes, structs, constants and functions to help with basic and advanced mathematical calculations.

The library is currently in a very early state and not useful yet. Once it is useful, this document will be updated.

## Latest Version Update

***Version:*** *0.1*  
***Date:*** *2024-02-06*

### Symbol explanation

- **+ \[name]**: \[name] has been added to the project.  
- **- \[name]**: \[name] has been removed from the project.  
- **\* \[name]**: \[name] has been changed.  
- **/ \[name]**: \[name] has been bug fixed.  
- *"\[text]"*: Description.  
- **\[function](pars1)**: Function overloads.  
	- **(pars2)**  
	- **...**  
- **T, U, ...**: Template parameters.

### What's New?

- **+ Lib53.h** | *"Header file collectively containing all relevant header files."*  
- **+ Test.h/.cpp** | *"Files used to run, test and debug library components."*  
	- **+ bool RunTest()** | *"Function to add code to to test components."*  
- **+ Constants.h** | *"List of mathematical constants."*  
	- **+ constexpr double PI** | *The very common constant pi.*  
	- **+ constexpr double TAU** | *The not as common constant tau, which is equal to 2 \* pi.*
- **+ Functions.h** | *List of mathematical functions.*  
	- **+ T Abs(T)** | *"Returns the absolute value of the parameter."*  
	- **+ int Sgn(T)** | *"Returns the sign of the parameter. Negative: -1, positive: 1, and zero: 0."*  
	- **+ T Min(T, T)** | *"Returns the minimum value of the two parameters."*  
	- **+ T Max(T, T)** | *"Returns the maximum value of the two parameters."*  
	- **+ T Round(U)** | *"Returns the nearest integer to the parameter."*  
	- **+ T Floor(U)** | *"Returns the nearest lower integer to the parameter."*  
	- **+ T Ceil(U)** | *"Returns the nearest upper integer to the parameter."*  
	- **+ T GCD(T, T)** | *"Returns the greatest common divisor of the two parameters."*  
	- **+ T LCM(T, T)** | *"Returns the least common multiple of the two parameters."*  
- **+ Fraction.h/.cpp** | *"Struct and operators for mathematical fractions."*  
	- **+ struct Fraction** | *"A mathematical fraction"*  
		- **+ int num** | *"Numerator."*  
		- **+ uint32_t den** | *"Denominator."*  
		- **+ Fraction()** | *"Constructors."*  
			- **(int)**  
			- **(float)**  
			- **(double)**  
			- **(int, uint32_t)**  
		- **+** ***Operators*** | *"Common C++ operators."*  
	- **+ std::ostream& operator<<(std::ostream&, const Fraction&)**  
	- **+ Fraction operator""_F(long double)** | *"Literal operator returning a 'Fraction'."*  
		- **(unsigned long long)**  
- **+ VecMat.h/.cpp** | *"Structs and functions for vectors and matrixes."* ***WIP***  
- **+ Complex.h/.cpp** | *"Structs and functions for complex numbers in standard and polar form."* ***WIP***
