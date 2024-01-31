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
    public partial class RecieptForm : Form
    {
        OracleConnection con;
        public RecieptForm()
        {
            InitializeComponent();
        }

        private void Reciept_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID = ali; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Successful");
        }

        private void button1_Click(object sender, EventArgs e)
        {

            printcreceipt c1 = new printcreceipt(textBox13.Text.ToString(), textBox12.Text.ToString(), textBox2.Text.ToString());
            this.Hide();
            c1.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            con.Open();
            int sales;
            using (OracleCommand countCommand = con.CreateCommand())
            {
                countCommand.CommandText = "SELECT p.sales_price FROM product p where p_id = " + textBox1.Text.ToString();
                countCommand.CommandType = CommandType.Text;
                sales = Convert.ToInt32(countCommand.ExecuteScalar());
            }
            sales = sales * int.Parse(textBox5.Text.ToString());
            string sale = sales.ToString();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "INSERT INTO sales_reciept VALUES(\'" +
            textBox13.Text.ToString() + "\'," + textBox12.Text.ToString() + "," + sale +
            ",sysdate )" ;
            insertEmp.CommandType = CommandType.Text;

            OracleCommand insertsales = con.CreateCommand();
            insertsales.CommandText = "INSERT INTO sales_detail VALUES(" +
            textBox5.Text.ToString() + "," + textBox12.Text.ToString() + "," + textBox2.Text.ToString() +
            "," + textBox1.Text.ToString() +")";
            insertsales.CommandType = CommandType.Text;
            
            OracleCommand updatequan = con.CreateCommand();
            updatequan.CommandText = "UPDATE product SET quantity = quantity - " +
                "(select quantity from sales_detail where p_id = "+ textBox1.Text.ToString() + ")" + "where p_id = " + textBox1.Text.ToString();
            updatequan.CommandType = CommandType.Text;
            
            int rows = insertEmp.ExecuteNonQuery();
            insertsales.ExecuteNonQuery();
            updatequan.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("product added to receipt", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            con.Close();
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click_1(object sender, EventArgs e)
        {

        }

        private void textBox13_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox12_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
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
