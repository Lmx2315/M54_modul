/*
 * Created by SharpDevelop.
 * User: Lmx2315
 * Date: 09/10/2018
 * Time: 15:04
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Diagnostics;


namespace fft_writer
{
	/// <summary>
	/// Description of Class1.
	/// </summary>
	public class Class1
	{
		public int  BUF_N;
        public byte flag_start=0;
		public byte flag_packet_ok=0;
		static Int16 k=0;
		static uint odd;
		public int  [] Mas_data =new int[32000];
	    public uint [] Mas_data_I=new uint[32000];
        public uint [] Mas_data_Q = new uint[32000];
  		
		public Class1()//это конструктор
		{
		}
		
		public void rcv_control(byte [] a,int size_a)
		{
			 int i;
			 int j;
			 int l;
       		 uint v1;
			 uint v2;
             uint z;	

			for (i=6;i<size_a;i++)	
			{
				if (flag_packet_ok==0)
				{
					if (k<BUF_N+1)
					{
						if (odd==0) 
						{
							v2=a[i];
							v1=v2<<8;
							Mas_data_I[k]=v1;
						}
						else
                        if (odd == 1)
                        {
							Mas_data_I[k]=Mas_data_I[k]+a[i];
                        }
                        if (odd == 2)
                        {
                            v2 = a[i];
                            v1 = v2 << 8;
                            Mas_data_Q[k] = v1;
                        }
                        else
                        if (odd == 3)
                        {
                            Mas_data_Q[k] = Mas_data_Q[k] + a[i];
                        }

                        if (odd!=3) odd++; 
						else 
						{
							k++;
							odd=0;
						}
					} 

					//Debug.WriteLine("k:"+ k);
					//Debug.WriteLine("i:"+ i);

					if (k==(BUF_N+1)) //тут определяем что буфер собран и равен требуемому значению
					{
				           flag_packet_ok = 1;

                            for (l = 0; l < BUF_N; l++)
                            {

                                z = (uint)(Mas_data_I[l]);
                           // Mas_data[l] = Convert.ToInt32(1 * z);
                                z = (~z) & 0xffff;

                            if (((z >> 15) & 0x01) == 0x01)
                             {
                                 Mas_data[l] = Convert.ToInt32(1 * z) - 65535;
                             }
                             else Mas_data[l] = Convert.ToInt32(1 * z) ;

                           // Mas_data[l] = Mas_data[l] - 32767;

                         //  Debug.WriteLine("m:"+ Mas_data[l]);
                            }   

                        k = 0;
                        odd = 0;
                    }

				j=i;
				
				}
					
			}

			//Debug.WriteLine("k:"+ k);		
			
		}		
	}
}
