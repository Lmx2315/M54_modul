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
    public partial class Plot2 : Form
    {
        private string mTitle;
        private string mAxisX;
        private string mAxisY;
        private double mMax;
       
        public Plot2(double max,string mainTitle, string xAxisTitle, string yAxisTitle)
        {
            InitializeComponent();

            mTitle = mainTitle;
            mAxisX = xAxisTitle;
            mAxisY = yAxisTitle;            
            mMax = max;
        }

        private void Plot_Load(object sender, EventArgs e)
        {
            
            // Add the titles
            chart1.Titles["Title"].Text = mTitle;
            this.Text = mTitle;
            chart1.Titles["AxisX"].Text = mAxisX; 
            chart1.Titles["AxisY"].Text = mAxisY;
          //  chart1.ChartAreas["ChartArea1"].AxisY.Maximum = mMax;
            
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
		
	        // XY Line Chart (Overload)
        public void PlotData(double[] xData, double[] yData)
        {
            chart1.Series["Series1"].Points.Clear();
            chart1.Series["Series1"].Points.DataBindXY(xData, yData);
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

    }


}
