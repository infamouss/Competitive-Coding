using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HollowSquare
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            int side = int.Parse(Console.ReadLine());
            for(int i=1,j=0; i<=side; i++)
            {
                if(i==1||i==side)
                {
                    for (j = 0; j < side; j++)
                        Console.Write(num);
                    Console.Write("\n");
                }
                else
                {
                    Console.Write(num);
                    for (j = 2; j < side; j++)
                        Console.Write(" ");
                    Console.Write(num);
                    Console.Write("\n");
                }
            }
        }
    }
}
