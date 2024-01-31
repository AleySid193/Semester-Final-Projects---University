using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DB_FINAL_PROJECT_2
{
    public partial class ProfileForm : Form
    {
        public ProfileForm()
        {
            InitializeComponent();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            MainPageForm v1 = new MainPageForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            AdminAddForm v1 = new AdminAddForm();
            this.Hide();
            v1.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdminUpdateForm v1 = new AdminUpdateForm();
            this.Hide();
            v1.ShowDialog();
        }
    }
}
