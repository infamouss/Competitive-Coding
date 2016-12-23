using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiplyIfNotZero
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            if(a!=0)
            {
                int b = int.Parse(Console.ReadLine());
                Console.WriteLine(a * b);
            }
            else
            {
                Console.WriteLine("0");
            }
        }
    }
}
