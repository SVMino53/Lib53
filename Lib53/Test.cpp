// Lib53 
// Created by Isak "Mino53" Forsberg, 2024-01-16
// V 0.1, 2024-02-06

// Source file used to run, test and debug library components.
// Current version was used to test additions and changes in the latest update.


#include "Test.h"

using namespace Lib53;


namespace Test
{
   /**
    * Function to add code to to test components.
    * 
    * @returns true: Successfully ran the test.
    * @returns false: Failed to run the test.
    */
   bool RunTest()
   {
      std::cout << "Running test:\n\n";

      try
      {
         int ival1 = 24;
         int ival2 = -10;
         float fval1 = 3.5f;
         float fval2 = -0.5f;
         double dval1 = 35.01;
         double dval2 = -0.04;

         Fraction fracn;
         Fraction fracd(PI);
         Fraction fracf(0.125f);
         Fraction fraci(123);
         Fraction fraca(-3, 5);

         std::cout << "\"Function.h\"\n\n";

         std::cout << "\tAbs(" << ival1 << ") = " << Abs(ival1) << '\n';
         std::cout << "\tAbs(" << ival2 << ") = " << Abs(ival2) << '\n';
         std::cout << "\tAbs(" << fval1 << ") = " << Abs(fval1) << '\n';
         std::cout << "\tAbs(" << fval2 << ") = " << Abs(fval2) << '\n';
         std::cout << "\tAbs(" << dval1 << ") = " << Abs(dval1) << '\n';
         std::cout << "\tAbs(" << dval2 << ") = " << Abs(dval2) << '\n';
         std::cout << "\tAbs(" << fracn << ") = " << Abs(fracn) << '\n';
         std::cout << "\tAbs(" << fracd << ") = " << Abs(fracd) << '\n';
         std::cout << "\tAbs(" << fracf << ") = " << Abs(fracf) << '\n';
         std::cout << "\tAbs(" << fraci << ") = " << Abs(fraci) << '\n';
         std::cout << "\tAbs(" << fraca << ") = " << Abs(fraca) << '\n';

         std::cout << '\n';

         std::cout << "\tSgn(" << ival1 << ") = " << Sgn(ival1) << '\n';
         std::cout << "\tSgn(" << ival2 << ") = " << Sgn(ival2) << '\n';
         std::cout << "\tSgn(" << fval1 << ") = " << Sgn(fval1) << '\n';
         std::cout << "\tSgn(" << fval2 << ") = " << Sgn(fval2) << '\n';
         std::cout << "\tSgn(" << dval1 << ") = " << Sgn(dval1) << '\n';
         std::cout << "\tSgn(" << dval2 << ") = " << Sgn(dval2) << '\n';
         std::cout << "\tSgn(" << fracn << ") = " << Sgn(fracn) << '\n';
         std::cout << "\tSgn(" << fracd << ") = " << Sgn(fracd) << '\n';
         std::cout << "\tSgn(" << fracf << ") = " << Sgn(fracf) << '\n';
         std::cout << "\tSgn(" << fraci << ") = " << Sgn(fraci) << '\n';
         std::cout << "\tSgn(" << fraca << ") = " << Sgn(fraca) << '\n';

         std::cout << '\n';

         std::cout << "\tMin(" << ival1 << ", " << ival2 << ") = "
                   << Min(ival1, ival2) << '\n';
         std::cout << "\tMin(" << ival1 << ", " << ival1 << ") = "
                   << Min(ival1, ival1) << '\n';
         std::cout << "\tMin(" << ival2 << ", " << ival2 << ") = "
                   << Min(ival2, ival2) << '\n';
         std::cout << "\tMin(" << fval1 << ", " << fval2 << ") = "
                   << Min(fval1, fval2) << '\n';
         std::cout << "\tMin(" << dval1 << ", " << dval2 << ") = "
                   << Min(dval1, dval2) << '\n';
         std::cout << "\tMin(" << fracn << ", " << fracd << ") = "
                   << Min(fracn, fracd) << '\n';
         std::cout << "\tMin(" << fracf << ", " << fraca << ") = "
                   << Min(fracf, fraca) << '\n';

         std::cout << '\n';

         std::cout << "\tMax(" << ival1 << ", " << ival2 << ") = "
                   << Max(ival1, ival2) << '\n';
         std::cout << "\tMax(" << ival1 << ", " << ival1 << ") = "
                   << Max(ival1, ival1) << '\n';
         std::cout << "\tMax(" << ival2 << ", " << ival2 << ") = "
                   << Max(ival2, ival2) << '\n';
         std::cout << "\tMax(" << fval1 << ", " << fval2 << ") = "
                   << Max(fval1, fval2) << '\n';
         std::cout << "\tMax(" << dval1 << ", " << dval2 << ") = "
                   << Max(dval1, dval2) << '\n';
         std::cout << "\tMax(" << fracn << ", " << fracd << ") = "
                   << Max(fracn, fracd) << '\n';
         std::cout << "\tMax(" << fracf << ", " << fraca << ") = "
                   << Max(fracf, fraca) << '\n';

         std::cout << '\n';

         std::cout << "\tRound<int>(" << fval1 << ") = "
                   << Round<int>(fval1) << '\n';
         std::cout << "\tRound<int>(" << fval2 << ") = "
                   << Round<int>(fval2) << '\n';
         std::cout << "\tRound<int>(" << dval1 << ") = "
                   << Round<int>(dval1) << '\n';
         std::cout << "\tRound<int>(" << dval2 << ") = "
                   << Round<int>(dval2) << '\n';
         std::cout << "\tRound<int>(" << fracn << ") = "
                   << Round<int>(fracn) << '\n';
         std::cout << "\tRound<int>(" << fracd << ") = "
                   << Round<int>(fracd) << '\n';
         std::cout << "\tRound<int>(" << fracf << ") = "
                   << Round<int>(fracf) << '\n';
         std::cout << "\tRound<int>(" << fraci << ") = "
                   << Round<int>(fraci) << '\n';
         std::cout << "\tRound<int>(" << fraca << ") = "
                   << Round<int>(fraca) << '\n';

         std::cout << '\n';

         std::cout << "\tFloor<int>(" << fval1 << ") = "
                   << Floor<int>(fval1) << '\n';
         std::cout << "\tFloor<int>(" << fval2 << ") = "
                   << Floor<int>(fval2) << '\n';
         std::cout << "\tFloor<int>(" << dval1 << ") = "
                   << Floor<int>(dval1) << '\n';
         std::cout << "\tFloor<int>(" << dval2 << ") = "
                   << Floor<int>(dval2) << '\n';
         std::cout << "\tFloor<int>(" << fracn << ") = "
                   << Floor<int>(fracn) << '\n';
         std::cout << "\tFloor<int>(" << fracd << ") = "
                   << Floor<int>(fracd) << '\n';
         std::cout << "\tFloor<int>(" << fracf << ") = "
                   << Floor<int>(fracf) << '\n';
         std::cout << "\tFloor<int>(" << fraci << ") = "
                   << Floor<int>(fraci) << '\n';
         std::cout << "\tFloor<int>(" << fraca << ") = "
                   << Floor<int>(fraca) << '\n';

         std::cout << '\n';

         std::cout << "\tCeil<int>(" << fval1 << ") = "
                   << Ceil<int>(fval1) << '\n';
         std::cout << "\tCeil<int>(" << fval2 << ") = "
                   << Ceil<int>(fval2) << '\n';
         std::cout << "\tCeil<int>(" << dval1 << ") = "
                   << Ceil<int>(dval1) << '\n';
         std::cout << "\tCeil<int>(" << dval2 << ") = "
                   << Ceil<int>(dval2) << '\n';
         std::cout << "\tCeil<int>(" << fracn << ") = "
                   << Ceil<int>(fracn) << '\n';
         std::cout << "\tCeil<int>(" << fracd << ") = "
                   << Ceil<int>(fracd) << '\n';
         std::cout << "\tCeil<int>(" << fracf << ") = "
                   << Ceil<int>(fracf) << '\n';
         std::cout << "\tCeil<int>(" << fraci << ") = "
                   << Ceil<int>(fraci) << '\n';
         std::cout << "\tCeil<int>(" << fraca << ") = "
                   << Ceil<int>(fraca) << '\n';

         std::cout << '\n';

         std::cout << "\tGCD(" << ival1 << ", " << ival2 << ") = "
                   << GCD(ival1, ival2) << '\n';
         std::cout << "\tGCD(" << ival1 << ", " << ival1 << ") = "
                   << GCD(ival1, ival1) << '\n';
         std::cout << "\tGCD(-1, 100) = " << GCD(-1, 100) << '\n';
         std::cout << "\tGCD(55, 33) = "  << GCD(55, 33)  << '\n';

         std::cout << '\n';

         std::cout << "\tLCM(" << ival1 << ", " << ival2 << ") = "
                   << LCM(ival1, ival2) << '\n';
         std::cout << "\tLCM(" << ival1 << ", " << ival1 << ") = "
                   << LCM(ival1, ival1) << '\n';
         std::cout << "\tLCM(-1, 100) = " << LCM(-1, 100) << '\n';
         std::cout << "\tLCM(55, 33) = "  << LCM(55, 33)  << '\n';

         std::cout << "\n\"Fraction.h\"\n\n";

         std::cout << '\t' << fracn << " numerator: " << fracn.num << '\n';
         std::cout << '\t' << fracn << " denominator: " << fracn.den << '\n';
         std::cout << '\t' << fracf << " numerator: " << fracf.num << '\n';
         std::cout << '\t' << fracf << " denominator: " << fracf.den << '\n';
         std::cout << '\t' << fraca << " numerator: " << fraca.num << '\n';
         std::cout << '\t' << fraca << " denominator: " << fraca.den << '\n';

         std::cout << '\n';

         std::cout << "\t+(" << fracn << ") = " << +fracn << '\n';
         std::cout << "\t+(" << fracf << ") = " << +fracf << '\n';
         std::cout << "\t+(" << fraca << ") = " << +fraca << '\n';
         std::cout << "\t-(" << fracn << ") = " << -fracn << '\n';
         std::cout << "\t-(" << fracf << ") = " << -fracf << '\n';
         std::cout << "\t-(" << fraca << ") = " << -fraca << '\n';

         std::cout << '\n';

         std::cout << '\t' << fracf << " + " << fraca << " = "
                   << fracf + fraca << '\n';
         std::cout << '\t' << fraca << " + " << fracf << " = "
                   << fraca + fracf << '\n';
         std::cout << '\t' << fracf << " + " << fracf << " = "
                   << fracf + fracf << '\n';
         std::cout << '\t' << fraca << " + " << fraca << " = "
                   << fraca + fraca << '\n';
         std::cout << '\t' << fracf << " - " << fraca << " = "
                   << fracf - fraca << '\n';
         std::cout << '\t' << fraca << " - " << fracf << " = "
                   << fraca - fracf << '\n';
         std::cout << '\t' << fracf << " - " << fracf << " = "
                   << fracf - fracf << '\n';
         std::cout << '\t' << fraca << " - " << fraca << " = "
                   << fraca - fraca << '\n';
         std::cout << '\t' << fracf << " * " << fraca << " = "
                   << fracf * fraca << '\n';
         std::cout << '\t' << fraca << " * " << fracf << " = "
                   << fraca * fracf << '\n';
         std::cout << '\t' << fracf << " * " << fracf << " = "
                   << fracf * fracf << '\n';
         std::cout << '\t' << fraca << " * " << fraca << " = "
                   << fraca * fraca << '\n';
         std::cout << '\t' << fracf << " / " << fraca << " = "
                   << fracf / fraca << '\n';
         std::cout << '\t' << fraca << " / " << fracf << " = "
                   << fraca / fracf << '\n';
         std::cout << '\t' << fracf << " / " << fracf << " = "
                   << fracf / fracf << '\n';
         std::cout << '\t' << fraca << " / " << fraca << " = "
                   << fraca / fraca << '\n';

         std::cout << '\n';

         Fraction fradF = 0.33333333333333_F;
         Fraction fraiF = -15_F / 25_F;

         std::cout << "\tfradF = " << fradF << '\n';
         std::cout << "\tfraiF = " << fraiF << '\n';

         std::cout << '\n';

         auto temp = fradF;
         std::cout << "\t> auto temp = fradF;\n";
         std::cout << "\ttemp = " << temp << '\n';
         fradF = fraiF;
         std::cout << "\n\t> fradF = fraiF;\n";
         std::cout << "\tfradF = " << fradF << '\n';
         fraiF += temp;
         std::cout << "\n\t> fraiF += temp;\n";
         std::cout << "\tfraiF = " << fraiF << '\n';
         fradF -= fraiF;
         std::cout << "\n\t> fradF -= fraiF;\n";
         std::cout << "\tfradF = " << fradF << '\n';
         fradF *= fraiF;
         std::cout << "\n\t> fradF *= fraiF;\n";
         std::cout << "\tfradF = " << fradF << '\n';
         fraiF /= fradF;
         std::cout << "\n\t> fraiF /= fradF;\n";
         std::cout << "\tfraiF = " << fraiF << '\n';

         std::cout << '\n';

         Fraction fra[5] = { 1_F/4_F, 1_F/4_F, 2_F/7_F, -1_F/5_F, -1_F/6_F };

         for (int i = 0; i < 5; i++)
         {
            std::cout << "\tfra[" << i << "] = " << fra[i] << '\n';
         }

         std::cout << '\n';

         std::cout << "\top (==):\n";
         std::cout << "\t\t|  lhs   |  rhs   | ret |\n";
         std::cout << "\t\t+--------+--------+-----+\n";
         for (int i = 0; i < 4; i++)
         {
            for (int j = i + 1; j < 5; j++)
            {
               std::cout << "\t\t| fra[" << i << "] | fra[" << j << "] |  "
                         << (fra[i] == fra[j]) << "  |\n";
            }
         }

         std::cout << '\n';

         std::cout << "\top (!=):\n";
         std::cout << "\t\t|  lhs   |  rhs   | ret |\n";
         std::cout << "\t\t+--------+--------+-----+\n";
         for (int i = 0; i < 4; i++)
         {
            for (int j = i + 1; j < 5; j++)
            {
               std::cout << "\t\t| fra[" << i << "] | fra[" << j << "] |  "
                         << (fra[i] != fra[j]) << "  |\n";
            }
         }

         std::cout << '\n';

         std::cout << "\top (<):\n";
         std::cout << "\t\t|  lhs   |  rhs   | ret |\n";
         std::cout << "\t\t+--------+--------+-----+\n";
         for (int i = 0; i < 4; i++)
         {
            for (int j = i + 1; j < 5; j++)
            {
               std::cout << "\t\t| fra[" << i << "] | fra[" << j << "] |  "
                         << (fra[i] < fra[j]) << "  |\n";
            }
         }

         std::cout << '\n';

         std::cout << "\top (>):\n";
         std::cout << "\t\t|  lhs   |  rhs   | ret |\n";
         std::cout << "\t\t+--------+--------+-----+\n";
         for (int i = 0; i < 4; i++)
         {
            for (int j = i + 1; j < 5; j++)
            {
               std::cout << "\t\t| fra[" << i << "] | fra[" << j << "] |  "
                         << (fra[i] > fra[j]) << "  |\n";
            }
         }

         std::cout << '\n';

         std::cout << "\top (<=):\n";
         std::cout << "\t\t|  lhs   |  rhs   | ret |\n";
         std::cout << "\t\t+--------+--------+-----+\n";
         for (int i = 0; i < 4; i++)
         {
            for (int j = i + 1; j < 5; j++)
            {
               std::cout << "\t\t| fra[" << i << "] | fra[" << j << "] |  "
                         << (fra[i] <= fra[j]) << "  |\n";
            }
         }

         std::cout << '\n';

         std::cout << "\top (>=):\n";
         std::cout << "\t\t|  lhs   |  rhs   | ret |\n";
         std::cout << "\t\t+--------+--------+-----+\n";
         for (int i = 0; i < 4; i++)
         {
            for (int j = i + 1; j < 5; j++)
            {
               std::cout << "\t\t| fra[" << i << "] | fra[" << j << "] |  "
                         << (fra[i] >= fra[j]) << "  |\n";
            }
         }

         std::cout << '\n';

         std::cout << "\tint(fra[2]) = " << int(fra[2]) << '\n';
         std::cout << "\tint(fra[3]) = " << int(fra[3]) << '\n';
         std::cout << "\tint(fra[4]) = " << int(fra[4]) << '\n';
         std::cout << "\tfloat(fra[2]) = " << float(fra[2]) << '\n';
         std::cout << "\tfloat(fra[3]) = " << float(fra[3]) << '\n';
         std::cout << "\tfloat(fra[4]) = " << float(fra[4]) << '\n';
         std::cout << "\tdouble(fra[2]) = " << double(fra[2]) << '\n';
         std::cout << "\tdouble(fra[3]) = " << double(fra[3]) << '\n';
         std::cout << "\tdouble(fra[4]) = " << double(fra[4]) << '\n';
      }
      catch (std::exception e)
      {
         std::cout << "\nERROR: Failed the test.\n" << e.what();
         return false;
      }

      std::cout << "\nTest finished successfully!\n\n";

      return true;
   }
}