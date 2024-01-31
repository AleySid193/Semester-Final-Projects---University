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
    public partial class VendorViewForm : Form
    {
        OracleConnection con;
        public VendorViewForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand getEmps = con.CreateCommand();
            getEmps.CommandText = "SELECT * FROM vendor";
            getEmps.CommandType = CommandType.Text;
            OracleDataReader empdr = getEmps.ExecuteReader();
            DataTable empdt = new DataTable();
            empdt.Load(empdr);
            dataGridView1.DataSource = empdt;
            con.Close();
        }

        private void VendorViewForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            VendorForm obj = new VendorForm();
            this.Hide();
            obj.ShowDialog();
        }
    }
}
