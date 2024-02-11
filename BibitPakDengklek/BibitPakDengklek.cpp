#include <cmath>
#include <iostream>
#include <list>

#define CARI_SELISIH(X, Y) ((X < Y) ? Y - X : X - Y)

typedef struct Vec2 {
	unsigned long row;
	unsigned long col;
} Vec2;

int
main()
{
	const unsigned long MAX_N = (unsigned long)pow(10, 9);
	unsigned long jumlah_bibit = 0;

	std::list<Vec2> Kemungkinan;

	unsigned long selisih_terkecil = -1;

	std::cout << "Jumlah Bibit: ";
	std::cin >> jumlah_bibit;

	if (jumlah_bibit < 0 || jumlah_bibit > MAX_N) {
		std::cerr << "Jumlah Bibit invalid!";
		return -1;
	}

	// cari ukuran lahan yang sesuai
	for (unsigned long row = 0; row <= jumlah_bibit; row++) {
		for (unsigned long col = 0; col <= jumlah_bibit; col++) {

			if ((row * col != jumlah_bibit) || (row == col))
				continue;

			unsigned long selisih = CARI_SELISIH(row, col);

			if ((row == 1 && col == 1) ||
			    (selisih < selisih_terkecil)) {
				selisih_terkecil = selisih;
			}

			Kemungkinan.push_back({.row = row, .col = col});
		}
	}

	// cari ukuran yang memiliki selisih terkecil
	for (Vec2 ukuran : Kemungkinan) {
		if ((CARI_SELISIH(ukuran.row, ukuran.col) == selisih_terkecil))
			std::cout << ukuran.row << "X" << ukuran.col << "\n";
	}

	return 0;
}
