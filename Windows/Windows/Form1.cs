using System;
using System.Windows.Forms;
using System.IO.Ports;

namespace Ardeno
{
    public partial class Form1 : Form
    {
        public Form1() {
            InitializeComponent();
            this.ControlBox = false;
            AppDomain.CurrentDomain.ProcessExit += new EventHandler(OnProcessExit);
        }
        public SerialPort myport;

        private void Form1_Load(object sender, EventArgs e)
        {
            myport = new SerialPort();
            myport.BaudRate = 9600;
            myport.PortName = "COM4";
            myport.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
            myport.Open();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var day = (int)DateTime.Now.DayOfWeek;
            var dayStr = "D: " + day;

            myport.WriteLine(dayStr);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            myport.WriteLine("S!!");
        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadExisting();
            Console.WriteLine(indata);
        }

        void OnProcessExit(object sender, EventArgs e)
        {
            myport.WriteLine("S!!");
        }
    }
}