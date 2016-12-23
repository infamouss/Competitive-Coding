using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelperMethods
{
    class Program
    {
        static void Main(string[] args)
        {
            string myValue = mySuperSecretFormula("guys");
            Console.WriteLine(myValue);
            myValue = mySuperSecretFormula();
            Console.WriteLine(myValue);
            Console.ReadLine();
        }

        private static string mySuperSecretFormula()
        {
            //Some cool stuff
            return "Hello World!";
        }
        private static string mySuperSecretFormula(string name)
        {
            return string.Format("Hello {0}!", name);
        }


    }
}
