using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Understanding_Arrays
{
    class Program
    {
        static void Main(string[] args)
        {
            //int[] numbers = new int[5];
            //numbers[0] = 7;
            //numbers[1] = 9;
            //numbers[2] = 78;
            //numbers[3] = 234;
            //numbers[4] = 67;

            //int[] numbers = { 7, 9, 78, 234, 67, 6847 };

            //Console.WriteLine(numbers[3].ToString());
            //Console.ReadLine();


            string zig = "You can get what you want out of life"
                + " if you help enough other people get what they want.";
            char[] character = zig.ToCharArray();
            Array.Reverse(character);
            foreach(char a in character)
            {
                Console.Write(a);
            }
            Console.WriteLine(character.Length);
            Console.ReadLine();
        }
    }
}
