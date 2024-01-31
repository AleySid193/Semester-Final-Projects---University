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
    public partial class MarketingMainForm : Form
    {
        int opt_select = 0;
        OracleConnection con;
        public MarketingMainForm()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (opt_select == 1)
            {
                con.Open();

                // Get the count from the customers table
                string customerCount;
                using (OracleCommand countCommand = con.CreateCommand())
                {
                    countCommand.CommandText = "SELECT COUNT(*) FROM customer";
                    countCommand.CommandType = CommandType.Text;
                    customerCount = Convert.ToString(countCommand.ExecuteScalar());
                }

                // Insert the count into the notifications table
                using (OracleCommand insertEmp = con.CreateCommand())
                {
                    insertEmp.CommandText = "INSERT INTO notifications (message, time, counter, recepeint) VALUES (\'" + textBox2.Text.ToString() + " \', systimestamp, " + customerCount + ", \'C\')";
                    insertEmp.CommandType = CommandType.Text;
                    insertEmp.ExecuteNonQuery();
                    MessageBox.Show("Message Sent To Customers :)");

                }
                textBox2.Text = "";
                opt_select = 0;
                con.Close();

            }
            else if (opt_select == 2)
            {
                con.Open();

                // Get the count from the customers table
                string customerCount;
                using (OracleCommand countCommand = con.CreateCommand())
                {
                    countCommand.CommandText = "SELECT COUNT(*) FROM vendor";
                    countCommand.CommandType = CommandType.Text;
                    customerCount = Convert.ToString(countCommand.ExecuteScalar());
                }

                // Insert the count into the notifications table
                using (OracleCommand insertEmp = con.CreateCommand())
                {
                    insertEmp.CommandText = "INSERT INTO notifications (message, time, counter, recepeint) VALUES (\'" + textBox2.Text.ToString() + " \', systimestamp, " + customerCount + ", \'V\')";
                    insertEmp.CommandType = CommandType.Text;
                    insertEmp.ExecuteNonQuery();
                    MessageBox.Show("Message Sent To Vendors :)");

                }
                textBox2.Text = "";
                opt_select = 0;
                con.Close();
            }
            else
            {
                MessageBox.Show("Please Select One Of The Options :)");
            }

        }

        private void MarketingForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            MainPageForm obj = new MainPageForm();
            this.Hide();
            obj.ShowDialog();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            opt_select = 1;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            opt_select = 2;
        }
    }
}
