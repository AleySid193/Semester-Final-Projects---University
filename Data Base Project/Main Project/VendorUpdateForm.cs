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
    public partial class VendorUpdateForm : Form
    {
        OracleConnection con;
        string vid;
        public VendorUpdateForm(string str)
        {
            vid = str;
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
                    insertEmp.CommandText = "UPDATE vendor SET v_name = \'" +
                        textBox6.Text.ToString() + "\', v_contact = " + textBox8.Text.ToString() + ", address = \'" + textBox7.Text.ToString() +
                        "\', email = \'" + textBox9.Text.ToString() + "\' where v_id = " + vid;
                    insertEmp.CommandType = CommandType.Text;
                    int rows = insertEmp.ExecuteNonQuery();
                    if (rows > 0)
                    {
                        MessageBox.Show("Vendor Updated", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        this.Close();
                    }
                    else
                    {
                        MessageBox.Show("Vendor Not Found", "Invalid Vendor ID", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        this.Close();
                    }
                    con.Close();
                    CostumerForm f1 = new CostumerForm();
                    this.Hide();
                    f1.ShowDialog();
                }
            }
            catch (Exception ex)
            {
                // Handle the exception
                MessageBox.Show("An error occurred: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void VendorUpdateForm_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            VendorForm v1 = new VendorForm();
            this.Hide();
            v1.ShowDialog();
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
