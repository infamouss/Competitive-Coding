using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Decisions
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Please type something and press the enter key.");
            //string userValue;
            //userValue = Console.ReadLine();
            //Console.WriteLine("You typed: " + userValue);
            //Console.WriteLine(userValue + ": You typed");
            Console.WriteLine("Would you like to prefer what is behind door number 1, 2 or 3?");
            string userValue = Console.ReadLine();
            //string message = "";
            //if (userValue == "1")
            //    message = "You won a new car!";
            //else if (userValue == "2")
            //    message = "You won a new boat!";
            //else if (userValue == "3")
            //    message = "You won new cat!";
            //else
            //    message = "Sorry! We didn't understand. You lose!";
            //Console.WriteLine(message);

            string message = (userValue == "1") ? "boat" : "strand of lint";
            Console.WriteLine("You won  {0}  {1}", message, userValue);



            Console.ReadLine();
        }
    }
}
