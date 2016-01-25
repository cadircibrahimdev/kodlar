using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb; // Bu Komut İle OleDb Kütüphanesini ekliyoruz arkadaşlar

namespace WindowsFormsApplication7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        OleDbConnection con = new OleDbConnection("Provider=Microsoft.ACE.OleDb.12.0;Data Source=data.accdb"); /* Arkadaşlar bu kod ile veritabanına bağlanıyoruz. Data Sorce = data.accdb kısmındaki data ismi sizin dosyanızın adı ne ise onunla değiştirin
 
        */
        private void button1_Click(object sender, EventArgs e)
        {
            con.Close();// Close() ile bağlantımızı kapatıyoruz.
            con.Open(); /* Open() ilede açıyoruz. Neden önce kapatıp sonra açtığımızı soracak olursanız Kontrol amaçlı yaptık  eğer bağlantı açık ise bir daha açarsak hata verir çünkü */
            OleDbCommand query = new OleDbCommand("Select * from users where username=@usern AND password=@pass ", con);
            query.Parameters.AddWithValue("usern",textBox1.Text);
            query.Parameters.AddWithValue("pass",textBox2.Text);
/*Eğer Sql Bilginiz var ise zaten bu kodlar yabancı gelmemiştir size. Bu kod ile con bağlantısı içindeki users tablosundan username= textBox1.Text e eşit olan ve passwordu textBox2.Text; eşit olan veriyi çekiyoruz. textBox1.Text ve textBox2.text; leri Sql cümlemizde yazmıyoruz ama gördüğünüz gibi hemen aşağısında  query.Parameters.AddWithValue ile sql cümlesinde verdiğimiz isimlere değer atıyoruz. */
            OleDbDataReader dr = query.ExecuteReader(); // Bu kod ilede Sql cümlemizi işlilyoruz
            if (dr.Read()) /*bu koşul veri varsa anlamına geliyor. */
            {
                /*Kullanıcı adı ve şifre eğer doğru girilmiş ise burası çalışır.. Eğer Burası çalıştığında mesaj yazdırmak yerine farklı bir forma geçmek istiyorsanız Şu şekilde değiştirebilirsiniz kodlarınızı;
                        this.Hide();
                        Form2 fr2 = new Form2();
                        fr2.Show();
*/
                MessageBox.Show("GİRİŞ BAŞARILI");
            }
            else
            {
                 /*Kullanıcı adı ve şifre eğer yanlış girilmişse burası çalışır.*/
                MessageBox.Show("Giriş Başarısız");
            }
            textBox2.Text = "";
            textBox1.Text = "";
            con.Close();
             /* Son olarakta textBox ları boşaltıyoruz ve bağlantımızı kapatıyoruz...
  
             */
        }
    }
}
