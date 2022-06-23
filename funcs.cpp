#include <iostream>
#include "funcs.hpp"

std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void introduction() {
    
    std::cout << "\n\nWelcome to Tic-Tac-Toe!\n\n" << "Press any key to begin... \n";
    std::cin.ignore();

    std::cout << "===========\n";
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "===========\n\n";

    std::cout << "Player 1: X\n";
    std::cout << "Player 2: O\n\n";

    std::cout << "Printing grid...\n\n";

    std::cout << "     |     |     \n";
    std::cout << "  1  |  2  |  3  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  4  |  5  |  6  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  7  |  8  |  9  \n";
    std::cout << "     |     |     \n\n";

}

bool winner() {
    bool winner = false;
    //rows
    if (board[0] == board[1] && board[1] == board[2] && board[0] != " ") {
        winner = true;
    } else if (board[3] == board[4] && board[4] == board[5] && board[3] != " ") {
        winner = true;
    } else if (board[6] == board[7] && board[7] == board[8] && board[6] != " ") {
        winner = true;
    }
    //columns
    else if (board[0] == board[3] && board[3] == board[6] && board[0] != " ") {
        winner = true;
    } else if (board[1] == board[4] && board[4] == board[7] && board[1] != " ") {
        winner = true;
    } else if (board[2] == board[5] && board[5] == board[8] && board[2] != " ") {
        winner = true;
    }
    //diagonals
    else if (board[0] == board[4] && board[4] == board[8] && board[0] != " ") {
        winner = true;
    } else if (board[2] == board[4] && board[4] == board[6] && board[2] != " ") {
        winner = true;
    }
    return winner;
}
bool filled() {
    bool fill = true;
    for (int i = 0; i < 9; i++) {
        if (board[i] == " ") {
            fill = false;
        }
    }
    return fill;
}
void take_turn() {
    while (!winner() && !filled()) {
        set_position();
        update_board();
        draw();
        change_player();
    }
}
void set_position() {
    std::cout << "Your move, player " << player << ". Pick a space 1-9: ";
    while (!(std::cin >> position)) {
        std::cout << "Player " << player << ", please choose an integer between 1 and 9: ";
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << "\n";
    while (board[position - 1] != " ") {
        std::cout << "Sorry that spot is already taken!\n";
        std::cout << "Please choose a new spot player" << player << ": ";
        std::cin >> position;
        std::cout << "\n";
    }
}
void change_player() {
    if (player == 1) {
        player++;
    } else {
        player--;
    }
}
void update_board() {
    if (player == 1) {
        board[position - 1] = "X";
    } else {
        board[position - 1] = "O";
    }
}
void draw() {
    std::cout << "\n\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
    std::cout << "     |     |     \n";
}
void end_game() {
    change_player();
    if (winner()) {
        std::cout << "Player " << player << " is victorius!\n";
    } else if (filled()) {
        std::cout << "It's a tie!\n";
    }
}