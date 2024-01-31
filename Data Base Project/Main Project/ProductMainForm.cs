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
    public partial class ProductForm : Form
    {
        OracleConnection con;
        public ProductForm()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            ProductUpdate p1 = new ProductUpdate(textBox6.Text.ToString());
            this.Hide();
            p1.ShowDialog();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                con.Open();
                OracleCommand insertEmp = con.CreateCommand();
                insertEmp.CommandText = "INSERT INTO product VALUES(" +
                textBox1.Text.ToString() + "," + textBox4.Text.ToString() + ",\'" + textBox2.Text.ToString() +
                "\'," + textBox3.Text.ToString() + "," + textBox9.Text.ToString() + "," + textBox5.Text.ToString() + ")";
                insertEmp.CommandType = CommandType.Text;
                int rows = insertEmp.ExecuteNonQuery();
                if (rows > 0)
                {
                    MessageBox.Show("Product Added", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    textBox1.Text = textBox4.Text = textBox2.Text = textBox3.Text = textBox9.Text = textBox5.Text = "";
                }
                con.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("An Error Occurred : " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                // Additional error handling code if needed
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {

            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {

            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {

            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {

            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void ProductForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            ProductViewForm p1 = new ProductViewForm();
            this.Hide();
            p1.ShowDialog();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void button6_Click_1(object sender, EventArgs e)
        {
            ProductSearchForm v1 = new ProductSearchForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void button9_Click_1(object sender, EventArgs e)
        {
            MainPageForm v1 = new MainPageForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void button8_Click_1(object sender, EventArgs e)
        {
            ProductViewForm v1 = new ProductViewForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void tabPage4_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click_1(object sender, EventArgs e)
        {

        }

        private void button7_Click_1(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Delete from product where p_id = " +
            textBox7.Text.ToString();
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                // Show a message box with a "Confirm" button
                DialogResult result = MessageBox.Show("Caution!! The product will be deleted", "Delete Product", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);

                // If the user confirms the deletion, show another message box with the confirmation message
                if (result == DialogResult.OK)
                {
                    MessageBox.Show("Product deleted!!", "Confirmation", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            con.Close();
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
            MainPageForm v1 = new MainPageForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click_1(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            MainPageForm v1 = new MainPageForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void button2_Click_2(object sender, EventArgs e)
        {
            if (textBox6.Text.ToString() == "")
            {
                MessageBox.Show("Please Fill The Text Box!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                ProductUpdate p1 = new ProductUpdate(textBox6.Text.ToString());
                this.Hide();
                p1.ShowDialog();

            }
        }

        private void textBox6_TextChanged_1(object sender, EventArgs e)
        {

        }
    }
}
