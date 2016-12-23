using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GreatestOfThree
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int c = int.Parse(Console.ReadLine());
            if(a>=b)
            {
                if(a>=c)
                {
                    Console.WriteLine("Biggest is a {0}", a);
                }
                else
                {
                    Console.WriteLine("Biggest is c {0}", c);
                }
            }
            else
            {
                if(b>=c)
                {
                    Console.WriteLine("Biggest is b {0}", b);
                }
                else
                {
                    Console.WriteLine("Biggest is c {0}", c);
                }
            }
        }
    }
}
