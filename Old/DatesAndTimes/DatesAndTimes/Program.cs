using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatesAndTimes
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime myValue = DateTime.Now;
            //Console.WriteLine(myValue.ToString());
            //Console.WriteLine(myValue.ToShortDateString());
            //Console.WriteLine(myValue.ToLongDateString());
            //Console.WriteLine(myValue.ToShortTimeString());
            //Console.WriteLine(myValue.ToLongTimeString());

            //Console.WriteLine(myValue.AddDays(50).ToLongDateString());

            //Console.WriteLine(myValue.AddDays(-50).ToLongDateString());
            //Console.WriteLine(myValue.Month.ToString());

            //DateTime myBirthday = new DateTime(1995, 10, 8);
            //Console.WriteLine(myBirthday.ToLongDateString());


            DateTime myBirthday = DateTime.Parse("10/8/1995");

            TimeSpan myAge = myValue.Subtract(myBirthday);
            Console.WriteLine(myAge.TotalDays);


            Console.ReadLine();

        }
    }
}
