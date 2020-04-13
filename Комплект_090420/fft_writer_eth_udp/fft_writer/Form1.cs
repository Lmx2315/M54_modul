/*
 * Created by SharpDevelop.
 * User: Lmx2315
 * Date: 09/10/2018
 * Time: 14:36
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Drawing;
using System.Windows.Forms;
using System.Linq;
using System.Numerics;
using System.Diagnostics;

namespace fft_writer
{
	/// <summary>
	/// Description of Form1.
	/// </summary>
	public partial class Form1 : Form
	{
		public Form1()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		static Int16  BUF_N=2048;
		public int   [] FFT_array=new int [8192];
		public byte flag_new_fft=0;
		Bitmap image1 = new Bitmap(635,560);
		
		void Form1Load(object sender, EventArgs e)
		{
			int x, y;
			
			
			Pen pen = new Pen(Color.Black, 3);
			
			for(y=0; y<image1.Height; y++)
            {
                 image1.SetPixel(0, y, Color.FromArgb(0, 0, 255));
            }
			 for(x=0; x<image1.Width; x++)
            {
                
                image1.SetPixel(x,0,Color.FromArgb(0, 0, 255));
            }
			
			for(y=0; y<image1.Height; y++)
            {
                 image1.SetPixel(image1.Width-1, y, Color.FromArgb(0, 0, 0));
            }
			 for(x=0; x<image1.Width; x++)
            {
                
                image1.SetPixel(x,image1.Height-1,Color.FromArgb(0, 0, 0));
            } 
			 
			for(y=0; y<image1.Height; y++)
            {
                 image1.SetPixel(image1.Width/2, y, Color.FromArgb(0, 0, 0));
            }
		    for(x=0; x<image1.Width; x++)
            {
                
			image1.SetPixel(x,image1.Height/2,Color.FromArgb(0, 0, 0)); }
		    
		    Graphics gr= Graphics.FromImage (image1);
		    
		    // Create array of points that define lines to draw.
    		Point[] points =
             {
                 new Point(1,550),
                 new Point(634,550),
               //  new Point(200,  50),
               //  new Point(250, 300)
             };

    		//Draw lines to screen.
    		gr.DrawLines(pen, points);			
						
			pictureBox1.Image=	image1;	
		}
		void Btn_fft_timeClick(object sender, EventArgs e)
		{
			if (btn_fft_time.Text=="FFT") btn_fft_time.Text="time"; else btn_fft_time.Text="FFT";
		}
		void Timer1Tick(object sender, EventArgs e)
		{
			int i=0;
			int x_max=0;
			int y_max=0;
		//	int signed_var1;
			double kj=0;
			double  a,b;
			UInt32 length = 1024;
			double samplingRate = 1000;

			double   [] FFT_double=new double [length];
			
			int   [] FFT_norm=new int [8192];

			if (flag_new_fft==1)
			{
				flag_new_fft=0;
				//отрабатываем вывод данных.
				
				//---------FFT--------------------
				// Instantiate a new DFT
	            DSPLib.DFT dft = new DSPLib.DFT();

	            // Initialize the DFT
	            // You only need to do this once or if you change any of the DFT parameters.
	            dft.Initialize(length);
				//--------------------------------
				
				Graphics gr= Graphics.FromImage (image1);
			    Pen pen = new Pen(Color.Black, 3);
			    // Create array of points that define lines to draw.
	    		Point[] points = new Point[1024];
	             
	    		y_max=pictureBox1.Size.Height-10;
	    		x_max=pictureBox1.Size.Width;
				
	   
	    		int maxValue = FFT_array.Max();
	    		    		
	    		//Debug.WriteLine("maxValue:"+ maxValue);
	    		//Debug.WriteLine("y_max   :"+ y_max);
	    		//Debug.WriteLine("x_max   :"+ x_max);
	    		
	    		a=maxValue;
	    		b=y_max;
	    		kj=a/b;
	    		
	    		Debug.WriteLine("kj:"+ kj);

	    		for (i=0;i<1024;i++) 
				{
	    			FFT_double[i]=Convert.ToDouble(FFT_array[i]);
				}

	    			 // Call the DFT and get the scaled spectrum back
	            Complex[] cSpectrum = dft.Execute(FFT_double);

	            // Convert the complex spectrum to magnitude
	            double[] lmSpectrum = DSPLib.DSP.ConvertComplex.ToMagnitude(cSpectrum);

	            // Note: At this point lmSpectrum is a 501 byte array that 
	            // contains a properly scaled Spectrum from 0 - 50,000 Hz

	            // For plotting on an XY Scatter plot generate the X Axis frequency Span
	            double[] freqSpan = dft.FrequencySpan(samplingRate);

	            // At this point a XY Scatter plot can be generated from,
	            // X axis => freqSpan
	            // Y axis => lmSpectrum
	    		
	    		for (i=0;i<512;i++) 
				{
					a=freqSpan[i];
					b=a/(kj*2);
					FFT_norm[i]=Convert.ToInt16(b);
	    		//	Debug.WriteLine("freqSpan[i]:"+ freqSpan[i]);
	    		//	Debug.WriteLine("FFT_norm [i]:"+ FFT_norm[i]);
				}
	    		
	    		

	
	    		for (i=0;i<1024;i++) 
				{
					points[i].X=i;
					points[i].Y=FFT_norm[i]+y_max/2;
				}
	    		
	    		gr.Clear(Color.White);
	
	    		//Draw lines to screen.
	    		gr.DrawLines(pen, points);
	    		pictureBox1.Image=	image1;	
				
			}
		}
		
		
		
		
		
		
	}
}
