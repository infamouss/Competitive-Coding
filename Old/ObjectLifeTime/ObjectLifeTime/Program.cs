using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObjectLifeTime
{
    class Program
    {
        static void Main(string[] args)
        {
            Car myCar = new Car();


            Car myOtherCar = myCar;

            myCar = null;
            myOtherCar = null;

            Car myThirdCar = new Car("Ford", "Escape", 2005, "White");


        }
    }

    class Car
    {
        public string Make { get; set; }
        public string Model { get; set; }
        public int Year { get; set; }
        public string Color { get; set; }
        public double OriginalPrice { get; set; }


        public Car()
        {
            this.Make = "Nissan";
        }


        public Car(string make, string model, int year, string color)
        {
            Make = make;
            Model = model;
            Year = year;
            Color = color;
        }

        //public Car(string someOtherInputParameter, string model, int year, string color)
        //{
        //    Make = someOtherInputParameter;
        //    Model = model;
        //    Year = year;
        //    Color = color;
        //}


    }
}
