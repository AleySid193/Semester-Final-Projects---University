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
    public partial class CostumerUpdate : Form
    {
        string cid;
        OracleConnection con;
        public CostumerUpdate(string str)
        {
            cid = str;
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBox6.Text.ToString() == "" && textBox8.Text.ToString() == "" && textBox7.Text.ToString() == "" && textBox9.Text.ToString() == "")
                {
                    MessageBox.Show("Please Fill The Text Boxes!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                else
                {
                    con.Open();
                    OracleCommand insertEmp = con.CreateCommand();
                    insertEmp.CommandText = "UPDATE customer SET c_name = \'" +
                        textBox6.Text.ToString() + "\', contact_num = " + textBox8.Text.ToString() + ", address = \'" + textBox7.Text.ToString() +
                        "\', email = \'" + textBox9.Text.ToString() + "\' where c_id = " + cid;
                    insertEmp.CommandType = CommandType.Text;
                    int rows = insertEmp.ExecuteNonQuery();
                    if (rows > 0)
                    {
                        MessageBox.Show("Customer Updated", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        textBox7.Text = textBox9.Text = textBox8.Text = textBox6.Text = "";
                    }
                    else
                    {
                        MessageBox.Show("Customer Not Found", "Invalid Customer ID", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                }
            }
            catch (Exception ex)
            {
                // Handle the exception
                MessageBox.Show("An error occurred: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void CostumerUpdateForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            CostumerForm c1 = new CostumerForm();
            this.Hide();
            c1.ShowDialog();
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
