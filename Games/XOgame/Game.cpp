﻿#include <iostream>
using namespace std;
int x;
int y;
class Board {
private:
    int rows = 3;
    int columns = 3;
    char** matrix;
    void checkwinner() {
        checkwinnerrows();
        checkwinnercolumns();
        checkwinnerdiagonal();
    }
    int x = -1;
    int y = -1;
    void WinnerWriteX()
    {
        cout << "\nHey who played for X You win\n";
        std::cout << "   __     ______  _    _ _   _ _     _\n"
            "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
            "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
            "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
            "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
            "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;


    }
    void WinnerWriteO()
    {
        cout << "\nHey who played for O You win\n";
        std::cout << "   __     ______  _    _ _   _ _     _\n"
            "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
            "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
            "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
            "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
            "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
    }
    void checkwinnercolumns(){

        if ((matrix[0][0]) == *("X") && matrix[1][0] == *("X") && matrix[2][0] == *("X")) {
            WinnerWriteX();
        }
        else if ((matrix[0][1]) == *("X") && matrix[1][1] == *("X") && matrix[2][1] == *("X")) {
            WinnerWriteX();
        }
        else if ((matrix[0][2]) == *("X") && matrix[1][2] == *("X") && matrix[2][2] == *("X")) {
            WinnerWriteX();
        }
        if ((matrix[0][0]) == *("O") && matrix[1][0] == *("O") && matrix[2][0] == *("O")) {
            WinnerWriteO();
        }
        else if ((matrix[0][1]) == *("O") && matrix[1][1] == *("O") && matrix[2][1] == *("O")) {
            WinnerWriteO();
        }
        else if ((matrix[0][2]) == *("O") && matrix[1][2] == *("O") && matrix[2][2] == *("O")) {
            WinnerWriteO();
        }
    }
    void checkwinnerrows() {
        if ((matrix[0][0]) == *("X") && matrix[0][1] == *("X") && matrix[0][2] == *("X")) {
            WinnerWriteX();
        }
        else if ((matrix[1][0]) == *("X") && matrix[1][1] == *("X") && matrix[1][2] == *("X")) {
            WinnerWriteX();
        }
        else if ((matrix[2][0]) == *("X") && matrix[2][1] == *("X") && matrix[2][2] == *("X")) {
            WinnerWriteX();
        }

        if ((matrix[0][0]) == *("O") && matrix[0][1] == *("O") && matrix[0][2] == *("O")) {
            WinnerWriteO();
        }
        else if ((matrix[1][0]) == *("O") && matrix[1][1] == *("O") && matrix[1][2] == *("O")) {
            WinnerWriteO();
        }
        else if ((matrix[2][0]) == *("O") && matrix[2][1] == *("O") && matrix[2][2] == *("O")) {
            WinnerWriteO();
        }
    }
    void checkwinnerdiagonal() {
        if ((matrix[0][0]) == *("X") && matrix[1][1] == *("X") && matrix[2][2] == *("X")) {
            WinnerWriteX();
        }
        if ((matrix[0][2]) == *("X") && matrix[1][1] == *("X") && matrix[2][0] == *("X")) {
            WinnerWriteX();
        }
        if ((matrix[0][0]) == *("O") && matrix[1][1] == *("O") && matrix[2][2] == *("O")) {
            WinnerWriteO();
        }
        if ((matrix[0][2]) == *("O") && matrix[1][1] == *("O") && matrix[2][0] == *("O")) {
            WinnerWriteO();
        }
    }
public:
    Board() {
        matrix = (char**)malloc(sizeof(char*) * rows);
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = (char*)malloc(sizeof(char) * columns);
        }
        default_value();
    }
    void default_value() {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = '=';
            }
        }
    }
    void display() {
        cout << "O /  1 / 2 / 3 /\n";
        short a = 0;
        short b = x;
        --b;
        for (int i = 0; i < rows; i++)
        {
            if (b != i) {
                a = i;
                cout << ++a << " / [";
            }
            else {
                cout << "->" << " / [";
            }
            for (int j = 0; j < columns; j++)
            {
                cout << matrix[i][j] << " | ";
            }
            cout << "]\n";
        }
    }
    void InputX() {
        cin >> x;
        if (3 < x)
        {
            cerr << "The inputed number cant be a bigger than three\n";
            throw abort;

        }
        display();
        cin >> y;
        if (3 < y)
        {
            cerr << "The inputed number cant be a bigger than three\n";
            throw abort;
        }
        --x;
        --y;
            while (matrix[x][y] == *("X") || matrix[x][y] == *("O"))
            {
                cerr << "You Cant Place above other played location\n";
                cin >> x;
                if (3 < x)
                {
                    cerr << "The inputed number cant be a bigger than three\n";
                    throw abort;

                }
                display();
                cin >> y;
                if (3 < y)
                {
                    cerr << "The inputed number cant be a bigger than three\n";
                    throw abort;
                }
                --x;
                --y;
            }
        matrix[x][y] = *("X");
         x = -1;
         y = -1;
    }
    void InputO() {
        cin >> x;
        if (3 < x)
        {
            cerr << "The inputed number cant be a bigger than three\n";
            throw abort;
        }
        display();
        cin >> y;
        if (3 < y)
        {
            cerr << "The inputed number cant be a bigger than three\n";
            throw abort;

        }
        --x;
        --y;
        while (matrix[x][y] == *("X") || matrix[x][y] == *("O"))
        {
            cerr << "You Cant Place above other played location\n";
            cin >> x;
            if (3 < x)
            {
                cerr << "The inputed number cant be a bigger than three\n";
                throw abort;
            }
            display();
            cin >> y;
            if (3 < y)
            {
                cerr << "The inputed number cant be a bigger than three\n";
                throw abort;

            }
            --x;
            --y;
        }
        matrix[x][y] = *("O");
        x = -1;
        y = -1;
    }
    ~Board() {
        for (int i = 0; i < rows; i++)
        {
            free(matrix[i]);
            matrix[i] = nullptr;
        }
        free(matrix);
        matrix = nullptr;
    }
    void start() {
        system("cls");
        cout << "The game is started input the where you want to place x\n";
        display();
        for (int i = 0; i < 9; i++)
        {
            InputX();
            system("cls");
            display();
            checkwinner();
            InputO();
            system("cls");
            checkwinner();
            display();
        }
    }

};
int main()
{
    cout << "Input the positions that you like to be an X\n";
    Board matrix;
    matrix.start();
    matrix.display();
}
