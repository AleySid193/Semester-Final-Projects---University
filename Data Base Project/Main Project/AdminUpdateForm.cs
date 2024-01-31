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
    public partial class AdminUpdateForm : Form
    {
        OracleConnection con;
        public AdminUpdateForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "UPDATE admin SET password = \'" +
            textBox2.Text.ToString() + "\',phone_no = " + textBox1.Text.ToString() + ",name = \'" + textBox10.Text.ToString() +
            "\' where username = \' " + textBox3.Text.ToString() + "\'";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Admin Added", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                textBox1.Text = textBox3.Text = textBox2.Text = textBox10.Text = "";
            }
            else
            {
                MessageBox.Show("Username Doesn't Exists.", "Failed", MessageBoxButtons.OK, MessageBoxIcon.Information);
                textBox1.Text = textBox3.Text = textBox2.Text = textBox10.Text = "";
            }
            con.Close();
        }

        private void AdminUpdateForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            MainPageForm m1 = new MainPageForm();
            this.Hide();
            m1.ShowDialog();
        }
    }
}
