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
    public partial class CostumerForm : Form
    {
        OracleConnection con;
        public CostumerForm()
        {
            InitializeComponent();
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void tabPage3_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Delete from customer where C_id = " +
            textBox7.Text.ToString();
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                // Show a message box with a "Confirm" button
                DialogResult result = MessageBox.Show("Caution!! The Customer will be deleted", "Delete Product", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);

                // If the user confirms the deletion, show another message box with the confirmation message
                if (result == DialogResult.OK)
                {
                    MessageBox.Show("Customer deleted!!", "Confirmation", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
            con.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
         
        }

        private void button1_Click(object sender, EventArgs e)
        {

            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "INSERT INTO customer VALUES(" +
            textBox10.Text.ToString() + ",\'" + textBox1.Text.ToString() + "\'," + textBox8.Text.ToString() +
            ",\'" + textBox2.Text.ToString() +"\',\'" + textBox9.Text.ToString() + "\')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Customer added", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            con.Close();
            
        }

        private void button4_Click(object sender, EventArgs e)
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

        private void button6_Click(object sender, EventArgs e)
        {
            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void button9_Click(object sender, EventArgs e)
        {

            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            CustomerSearchForm p1 = new CustomerSearchForm();
            this.Hide();
            p1.ShowDialog();
        }

        private void CostumerForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            if (textBox6.Text.ToString() == "")
            {
                MessageBox.Show("Please Fill The Text Box!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            else
            {
                CostumerUpdate p1 = new CostumerUpdate(textBox6.Text.ToString());
                this.Hide();
                p1.ShowDialog();

            }

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)
        {
            CustomerViewForm p1 = new CustomerViewForm();
            this.Hide();
            p1.ShowDialog();
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
