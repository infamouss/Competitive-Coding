using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GiveChange
{
    class Program
    {
        static void Main(string[] args)
        {
            int paid = int.Parse(Console.ReadLine());
            int price = int.Parse(Console.ReadLine());
            int diff = paid - price;
            //int c100,c50,c20,c10,c5,c2,c1;
            //c100=c50=c20=c10=c5=c2=c1=0;
            Console.Write("Your change:");
            while(diff>0)
            {
                if(diff>=100)
                {
                    diff -= 100;
                    //c100++;
                    Console.Write("{0} ", 100);
                }
                else if (diff >= 50)
                {
                    diff -= 50;
                    //c50++;
                    Console.Write("{0} ", 50);
                }
                else if(diff>=20)
                {
                    diff -= 20;
                    //c20++;
                    Console.Write("{0} ", 20);
                }
                else if(diff>=10)
                {
                    diff -= 10;
                    //c10++;
                    Console.Write("{0} ", 10);
                }
                else if(diff>=5)
                {
                    diff -= 5;
                    //c5++;
                    Console.Write("{0} ", 5);
                }
                else if(diff>=2)
                {
                    diff -= 2;
                    //c2++;
                    Console.Write("{0} ", 2);
                }
                else
                {
                    diff--;
                    //c1++;
                    Console.Write("{0} ", 1);
                }
            }
            //Console.Write("Your change:");
            //for(int i=0;i<c100;i++)
            //    Console.Write("{0} ",100);
            //for (int i = 0; i < c50; i++)
            //    Console.Write("{0} ", 50);
            //for (int i = 0; i < c20; i++)
            //    Console.Write("{0} ", 20);
            //for (int i = 0; i < c10; i++)
            //    Console.Write("{0} ", 10);
            //for (int i = 0; i < c5; i++)
            //    Console.Write("{0} ", 5);
            //for (int i = 0; i < c2; i++)
            //    Console.Write("{0} ", 2);
            //for (int i = 0; i < c1; i++)
            //    Console.Write("{0} ", 1);
        }
    }
}
