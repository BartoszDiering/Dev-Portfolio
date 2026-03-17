
using System;
using System.Collections;
using System.Security.Claims;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
         double stan = 0;
         int decyzja;
         string PIN = "1234";
         string KOD = "";
         double kwota;

        while(KOD !=PIN){
            Console.WriteLine("Wpisz Pin.");
            KOD=Console.ReadLine();
             if (string.IsNullOrEmpty(KOD))
            {
                Console.WriteLine("Musisz cos wpisac");
            }
            else if (KOD !=PIN)
            {
                Console.WriteLine("Zly PIN");
            }
        }
            while (true)
            {
                Console.WriteLine($"Twoja kwota to {stan}");
                Console.WriteLine("1.Wplata 2.Wyplata 3.Stan konta 4. Wyjscie");
                decyzja = int.Parse(Console.ReadLine());
                switch (decyzja)
                {
                    case 1:
                    Console.WriteLine("Ile chcesz wplacic?");
                    kwota = double.Parse(Console.ReadLine());
                    stan=stan+kwota;
                    break;

                    case 2:
                    Console.WriteLine("Ile chcesz wyplacic?");
                    kwota = double.Parse(Console.ReadLine());
                    if(kwota<=stan){
                    stan=stan-kwota;
                    }
                    else{
                    Console.WriteLine("Brak srodkow na koncie");
                    }
                    break;

                    case 3:
                    Console.WriteLine("");
                    Console.WriteLine($"Twoj stan konta to {stan}");
                    break;

                    case 4:
                    return;

                    default:
                    Console.WriteLine("Wpisz numer ktory ma przydzielony ");
                    break;
                }
                
            }
         

        }
    }
}