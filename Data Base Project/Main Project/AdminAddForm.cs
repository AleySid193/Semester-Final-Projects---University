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
    public partial class AdminAddForm : Form
    {
        OracleConnection con;
        public AdminAddForm()
        {
            InitializeComponent();
        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            ProfileForm v1 = new ProfileForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "INSERT INTO admin VALUES(\'" +
            textBox3.Text.ToString() + "\',\'" + textBox2.Text.ToString() + "\',\'" + textBox10.Text.ToString() +
            "\'," + textBox1.Text.ToString() + ")";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Admin Added", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                textBox1.Text = textBox3.Text = textBox2.Text = textBox10.Text = "";
            }
            con.Close();
        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void AdminAddForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }
    }
}
