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
    public partial class ProductSearchForm : Form
    {
        OracleConnection con;
        public ProductSearchForm()
        {
            InitializeComponent();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (textBox8.Text.ToString() == "")
            {
                MessageBox.Show("Please Fill The Text Box!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                con.Open();
                OracleCommand getEmps = con.CreateCommand();
                getEmps.CommandText = "SELECT * FROM product where p_id = " + textBox8.Text.ToString();
                getEmps.CommandType = CommandType.Text;
                OracleDataReader empdr = getEmps.ExecuteReader();
                DataTable empdt = new DataTable();
                empdt.Load(empdr);
                dataGridView1.DataSource = empdt;
                con.Close();
                textBox8.Text = "";
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void SearchProductForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            ProductForm v1 = new ProductForm();
            this.Hide();
            v1.ShowDialog();
        }
    }
}
