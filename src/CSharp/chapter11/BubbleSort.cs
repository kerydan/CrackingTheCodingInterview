using System;
using System.Collections.Generic;

namespace ConsoleApplication
{
    class Program
    {
        static List<int> BubbleSort(List<int> A)
        {
            for (var k = A.Count-1; k >= 0; k--)
            {
                for (var i = 0; i < k; i++)
                {
                    if (A[i] > A[i + 1])
                    {
                        var tmp = A[i];
                        A[i] = A[i + 1];
                        A[i + 1] = tmp;
                    }
                }
            }
            return A;
        }

        static void Main(string[] args)
        {
            List<int> A = new List<int>{ 3, 4, 1, 2, 7, 9, 0 };
            A = new List<int> {4, 1};
            List<int> B = BubbleSort(A);

            int z = 9;

        }
    }
}
