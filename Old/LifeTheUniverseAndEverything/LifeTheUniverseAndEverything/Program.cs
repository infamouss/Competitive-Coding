using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CC_Life__the_Universe__and_Everything
{
    class Program
    {
        static void Main(string[] args)
        {
            int num;
            num = int.Parse(Console.ReadLine());
            while(num!=42)
            {
                Console.WriteLine(num.ToString());
                num = int.Parse(Console.ReadLine());
            }
        }
    }
}
