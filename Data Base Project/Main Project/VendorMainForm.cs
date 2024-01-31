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
    public partial class VendorForm : Form
    {
        OracleConnection con;
        public VendorForm()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Delete from vendor where v_id = " +
            textBox2.Text.ToString();
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                // Show a message box with a "Confirm" button
                DialogResult result = MessageBox.Show("Caution!! The Vendor will be deleted", "Vendor Product", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);

                // If the user confirms the deletion, show another message box with the confirmation message
                if (result == DialogResult.OK)
                {
                    MessageBox.Show("Vendor deleted", "Confirmation", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            con.Close();
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.ToString() == "")
            {
                MessageBox.Show("Please Fill The Text Box!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                VendorUpdateForm V1 = new VendorUpdateForm(textBox1.Text.ToString());
                this.Hide();
                V1.ShowDialog();

            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "INSERT INTO vendor VALUES(" +
            textBox10.Text.ToString() + ",\'" + textBox9.Text.ToString() + "\',\'" + textBox6.Text.ToString() +
            "\',\'" + textBox7.Text.ToString() + "\'," + textBox8.Text.ToString() +")";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Vendor added", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            con.Close();
           

        }

        private void button5_Click(object sender, EventArgs e)
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

        private void button7_Click(object sender, EventArgs e)
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

        private void VendorForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click_1(object sender, EventArgs e)
        {
            VendorViewForm obj = new VendorViewForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            VendorSearchForm obj = new VendorSearchForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
