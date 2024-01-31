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
    public partial class ProductUpdate : Form
    {
        string pid;
        OracleConnection con;
        public ProductUpdate(string str)
        {
            pid = str;
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //try
            //{
            if (textBox6.Text.ToString() == "" && textBox8.Text.ToString() == "" && textBox7.Text.ToString() == "" && textBox9.Text.ToString() == "")
            {
                MessageBox.Show("Please Fill The Text Boxes!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                con.Open();
                OracleCommand insertEmp = con.CreateCommand();
                insertEmp.CommandText = "UPDATE product SET category_name = \'" +
                    textBox9.Text.ToString() + "\', v_price = " + textBox7.Text.ToString() + ", sales_price = " + textBox8.Text.ToString() +
                    ", quantity = " + textBox6.Text.ToString() + ", v_id = " + textBox10.Text.ToString() + " WHERE p_id = " + pid;
                insertEmp.CommandType = CommandType.Text;
                int rows = insertEmp.ExecuteNonQuery();
                if (rows > 0)
                {
                    MessageBox.Show("Product Updated", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    textBox10.Text = textBox7.Text = textBox9.Text = textBox8.Text = textBox6.Text = "";
                }
                else
                {
                    MessageBox.Show("Product Not Found", "Invalid Product ID", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                con.Close();
            }
            //}
            //catch (Exception ex)
            //{
            //    // Handle the exception
            //    MessageBox.Show("An error occurred: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            //}
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ProductForm p1 = new ProductForm();
            this.Hide();
            p1.ShowDialog();
        }

        private void ProductUpdate_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
