#include "Complex.h"

#include <cmath>
#include <string>
#include "Constants.h"



namespace Lib53
{
	// +-----------------+
	// | Complex methods |
	// +-----------------+

	Complex::Complex()
	{
		re = 0.0;
		im = 0.0;
	}

	Complex::Complex(Polar& pol)
	{
		re = pol.Re();
		im = pol.Im();
	}

	Complex::Complex(double re, double im)
	{
		this->re = re;
		this->im = im;
	}

	Polar Complex::ToPolar()
	{
		return Polar(Len(), Arg());
	}

	void Complex::Rotate(double angle)
	{
		Polar newPol(Len(), Arg() + angle);
		re = newPol.Re();
		im = newPol.Im();
	}

	Complex Complex::Conjugate()
	{
		return Complex(re, -im);
	}

	double Complex::Len()
	{
		return sqrt(pow(re, 2.0) + pow(im, 2.0));
	}

	double Complex::Arg()
	{
		if (re == 0.0)
		{
			if (im < 0.0)
				return 3.0 / 4.0 * TAU;
			else if (im > 0.0)
				return 1.0 / 4.0 * TAU;
			else
				return 0.0;
		}
		else
		{
			double arg = atan2(im, re);
			if (arg < 0.0)
			{
				arg += TAU;
			}

			return arg;
		}
	}

	Complex Complex::operator+(const Complex& other) const
	{
		return Complex(re + other.re, im + other.im);
	}

	Complex Complex::operator-(const Complex& other) const
	{
		return Complex(re - other.re, im - other.im);
	}

	Complex Complex::operator*(const Complex& other) const
	{
		return Complex(re * other.re - im * other.im,
		               re * other.im + im * other.re);
	}

	Complex Complex::operator/(const Complex& other) const
	{
		const Complex conju(other.re, -other.im);
		const Complex numer = *this * conju;
		const double denom = (other * conju).re;

		return Complex(numer.re / denom, numer.im / denom);
	}

	Complex& Complex::operator=(const Complex& other)
	{
		re = other.re;
		im = other.im;

		return *this;
	}

	Complex& Complex::operator+=(const Complex& other)
	{
		*this = *this + other;

		return *this;
	}

	Complex& Complex::operator-=(const Complex& other)
	{
		*this = *this - other;

		return *this;
	}

	Complex& Complex::operator*=(const Complex& other)
	{
		*this = *this * other;

		return *this;
	}

	Complex& Complex::operator/=(const Complex& other)
	{
		*this = *this / other;

		return *this;
	}

	bool Complex::operator==(const Complex& other) const
	{
		return re == other.re && im == other.im;
	}

	bool Complex::operator!=(const Complex& other) const
	{
		return !(*this == other);
	}


	// +---------------+
	// | Polar methods |
	// +---------------+

	Polar::Polar()
	{
		len = 0.0;
		arg = 0.0;
	}

	Polar::Polar(Complex& com)
	{
		len = com.Len();
		arg = com.Arg();

		if (this->arg < 0.0)
			this->arg += TAU;
	}

	Polar::Polar(double len, double arg)
	{
		this->len = len;
		this->arg = arg;

		while (this->arg < 0.0)
		{
			this->arg += TAU;
		}
		while (this->arg >= TAU)
		{
			this->arg -= TAU;
		}
	}

	Complex Polar::ToComplex()
	{
		return Complex();
	}

	void Polar::Rotate(double angle)
	{
		arg += angle;

		while (arg < 0.0)
		{
			arg += TAU;
		}
		while (arg >= TAU)
		{
			arg -= TAU;
		}
	}

	Polar Polar::Conjugate()
	{
		return Polar(len, TAU - arg);
	}

	double Polar::Re()
	{
		return len * cos(arg);
	}

	double Polar::Im()
	{
		return len * sin(arg);
	}

	Polar Polar::operator+(const Polar& other) const
	{
		double re = len * cos(arg) + other.len * cos(other.arg);
		double im = len * sin(arg) + other.len * sin(other.arg);
		Complex com(re, im);

		return Polar(com);
	}

	Polar Polar::operator-(const Polar& other) const
	{
		double re = len * cos(arg) - other.len * cos(other.arg);
		double im = len * sin(arg) - other.len * sin(other.arg);
		Complex com(re, im);

		return Polar(com);
	}

	Polar Polar::operator*(const Polar& other) const
	{
		double newArg = arg + other.arg;
		if (newArg >= TAU)
			newArg -= TAU;

		return Polar(len * other.len, newArg);
	}

	Polar Polar::operator/(const Polar& other) const
	{
		const Polar conju(other.len, -other.arg);
		const Polar numer = *this * conju;
		const double denom = (other * conju).len;

		return Polar(numer.len / denom, numer.arg);
	}

	Polar& Polar::operator=(const Polar& other)
	{
		len = other.len;
		arg = other.arg;

		return *this;
	}

	Polar& Polar::operator+=(const Polar& other)
	{
		*this = *this + other;

		return *this;
	}

	Polar& Polar::operator-=(const Polar& other)
	{
		*this = *this - other;

		return *this;
	}

	Polar& Polar::operator*=(const Polar& other)
	{
		*this = *this * other;

		return *this;
	}

	Polar& Polar::operator/=(const Polar& other)
	{
		*this = *this / other;

		return *this;
	}

	bool Polar::operator==(const Polar& other) const
	{
		if (this == &other)
			return true;

		return len == other.len && arg == other.arg;
	}

	bool Polar::operator!=(const Polar& other) const
	{
		return !(*this == other);
	}


	// +--------------------+
	// | External operators |
	// +--------------------+

	std::ostream& operator<<(std::ostream& lhs, const Complex& rhs)
	{
		lhs << rhs.re << " + " << rhs.im << "i";

		return lhs;
	}

	std::istream& operator>>(std::istream& lhs, Complex& rhs)
	{
		// TODO: Finish >> operator.

		std::string input = "";
		lhs >> input;

		try
		{
			const size_t plusInd = input.find('+');
			const size_t iInd = input.find('i');
			if (plusInd == -1 || iInd == -1)
				throw "\nERROR: Input is not a valid complex number.";

			std::string reStr = input.substr(0, plusInd);
			std::string imStr = input.substr(plusInd + 1, -1);

			std::string temp = "";
			for (int i = 0; i < reStr.size(); i++)
			{
				if (reStr[i] != ' ')
				{
					temp += reStr[i];
				}
			}
			reStr = temp;

			double re = std::strtod(reStr.c_str(), nullptr);
			

			temp = "";
			for (int i = 0; i < imStr.size(); i++)
			{
				if (imStr[i] != ' ')
				{
					temp += imStr[i];
				}
			}
			imStr = temp;
		}
		catch (const std::exception e)
		{
			std::cout << "\nERROR: Failed to read complex number.\n" << e.what();
		}

		return lhs;
	}


	// +-----------+
	// | Functions |
	// +-----------+

	Polar ComplexToPolar(Complex& ref)
	{
		return Polar(ref);
	}

	Complex PolarToComplex(Polar& ref)
	{
		return Complex(ref);
	}
}