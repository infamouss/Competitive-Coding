using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strings
{
    class Program
    {
        static void Main(string[] args)
        {
            //string myString="Go to your c:\\ drive";
            //string myString="My \"so called\" life";
            //string myString = "What if I need \n a new line?";
            //string myString = string.Format("{0}!", "Bonzai");
            //string myString = string.Format("Make: {0} (Model: {1})", "BMW", "760li");
            //string myString = string.Format("{0:C}", 464.64);
            //string myString = string.Format("{0:N}", 654646636664);


            //string myString = string.Format("{0:p}", 0.68545);
            //string myString = string.Format("Phone Number {0:(###)-###-####}", 1234567890);


            //string myString = "";
            //for (int i = 0; i < 100; i++)
            //{
            //    myString = myString + "--" + i.ToString();
            //}




            //StringBuilder myString = new StringBuilder();

            //for (int i = 0; i < 100; i++)
            //{
            //    myString.Append("--");
            //    myString.Append(i);
            //}




            string myString = "          That summer we took the threes across the board             ";

            //myString = myString.Substring(4,15);
            //myString = myString.ToUpper();


            //myString = myString.Replace(" ","--");

            myString = string.Format("Length Before:{0} -- Length After:{1}",
                myString.Length,
                myString.Trim().Length);



            Console.WriteLine(myString);
            Console.ReadLine();
        }
    }
}
