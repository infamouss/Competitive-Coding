using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleClasses
{
    class Program
    {
        static void Main(string[] args)
        {

            Car myNewCar = new Car();
            myNewCar.Make = "Oldsmobile";
            myNewCar.Model = "Cutlas Supreme";
            myNewCar.Year = 2002;
            myNewCar.Color = "Silver";

            Console.WriteLine("{0}-{1}-{2}",
                myNewCar.Make,
                myNewCar.Model,
                myNewCar.Year);

            double marketValueOfCar = determineMarketValue(myNewCar);
            Console.WriteLine(marketValueOfCar.ToString());
            Console.WriteLine("Car's value is {0:C}", myNewCar.determineMarketValue());

            Console.ReadLine();

        }


        private static double determineMarketValue(Car car)
        {
            double carValue = 100.5;

            //Someday will write the code!
            //

            return carValue;
        }

    }


    class Car
    {
        public string Make { get; set; }
        public string Model { get; set; }
        public int Year { get; set; }
        public string Color { get; set; }

        public double determineMarketValue()
        {
            double carValue;

            if (this.Year >= 1999)
                carValue = 10000;
            else
                carValue = 2000;

            return carValue;
        }


       
    }



}
