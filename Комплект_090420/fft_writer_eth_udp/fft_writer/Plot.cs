using System;
using System.Windows.Forms;
using System.Drawing;
using DSPLib;

/*
* Released under the MIT License
*
* Plot - A very simple wrapper class for the .NET Chart Control
* 
* Copyright(c) 2016 Steven C. Hageman.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/
namespace PlotWrapper
{
    public partial class Plot : Form
    {
        private string mTitle;
        private string mAxisX;
        private string mAxisY;
        private string mDB0;
        private string mDB1;
        private string mDB2;
        private string mdelta1_DB;
        private string mdelta2_DB;
        private double mMax;     

        public Plot(double max,string mainTitle, string xAxisTitle, string yAxisTitle,string DB0,string DB1,string DB2, string delta1_DB, string delta2_DB)
        {
            InitializeComponent();

            mTitle = mainTitle;
            mAxisX = xAxisTitle;
            mAxisY = yAxisTitle;

            mDB0 = DB0;
            mDB1 = DB1;
            mDB2 = DB2;
            mdelta1_DB = delta1_DB;
            mdelta2_DB = delta2_DB;
            mMax = max;
        }

        private void Plot_Load(object sender, EventArgs e)
        {
            
            // Add the titles
            chart1.Titles["Title"].Text = mTitle;
            this.Text = mTitle;
            chart1.Titles["AxisX"].Text = mAxisX; 
            chart1.Titles["AxisY"].Text = mAxisY;
            chart1.ChartAreas["ChartArea1"].AxisX.Minimum = -3125;
            chart1.ChartAreas["ChartArea1"].AxisX.Maximum =  3125;
            chart1.ChartAreas["ChartArea1"].AxisY.Maximum = mMax;

            chart1.Titles["DB0"].Text = mDB0;
            chart1.Titles["DB1"].Text = mDB1;
            chart1.Titles["DB2"].Text = mDB2;
            chart1.Titles["delta1_DB"].Text = mdelta1_DB;
            chart1.Titles["delta2_DB"].Text = mdelta2_DB;

            // Enable zooming
            chart1.ChartAreas[0].CursorX.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].CursorY.IsUserSelectionEnabled = true;

         
        }

        // Line chart
        public void PlotData(double[] yData)
        {
            chart1.Series["Series1"].Points.Clear();

            // Start X Data at zero! Not like the chart default of 1!
            double[] xData = DSP.Generate.LinSpace(0, yData.Length-1, (UInt32)yData.Length);
            chart1.Series["Series1"].Points.DataBindXY(xData, yData);
        }
		
		 // Y Line Chart (Overload)
        public void PlotData(double[] yData,double DB0, double DB1, double DB2)
        {
            string sDB0;
            string sDB1;
            string sDB2;
            double delta1 = 0;
            double delta2 = 0;

            chart1.Series["Series1"].Points.Clear();
            chart1.Series["Series1"].Points.DataBindY(yData);
      
            sDB0 = Convert.ToString("DB0:") + Convert.ToString(Math.Round(DB0 * 10) / 10);
            sDB1 = Convert.ToString("DB1:") + Convert.ToString(Math.Round(DB1 * 10) / 10);
            sDB2 = Convert.ToString("DB2:") + Convert.ToString(Math.Round(DB2 * 10) / 10);

            delta1 = DB0 - DB1;
            delta2 = DB0 - DB2;

            chart1.Titles["DB0"].Text = sDB0;
            chart1.Titles["DB1"].Text = sDB1;
            chart1.Titles["delta1_DB"].Text = Convert.ToString("M0-M1:") + Convert.ToString(Math.Round(delta1));
            chart1.Titles["delta2_DB"].Text = Convert.ToString("M0-M2:") + Convert.ToString(Math.Round(delta2));

         //   chart1.Titles["delta2_DB"].Text = sDB2;

        }

        // XY Line Chart (Overload)
        public void PlotData(double[] xData, double[] yData,double DB0, double DB1, double DB2,double x1,double y1,double x2,double y2,double x3,double y3 )
        {
            string sDB0;
            string sDB1;
            string sDB2;
            double delta1 = 0;
            double delta2 = 0;                  

            chart1.Series["Series1"].Points.Clear();
            chart1.Series["Series1"].Points.DataBindXY(xData, yData);

            chart1.Series["Series2"].Points.Clear();
            chart1.Series["Series2"].Points.AddXY(x1,y1);
       
            chart1.Series["Series3"].Points.Clear();
            chart1.Series["Series3"].Points.AddXY(x2,y2);

            chart1.Series["Series4"].Points.Clear();
            chart1.Series["Series4"].Points.AddXY(x3,y3);
       
            sDB0 = Convert.ToString("M0:") + Convert.ToString(Math.Round(DB0 * 10) / 10);
            sDB1 = Convert.ToString("M1:") + Convert.ToString(Math.Round(DB1 * 10) / 10);
            sDB2 = Convert.ToString("M2:") + Convert.ToString(Math.Round(DB2 * 10) / 10);

            delta1 = DB0 - DB1;//считаем дельты
            delta2 = DB0 - DB2;

            chart1.Titles["DB0"].Text = sDB0;//отображаем на чарте
            chart1.Titles["DB1"].Text = sDB1;
            chart1.Titles["DB2"].Text = sDB2;

            chart1.Titles["delta1_DB"].Text = Convert.ToString("M0-M1:") + Convert.ToString(Math.Round(delta1));
            chart1.Titles["delta2_DB"].Text = Convert.ToString("M0-M2:") + Convert.ToString(Math.Round(delta2));

         //   chart1.Titles["delta2_DB"].Text = sDB2;

        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
    }


}
