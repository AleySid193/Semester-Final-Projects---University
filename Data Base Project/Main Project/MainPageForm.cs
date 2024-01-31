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
    public partial class MainPageForm : Form
    {
        public MainPageForm()
        {
            InitializeComponent();
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void MainPage_Load(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            ProductForm c1 = new ProductForm();
            this.Hide();
            c1.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            RecieptForm c1 = new RecieptForm();
            this.Hide();
            c1.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            MarketingMainForm c1 = new MarketingMainForm();
            this.Hide();
            c1.ShowDialog();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            // Show a message box to confirm the shutdown
            DialogResult result = MessageBox.Show("Are you sure you want to shut down the program?", "Confirm Shutdown", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);

            // If the user confirms the shutdown, close the whole program
            if (result == DialogResult.Yes)
            {
                Application.Exit();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            CostumerForm c1 = new CostumerForm();
            this.Hide();
            c1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            VendorForm c1 = new VendorForm();
            this.Hide();
            c1.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {

            StocksForm c1 = new StocksForm();
            this.Hide();
            c1.ShowDialog();
        }

        private void MainPageForm_Load(object sender, EventArgs e)
        {
            //Application.Exit();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            ProfileForm v1 = new ProfileForm();
            this.Hide();
            v1.ShowDialog();
        }
    }
}
