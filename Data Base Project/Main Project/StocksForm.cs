using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Oracle.ManagedDataAccess.Client;

namespace DB_FINAL_PROJECT_2
{
    public partial class StocksForm : Form
    {
        OracleConnection con;
        public StocksForm()
        {
            InitializeComponent();
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void StocksForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID = ali; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand getEmps = con.CreateCommand();
            getEmps.CommandText = "SELECT sum(total) As sales FROM sales_reciept";
            getEmps.CommandType = CommandType.Text;
            OracleDataReader empdr = getEmps.ExecuteReader();
            DataTable empdt = new DataTable();
            empdt.Load(empdr);
            dataGridView1.DataSource = empdt;
            OracleCommand getexp = con.CreateCommand();
            getexp.CommandText = "select sum(v_price*quantity) as expense from product";
            getexp.CommandType = CommandType.Text;
            OracleDataReader empdra = getexp.ExecuteReader();
            DataTable empdta = new DataTable();
            empdta.Load(empdra);
            dataGridView2.DataSource = empdta;
            con.Close();
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
