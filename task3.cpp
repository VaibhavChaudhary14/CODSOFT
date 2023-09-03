#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
        std::cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayers() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;
        bool validMove;

        std::cout << "TIC-TAC-TOE GAME\n";
        displayBoard();

        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
            validMove = makeMove(row - 1, col - 1);
            if (!validMove) {
                std::cout << "Invalid move! Try again.\n";
            }
        } while (!validMove);

        if (checkWin()) {
            displayBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
        } else if (checkDraw()) {
            displayBoard();
            std::cout << "It's a draw!\n";
        } else {
            switchPlayers();
            play();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
