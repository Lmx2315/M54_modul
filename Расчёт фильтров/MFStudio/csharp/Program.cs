using System;

namespace csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int i=0,k=0,n=0;
            int N_k = 32;
            int index = 0;
            bool error = false;
            string text="";
            string sub="";
            string kfc  = "";
            string kfc1 = "";
            string kfc2 = "";
            Console.WriteLine("---------");
    //      Console.WriteLine(args[1]);

             try
            {
                if (args.Length != 0)
                {
                    foreach (string s in args)
                        Console.WriteLine(s);
                    text = System.IO.File.ReadAllText(args[1]);
                }
                else text = System.IO.File.ReadAllText("fdacoefs.h");
            }
            catch
            {
                Console.WriteLine("нет файла!");
                error = true;
            }
            
            if (error==false)
            {
                //       Console.WriteLine(text);

                foreach (char x in text) //ищем скобку
                {
                    if (x == '{') break;
                    i++;
                }

                while (i < text.Length)
                {
                    if (text.Substring(i, 1) == " ") k = i + 1;
                    if (text.Substring(i, 1) == ",")
                    {
                        n++;//подсчёт числа коэффициентов
                        if (n < N_k) sub = sub + text.Substring(k, (i - k)) + "\n";
                        else sub = sub + text.Substring(k, (i - k)) + "\n";

                        index = n - 1;
                        kfc1 = kfc1 + "dsp->RX1_CF_DFIR1[" + Convert.ToString(2*index) + "] =" + text.Substring(k, (i - k)) + ";" + "\n";
                        kfc1 = kfc1 + "dsp->RX1_CF_DFIR1[" + Convert.ToString(2*index+1) + "] =" + "0" + ";" + "\n";

                        kfc2 = kfc2 + "dsp->RX1_CF_DFIR2[" + Convert.ToString(2 * index) + "] =" + text.Substring(k, (i - k)) + ";" + "\n";
                        kfc2 = kfc2 + "dsp->RX1_CF_DFIR2[" + Convert.ToString(2 * index + 1) + "] =" + "0" + ";" + "\n";

                        //    Console.WriteLine(sub);
                    }
                    if (n == N_k) break;
                    i++;
                }

                kfc = kfc1 + "\n\n\n\n\n" + kfc2;

                Console.Write(sub);

                System.IO.File.WriteAllText("f_3.dat", sub);
                System.IO.File.WriteAllText("koeff.text", kfc);
            }
        }
    }
}
