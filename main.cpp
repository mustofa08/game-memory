#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 4; // Ukuran papan permainan (misalnya, 4x4)

// Struktur untuk menyimpan informasi kartu
struct Card {
    char symbol;
    bool flipped;

    Card(char s, bool f) : symbol(s), flipped(f) {}
};

// Fungsi untuk mencetak papan permainan
void printBoard(const vector<vector<Card>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].flipped) {
                cout << board[i][j].symbol << " ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

// Fungsi untuk memeriksa apakah semua kartu telah terungkap
bool allCardsUncovered(const vector<vector<Card>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].flipped) {
                return false;
            }
        }
    }
    return true;
}

// Fungsi untuk mengocok urutan kartu dalam papan permainan
void shuffleBoard(vector<vector<Card>>& board) {
    vector<char> symbols;

    // Inisialisasi daftar simbol kartu
    for (char c = 'A'; c <= 'Z'; c++) {
        symbols.push_back(c);
    }

    // Menggandakan simbol kartu
    symbols.resize(BOARD_SIZE * BOARD_SIZE / 2, ' ');

    // Mengocok urutan simbol kartu
    random_shuffle(symbols.begin(), symbols.end());

    // Menempatkan kartu ke dalam papan permainan
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].symbol = symbols[index++];
        }
    }
}

// Fungsi untuk mengungkapkan kartu pada posisi tertentu
void flipCard(vector<vector<Card>>& board, int row, int col) {
    if (!board[row][col].flipped) {
        board[row][col].flipped = true;
        printBoard(board);
    }
}

// Fungsi untuk menutup kartu pada posisi tertentu
void coverCard(vector<vector<Card>>& board, int row, int col) {
    if (board[row][col].flipped) {
        board[row][col].flipped = false;
        printBoard(board);
    }
}

// Fungsi untuk memeriksa apakah dua kartu yang terungkap memiliki simbol yang sama
bool isMatch(const vector<vector<Card>>& board, int row1, int col1, int row2, int col2) {
    return (board[row1][col1].symbol == board[row2][col2].symbol);
}

// Fungsi untuk menjalankan permainan
void playGame() {
    vector<vector<Card>> board(BOARD_SIZE, vector<Card>(BOARD_SIZE, Card(' ', false)));

    shuffleBoard(board);

    int flips = 0;
    int row1, col1, row2, col2;

    while (!allCardsUncovered(board)) {
        cout << "Flips: " << flips << endl;
        printBoard(board);
        cout << "Enter the row and column of the first card: ";
        cin >> row1 >> col1;
        flipCard(board, row1, col1);

        cout << "Enter the row and column of the second card: ";
        cin >> row2 >> col2;
        flipCard(board, row2, col2);

        if (isMatch(board, row1, col1, row2, col2)) {
            cout << "Match found!" << endl;
        } else {
            cout << "No match. Try again." << endl;
            coverCard(board, row1, col1);
            coverCard(board, row2, col2);
        }

        flips++;
    }

    cout << "Congratulations! You completed the game in " << flips << " flips." << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inisialisasi seed untuk fungsi random_shuffle

    playGame();

    return 0;
}
