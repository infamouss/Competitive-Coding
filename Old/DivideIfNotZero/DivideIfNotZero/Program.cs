using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DivideIfNotZero
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            if(b != 0)
            {
                Console.WriteLine(a / b);
            }
            else
            {
                Console.WriteLine("I cannot divide!!!");
            }
        }
    }
}
