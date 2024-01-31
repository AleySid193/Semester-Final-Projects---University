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
    public partial class AdminPageForm : Form
    {
        OracleConnection con;
        public AdminPageForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string conStr = @"DATA SOURCE = localhost:1521/xe; USER ID =ALI; PASSWORD = 123";
            con = new OracleConnection(conStr);
        }

        private void label1_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBox1.Text == "" || maskedTextBox1.Text == "")
                {
                    MessageBox.Show("Please Fill The Text Boxes!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    con.Open();

                    OracleCommand selectEmp = con.CreateCommand();
                    selectEmp.CommandText = "SELECT * FROM admin WHERE username = \'" + textBox1.Text.ToString() + "\' AND password = \'" + maskedTextBox1.Text.ToString() + "\'";
                    selectEmp.CommandType = CommandType.Text;
                    OracleDataReader reader = selectEmp.ExecuteReader();

                    if (reader.Read())
                    {
                        MessageBox.Show("Login Successful", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        MainPageForm v1 = new MainPageForm();
                        this.Hide();
                        v1.ShowDialog();
                    }
                    else
                    {
                        MessageBox.Show("Invalid Credentials", "Login Failed", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        AdminPageForm v1 = new AdminPageForm();
                        this.Hide();
                        v1.ShowDialog();
                    }

                    reader.Close();
                }

            }
            catch (Exception ex)
            {
                // Handle the exception
                MessageBox.Show("An Error Occurred : " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }


        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {
            if (maskedTextBox1.PasswordChar == '*')
            {
                maskedTextBox1.PasswordChar = '\0';  // Show the actual text
            }
            else
            {
                maskedTextBox1.PasswordChar = '*';   // Show the masked text
            }
        }

        private void label7_Click(object sender, EventArgs e)
        {
            // Show a message box to confirm the shutdown
            DialogResult result = MessageBox.Show("Are you sure you want to shut down the program?", "Confirm Shutdown", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);

            // If the user confirms the shutdown, close the whole program
            if (result == DialogResult.Yes)
            {
                Application.Exit();
            }
        }
    }
}
