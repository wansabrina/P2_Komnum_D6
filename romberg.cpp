/*
Kelompok 6
Anggota Kelompok:
    Najma Ulya Agustina	    5025211239
    Syarifah Thalita Erfany	5025211175
    Wan Sabrina Mayzura	    5025211023
*/

#include <iostream>
#include <cmath>

using namespace std;

// Fungsi yang akan dicari integrasinya
double f(double x)
{
    return 1/x; // Contoh: f(x) = 1/x
}

// Fungsi untuk menghitung integral dengan metode trapezoidal
double trapezoidal(double a, double b, int n)
{
    // Menghitung lebar subinterval/trapesium
    double h = (b - a) / n;
 
    // Menghitung jumlah suku pertama dan terakhir
    // dengan menggunakan fungsi f
    double r = f(a) + f(b);
 
    // Menjumlahkan suku tengah dalam rumus di atas
    for (int i = 1; i < n; i++)
        r += 2 * f(a + i * h);
 
    // lalu mengalikan h/2 dengan r
    return (h/2) * r;
}

// Fungsi untuk menghitung integral dengan integrasi Romberg
double romberg(double a, double b, int n)
{
    // Matriks untuk menyimpan nilai integral yang dihitung dengan metode trapezoidal
    double r[n+1][n+1];

    // Melakukan inisialisasi array dengan hasil dari metode trapezoidal
    for (int i = 1; i <= n; i++)
        r[i][1] = trapezoidal(a, b, pow(2, i-1));

    // Menampilkan hasil integral dengan n = 1
    cout << "Nilai integral dengan n = " << 1 << ": " << r[1][1] << endl;

    // Menggunakan teknik interpolasi Richardson untuk menghitung nilai integral yang lebih akurat
    // Dan akan menampilkan masing masing hasil integral tiap n dimulai dari n = 2
    for (int j = 2; j <= n; j++)
        for (int i = j; i <= n; i++)
        {
            r[i][j] = (pow(4, j-1) * r[i][j-1] - r[i-1][j-1]) / (pow(4, j-1) - 1);
            cout << "Nilai integral dengan n = " << j << ": " << r[i][j] << endl;
        }

    return r[n][n]; //Hasil akhir yang akan disimpan dalam r[n][n]
}

int main()
{
    // Batas atas dan batas bawah integral
    double a = 1;
    double b = 10;

    // Jumlah subinterval/pias yang digunakan
    int n = 5;

    // Menampilkan hasil integrasi metode Romberg dan Trapezoidal
    cout << "Hasil integrasi Romberg: " << romberg(a, b, n) << endl;
    cout << "Hasil integrasi Trapezoidal: " << trapezoidal(a, b, n) << endl;

    return 0;
}
