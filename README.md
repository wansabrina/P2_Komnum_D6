# P2_Komnum_D6
Praktikum 2 Komputasi Numerik


### Anggota Kelompok
| Nama                | NRP        | Kelas     |
| ---                 | ---        | ----------|
| Najma Ulya Agustina | 5025211239 |  Komnum D |
| Syarifah Thalita Erfany | 5025211175 |Komnum D |
| Wan Sabrina Mayzura | 5025211023 |Komnum D |

## Soal 
Salah satu kelemahan dari metode Trapezoidal adalah kita harus menggunakan jumlah interval yang besar untuk memperoleh akurasi yang diharapkan. Buatlah sebuah program komputer untuk menjelaskan bagaimana metode Integrasi Romberg dapat mengatasi kelemahan tersebut.

## Penjelasan Kode
Disini kami menggunakan fungsi 1/x yang akan dicari integrasinya
```
double f(double x)
{
    return 1/x; // Contoh: f(x) = 1/x
}
```

Lalu terdapat fungsi untuk menghitung integral dengan metode trapezoidal yang selanjutnya akan diimplementasikan pada metode romberg. Dimana a adalah batas atas, b adalah batas bawah, dan n adalah jumlah pias.
```
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
```

Selanjutnya, terdapat fungsi romberg untuk menghitung integral dengan implementasi metode trapezoidal. Pada fungsi romberg, digunakan juga teknik interpolasi Richardson untuk menghitung nilai integral yang lebih akurat.

```
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
```

Disini kami menggunakan contoh batas atas atau ```a = 1```, batas bawah atau ```b = 10```, dan ```n = 5```. Berikut hasil integrasi setelah program dijalankan:

![image](https://user-images.githubusercontent.com/90106865/208910929-42ee8c11-bf5c-4aa4-81cf-d57b14519fa5.png)


## Kesimpulan
Untuk mengatasi kelemahan dari metode trapezoidal, pada metode romberg tetap digunakan implementasi metode trapezoidal, namun juga digunakan teknik interpolasi Richardson untuk menambah akurasi dari integralnya. Sehingga hasil akurasi metode romberg dapat dibuktikan dengan melihat tingkat errornya yang lebih kecil daripada metode trapezoidal, jika dibandingkan dengan hasil integrasi dengan menggunakan perhitungan integral secara analitik.

Error pada integrasi Romberg:

![error romberg](https://user-images.githubusercontent.com/90106865/208910322-bf4198a3-e3f9-48b1-89bb-3f612ae9575e.jpeg)

Error pada integrasi Trapezoidal:

![error trapezoidal](https://user-images.githubusercontent.com/90106865/208910409-2e48938a-c19d-446a-86d8-e64a09d1f7ba.jpg)


