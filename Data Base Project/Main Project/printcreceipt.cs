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
    public partial class printcreceipt : Form
    {
        OracleConnection con;
        string sname, rid, cid;
        public printcreceipt(string sname1,string rid1,string cid1)
        {
            sname = sname1;
            rid = rid1;
            cid = cid1;
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {
            //label1.Text = "ok";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label1.Text = sname;
            label4.Text = rid;
            label9.Text = cid;
            con.Open();
            OracleCommand getEmps = con.CreateCommand();
            getEmps.CommandText = "SELECT * FROM print_receipt where reciept_id = " + rid;
            getEmps.CommandType = CommandType.Text;
            OracleDataReader empdr = getEmps.ExecuteReader();
            DataTable empdt = new DataTable();
            empdt.Load(empdr);
            dataGridView1.DataSource = empdt;
            con.Close();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void printcreceipt_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID = ali; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Done!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            RecieptForm f1 = new RecieptForm();
            this.Hide();
            f1.ShowDialog();
        }      
    }
}
