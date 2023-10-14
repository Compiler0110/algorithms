#ifndef ALGO_8QUEEN_H__
#define ALGO_8QUEEN_H__

#include <iostream>
#include <vector>

namespace alg {
    class Queen8 {
    private:
        std::vector<std::vector<char>> board;
        int cnt;

    public:
        Queen8() : board(8, std::vector<char>(8, '0')), cnt(0) {}

        void solve() {
            cnt = 0;
            _solve(0);
        }

    private:
        void _solve(int row) {
            if (row == 8) {
                print();
                return;
            }

            for (int col = 0; col < 8; col++) {
                if (check(row, col)) {
                    board[row][col] = '1';
                    _solve(row + 1);
                    board[row][col] = '0'; // rollback
                }
            }
        }

        void print() {
            std::cout << "Chessboard: " << ++cnt << std::endl;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    std::cout << board[i][j] << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        bool check(int row, int col) {
            for (int i = 0; i < row; i++) {
                if (board[i][col] == '1') {
                    return false; // Same column
                }

                int diag1 = col - (row - i);
                int diag2 = col + (row - i);

                if (diag1 >= 0 && board[i][diag1] == '1') {
                    return false; // Diagonal from top-left to bottom-right
                }

                if (diag2 < 8 && board[i][diag2] == '1') {
                    return false; // Diagonal from top-right to bottom-left
                }
            }

            return true;
        }
    };
}

#endif // ALGO_8QUEEN_H__
//Odii Fakher
