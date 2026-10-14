#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Student {
    std::string name;
    unsigned int age;
};

void tampilkanStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Belum ada user. " << std::endl;
        return;
    }

    std::cout << "Daftar user: " << std::endl;
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << i + 1 << ". " << students[i].name << " ("
        << students[i].age << " tahun)" << std::endl;
    }
}

void bersihkanInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<Student> students;
    int choices = 0;
    while (true) {
        std::cout << "1. Tambah user. " << std::endl;
        std::cout << "2. Tampilkan user. " << std::endl;
        std::cout << "3. Hapus user. " << std::endl;
        std::cout << "4. Exit. " << std::endl;
        std::cout << "Pilih: ";

        if (!(std::cin >> choices)) {
            bersihkanInput();
            std::cout << "Input harus berupa angka. " << std::endl;
            continue;
        }

        if (choices == 1) {
            std::string name;
            unsigned int age;

            std::cout << "Nama: ";
            bersihkanInput();
            std::getline(std::cin, name);

            std::cout << "Umur: ";
            if (!(std::cin >> age)) {
                bersihkanInput();
                std::cout << "Input tidak valid. " << std::endl;
                continue;
            }

            students.push_back({name, age});
            std::cout << "User \"" << name << "\" berhasil ditambahkan." << std::endl;
        } else if (choices == 2) {
            tampilkanStudents(students);
        } else if (choices == 3) {
            tampilkanStudents(students);
            if (students.empty()) continue;
            size_t nomor;
            std::cout << "Nomor user yang mau dihapus: ";
            if (!(std::cin >> nomor) || nomor < 1 || nomor > students.size()) {
                bersihkanInput();
                std::cout << "Nomor tidak valid. " << std::endl;
                continue;
            }
        } else if (choices == 3) {
            std::cout << "Keluar..." << std::endl;
            break;
        } else {
            std::cout << "Pilihan tidak tersedia. " << std::endl;
        }
    }

    return 0;
}