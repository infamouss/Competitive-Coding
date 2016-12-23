using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SumNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            int sum = 0;
            sum = num;
            while(Convert.ToBoolean(num))
            {
                Console.WriteLine(sum.ToString());
                num = int.Parse(Console.ReadLine());
                sum += num;
            }
            Console.WriteLine("Finished");    
        }
    }
}
