#include <iostream>
#include "Figures.h"
using namespace std;
bool check_coords(int x, int y, string** m_matrix) {
    if (x < 0 || y < 0)
    {
        cout << "The block where you want to move doesn't exist\ninput again\n";
        throw std::runtime_error("Invalid coordinates.");
    }
    else if (m_matrix[x][y] == " _______ ")
    {
        return false;
    }
    else {
        return true;
    }
}

void swap(string* a, string* b) {
    string temp = *a;
    *a = *b;
    *b = " _______ ";
}
void Figure::Move_Rook(int x, int y, int move_x, int move_y, string** m_matrix)
{
    if (m_matrix[x][y] == " W.Rook " || m_matrix[x][y] == " B.Rook ")
    {
        int j = 20;
        if (move_x == x && move_y > y)
        {
            for (int i = y + 1; i <= move_y; i++)
            {
                if (m_matrix[x][i] != " _______ ")
                {
                    j = i;
                    break;
                }
            }
            for (int i = y; i <= j; ++i)
            {
                if (move_y <= j && move_y == y + i)
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }
        }
        else if (move_x == x && move_y < y)
        {
            for (int i = y + 1; i <= move_y; i--)
            {
                if (m_matrix[x][i] != " _______ ")
                {
                    j = i;
                    break;
                }
            }
            for (int i = y; i <= j; ++i)
            {
                if (move_y <= j && move_y == y - i)
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }
        }
        else if (move_x > x && move_y == y)
        {
            for (int i = x + 1; i <= move_x; i++)
            {
                if (m_matrix[i][y] != " _______ ")
                {
                    j = i;
                    break;
                }
            }
            for (int i = x; i <= j; ++i)
            {
                if (move_x <= j && move_x == x + i)
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }
        }
        else if (move_x < x && move_y == y)
        {
            for (int i = x + 1; i <= move_x; i--)
            {
                if (m_matrix[i][y] != " _______ ")
                {
                    j = i;
                    break;
                }
            }
            for (int i = x; i <= j; ++i)
            {
                if (move_x <= j && move_x == x - i)
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }
        }
        else
        {
            cerr << "Error:your rook want to do incorrect move\n";
            throw abort;
        }
    }
};
void Figure::Move_Queen(int x, int y, int move_x, int move_y, string** m_matrix)
{
    if (m_matrix[x][y] == " W.Queen " || m_matrix[x][y] == " B.Queen ")
    {
        int lim_x = 8, lim_y = 8;

        if (move_x > x && move_y > y)
        {
            for (int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
            {
                if ((move_x <= lim_x && move_y <= lim_y && move_x == x + i && move_y == y + j) || (lim_x == 8 && lim_y == 8 && move_x == x + i && move_y == y + j))
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }

            lim_x = 8;
            lim_y = 8;
        }

        else if (move_x < x && move_y < y)
        {
            for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
            {
                if ((move_x >= lim_x && move_y >= lim_y && move_x == x - i && move_y == y - j) || (lim_x == 8 && lim_y == 8 && move_x == x - i && move_y == y - j))
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }

            lim_x = 8;
            lim_y = 8;
        }

        else if (move_x < x && move_y > y)
        {
            for (int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
            {
                if ((move_x >= lim_x && move_y <= lim_y && move_x == x - i && move_y == y + j) || (lim_x == 8 && lim_y == 8 && move_x == x - i && move_y == y + j))
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }
        }

        else if (move_x > x && move_y < y)
        {
            for (int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
            {
                if ((move_x <= lim_x && move_y >= lim_y && move_x == x + i && move_y == y - j) || (lim_x == 8 && lim_y == 8 && move_x == x + i && move_y == y - j))
                {
                    swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                    x = -1;
                    y = -1;
                    move_x = -1;
                    move_y = -1;
                    break;
                }
            }
        }

        else
        {
            int j = 20;
            if (move_x == x && move_y > y)
            {
                for (int i = y + 1; i <= move_y; i++)
                {
                    if (m_matrix[x][i] != " _______ ")
                    {
                        j = i;
                        break;
                    }
                }
                for (int i = y; i <= j; ++i)
                {
                    if (move_y <= j && move_y == y + i)
                    {
                        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                        x = -1;
                        y = -1;
                        move_x = -1;
                        move_y = -1;
                        break;
                    }
                }
            }
            else if (move_x == x && move_y < y)
            {
                for (int i = y - 1; i >= move_y; i--)
                {
                    if (m_matrix[x][i] != " _______ ")
                    {
                        j = i;
                        break;
                    }
                }
                for (int i = y; i <= j; ++i)
                {
                    if (move_y <= j && move_y == y - i)
                    {
                        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                        x = -1;
                        y = -1;
                        move_x = -1;
                        move_y = -1;
                        break;
                    }
                }
            }
            else if (move_x > x && move_y == y)
            {
                for (int i = x + 1; i <= move_x; i++)
                {
                    if (m_matrix[i][y] != " _______ ")
                    {
                        j = i;
                        break;
                    }
                }
                for (int i = x; i <= j; ++i)
                {
                    if (move_x <= j && move_x == x + i)
                    {
                        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                        x = -1;
                        y = -1;
                        move_x = -1;
                        move_y = -1;
                        break;
                    }
                }
            }
            else if (move_x < x && move_y == y)
            {
                for (int i = x + 1; i <= move_x; i--)
                {
                    if (m_matrix[i][y] != " _______ ")
                    {
                        j = i;
                        break;
                    }
                }
                for (int i = x; i <= j; ++i)
                {
                    if (move_x <= j && move_x == x - i)
                    {
                        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                        x = -1;
                        y = -1;
                        move_x = -1;
                        move_y = -1;
                        break;
                    }
                }
            }
            else {
                cerr << "Your queen wants to do a wrong move\n";
            }
        }
    }
}
void Figure::Move_Bishop(int x, int y, int move_x, int move_y, string** m_matrix)
{
    if (m_matrix[x][y] == " W.Bishop " || m_matrix[x][y] == " B.Bishop ")
    {
        int lim_x = 8, lim_y = 8;

        if (move_x > x && move_y > y)
        {
            for (int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            if ((move_x <= lim_x && move_y <= lim_y && move_x == x + (move_x - x) && move_y == y + (move_y - y)) || (lim_x == 8 && lim_y == 8 && move_x == x + (move_x - x) && move_y == y + (move_y - y)))
            {
                swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                return;
            }
        }
        else if (move_x < x && move_y < y)
        {
            for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            if ((move_x >= lim_x && move_y >= lim_y && move_x == x + (move_x - x) && move_y == y + (move_y - y)) || (lim_x == 8 && lim_y == 8 && move_x == x + (move_x - x) && move_y == y + (move_y - y)))
            {
                swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                return;
            }
        }
        else if (move_x < x && move_y > y)
        {
            for (int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            if ((move_x >= lim_x && move_y <= lim_y && move_x == x + (move_x - x) && move_y == y + (move_y - y)) || (lim_x == 8 && lim_y == 8 && move_x == x + (move_x - x) && move_y == y + (move_y - y)))
            {
                swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                return;
            }
        }
        else if (move_x > x && move_y < y)
        {
            for (int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j)
            {
                if (m_matrix[i][j] != " _______ ")
                {
                    lim_x = i;
                    lim_y = j;
                    break;
                }
            }
            if ((move_x <= lim_x && move_y >= lim_y && move_x == x + (move_x - x) && move_y == y + (move_y - y)) || (lim_x == 8 && lim_y == 8 && move_x == x + (move_x - x) && move_y == y + (move_y - y)))
            {
                swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                return;
            }
        }

        throw std::runtime_error("Your bishop wants to do an illegal move");
    }
}

void Figure::Move_Pawn(int x, int y, int move_x, int move_y, string** m_matrix) {
    if (m_matrix[x][y] == "  W.Pawn " && ((x + 1 != 8 && y + 1 != 8 && check_coords(1 + x, 1 + y, m_matrix) && move_x == 1 + x && move_y == 1 + y) ||
        (x == 1 && move_x == x + 2 && move_y == y) ||
        (move_y == y && x + 1 != 8 && move_x == x + 1) ||
        (x + 1 != 8 && y - 1 != -1 && check_coords(1 + x, y - 1, m_matrix) && move_x == 1 + x && move_y == y - 1)))
    {
        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
        x = -1;
        y = -1;
        move_x = -1;
        move_y = -1;
    }
    else if (m_matrix[x][y] == "  B.Pawn " && ((x - 1 != -1 && y - 1 != -1 && check_coords(x - 1, y - 1, m_matrix) && move_x == x - 1 && move_y == y - 1) ||
        (x == 6 && move_x == x - 2 && move_y == y) ||
        (x - 1 != -1 && move_x == x - 1 && move_y == y) ||
        (x - 1 != -1 && y + 1 != 8 && check_coords(x - 1, y + 1, m_matrix) && move_x == x - 1 && move_y == y + 1)))
    {
        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
        x = -1;
        y = -1;
        move_x = -1;
        move_y = -1;
    }
    else
    {
        throw std::runtime_error("Invalid move for the pawn!");
    }
};

void Figure::Move_Knight(int x, int y, int move_x, int move_y, string** m_matrix) {
    if (((m_matrix[x][y] == " W.Knight " || m_matrix[x][y] == " B.Knight ") &&
        ((move_x == x + 1 && move_y == y + 2) ||
            (move_y == y + 1 && move_x == x + 2) ||
            (move_x == x + 1 && move_y == y - 2) ||
            (move_y == y - 1 && move_x == x + 2) ||
            (move_x == x - 1 && move_y == y - 2) ||
            (move_y == y + 2 && move_x == x - 1) ||
            (move_y == y - 1 && move_x == x - 2) ||
            (move_y == y + 1 && move_x == x - 2))))
    {
        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
        x = -1;
        y = -1;
        move_x = -1;
        move_y = -1;
    }
    else
    {
        cerr << "Your Knight wants to do an illegal move." << endl;
    }
};
void Figure::Move_King(int x, int y, int move_x, int move_y, string** m_matrix) {
    if (((m_matrix[x][y] == " W.King " || m_matrix[x][y] == " B.King ") &&
        ((x != 7 && move_x == x + 1) ||
            (x != 0 && move_x == x - 1) ||
            (y != 7 && move_y == y + 1) ||
            (y != 0 && move_y == y - 1) ||
            (x + 1 != 8 && y + 1 != 8 && move_x == x + 1 && move_y == y + 1) ||
            (x + 1 != 8 && y - 1 != -1 && move_x == x + 1 && move_y == y - 1) ||
            (x - 1 != -1 && y - 1 != -1 && move_x == x - 1 && move_y == y - 1) ||
            (x - 1 != -1 && y + 1 != 8 && move_x == x - 1 && move_y == y + 1))))
    {
        swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
        x = -1;
        y = -1;
        move_x = -1;
        move_y = -1;
    }
    else
    {
        cerr << "Your King wants to do an illegal move." << endl;
    }
};