#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_1recursive/Lab_07_1recursive.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest712
{
    TEST_CLASS(UnitTest712)
    {
    public:
        TEST_METHOD(TestCalcRecursive)
        {
            const int rows = 3;
            const int cols = 3;
            int** a = new int* [rows];
            for (int i = 0; i < rows; i++)
                a[i] = new int[cols];

            a[0][0] = 4;  a[0][1] = 6;  a[0][2] = 5;
            a[1][0] = 8;  a[1][1] = 2;  a[1][2] = 12;
            a[2][0] = 7;  a[2][1] = 14; a[2][2] = 10;

            int S = 0, k = 0;
            Calc(a, rows, cols, 0, 0, S, k);

            Assert::AreEqual(14, S);
            Assert::AreEqual(2, k);
            Assert::AreEqual(0, a[0][0]);
            Assert::AreEqual(0, a[2][2]);

            for (int i = 0; i < rows; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}