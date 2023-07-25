#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


class Board {
private:
    int m_rows = 8;
    int m_columns = 8;
    int x = -1;
    int y = -1;
    int move_x = -1;
    int move_y = -1;
    string** m_matrix;
    string B_Chessmate_types[9]{ " B.Rook "," B.Knight "," B.Bishop "," B.Queen "," B.King ","  W.Pawn " };
    string W_Chessmate_types[9]{ " W.Rook "," W.Knight "," W.Bishop "," W.Queen "," W.King ","  W.Pawn " };
protected:
    bool check_coords() {
        if (x < 0 || y < 0)
        {
            cout << "The block where you want to move doesent \n input again\n";
            throw std::abort;
        }
        else if (m_matrix[x][y] == " _______ ")
        {
            return 0;
        }
        else {
            return 1;
        }
    }
    bool check_coords(int x,int y) {
        if (x < 0 || y < 0)
        {
            cout << "The block where you want to move doesent \n input again\n";
            throw std::abort;
        }
        else if (m_matrix[x][y] == " _______ ")
        {
            return 0;
        }
        else {
            return 1;
        }
    }
#pragma region default board
    void def_init() {
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_columns; j++)
            {
                m_matrix[i][j] = " _______ ";
            }
        }
        string BChessmate_types[9]{ " B.Rook "," B.Knight "," B.Bishop "," B.Queen "," B.King "," B.Bishop "," B.Knight "," B.Rook " };
        string WChessmate_types[9]{ " W.Rook "," W.Knight "," W.Bishop "," W.Queen "," W.King "," W.Bishop "," W.Knight "," W.Rook " };
        for (int i = 0; i < 8; i++)
        {
            m_matrix[0][i] = WChessmate_types[i];
            m_matrix[1][i] = "  W.Pawn ";
        }
        for (int i = 0; i < 8; i++)
        {
            m_matrix[7][i] = BChessmate_types[i];
            m_matrix[6][i] = "  B.Pawn ";
        }
    }
#pragma endregion default board
public:
#pragma region constructors operator= and destructors
    Board() {
        m_matrix = new string * [m_rows];
        for (int i = 0; i < m_rows; i++)
        {
            m_matrix[i] = new string[m_columns];
        }
    }
    ~Board()noexcept {
        for (int i = 0; i < m_rows; i++)
        {
            delete[] m_matrix[i];
            m_matrix[i] = nullptr;
        }
        delete[] m_matrix;
        m_matrix = nullptr;
    }
    Board(Board&& other) noexcept : m_rows(other.m_rows), m_columns(other.m_columns), m_matrix(other.m_matrix) {
        other.m_rows = 0;
        other.m_columns = 0;
        other.m_matrix = nullptr;
        std::cout << "Move constructor called\n";
    }

    Board& operator= (Board&& other) noexcept {
        if (this != &other) {
            for (int i = 0; i < m_rows; i++) {
                delete[] m_matrix[i];
            }
            delete[] m_matrix;

            m_rows = other.m_rows;
            m_columns = other.m_columns;
            m_matrix = other.m_matrix;

            other.m_rows = 0;
            other.m_columns = 0;
            other.m_matrix = nullptr;
        }
        std::cout << "Move assignment operator called\n";
        return *this;
    }
#pragma endregion constructors operator= and destructors
#pragma region displayfunc
    void display() {
        char a = 'A';
        for (int i = 0; i < m_rows; i++)
        {

            cout << "     " << a << "   |";
            ++a;
        }
        cout << std::endl;
        for (int i = 0; i < m_rows; i++)
        {
            cout << std::endl << i << "[";
            for (int j = 0; j < m_columns; j++)
            {
                cout << m_matrix[i][j] << "|";
            }
            cout << "]\n";
        }
    }
#pragma endregion display function
    void W_select_figure() {
        while (x < 0 && y < 0)
        {
            cout << "Input the coordinats of figure that you want to move(first x and y)\n";
            cin >> x;
            cout << "Input the y\n";
            cin >> y;
        }
        if (check_coords() == 0)
        {
            cerr << "There wasnt figure\n;";
            throw abort;
        }
        else if (x > 8 || y > 8)
        {
            cerr << "the cordinats are illegal\n";
            throw abort;
        }
        for (size_t i = 0; i < m_rows; i++)
        {
            if (W_Chessmate_types[i] == m_matrix[x][y]) {
                return;
            }
        }
        throw abort;

    }
    void White_move_figure() {
        W_select_figure();
        while (move_x < 0 && move_y < 0) {
            cout << "Where you want to move that figure\n";
            cin >> move_x;
            cout << "Input the y\n";
            cin >> move_y;
        }
        if (move_x > 8 || move_y > 8)
        {
            cerr << "the cordinats are illegal\n";
            throw abort;
        }
        if (move_x == x && move_y == y)
        {
            cerr << "Error:you want to dont move figure\n";
            throw abort;
        }
        for (int i = 0; i < m_rows; i++)
        {
            if (W_Chessmate_types[i] == m_matrix[move_x][move_y]) {
                cerr << "ERROR:There was your figure\n";
                throw abort;
            }
        }
        if (m_matrix[x][y] == "  W.Pawn " && ((x+1 != 8 && y + 1 != 8 && check_coords(1 + x, 1 + y) && move_x == 1 + x && move_y == 1 + y) || (x == 1 && move_x == x + 2 && move_y == y ) || (x  + 1 != 8 && move_x == x + 1) || (x + 1 != 8 && y - 1 != 0 && check_coords(1 + x, y - 1) && move_x == 1 + x && move_y == y - 1)))
        {
                swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                x = -1;
                y = -1;
                move_x = -1;
                move_y = -1;
        } 
        else if (m_matrix[x][y] == " W.Knight " && ((move_x == 1 + x && move_y == y + 2) || (move_y == 1 + y && move_x == x + 2) || (y - 2 > -1 && move_x == 1 + x && move_y == y - 2) || (y - 1 > -1 && move_y == y - 1 && move_x == x + 2) || (y - 2 > -1 && x-1 > -1 && move_x == x-1 && move_y == y - 2) || (x - 1 > -1 && move_y == y + 2 && move_x == x - 1) || (y - 1  >= 0 && x - 2 >= 0 && move_y == y - 1 && move_x == x - 2) || (y + 1 >= 0 && x - 2 >= 0 && move_y == y + 1 && move_x == x - 2)))
        {
            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
            x = -1;
            y = -1;
            move_x = -1;
            move_y = -1;
        }
        else if (m_matrix[x][y] == " W.King " && ((x != 7 && move_x == x + 1) && (x != 0 && move_x == x - 1) && (y != 7 && move_y == y + 1) && (y != 0 && move_y == y+1) && (x + 1 != 8 && y + 1 != 8 && move_x == x + 1 && move_y == y + 1 ) && (x + 1 != 8 && y - 1 != -1 && move_x == x + 1 && move_y == y - 1)
            && (x - 1 != -1 && y - 1 != -1 && move_x == x - 1 && move_y == y - 1) && (x - 1 != -1 && y + 1 != 8 && move_x == x - 1 && move_y == y + 1)))
        {
            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
            x = -1;
            y = -1;
            move_x = -1;
            move_y = -1;
        }
        else if (m_matrix[x][y] == " W.Rook ")
        {
            int j = 20;
            if (move_x == x && move_y > y)
            {
                for (int i = y  + 1; i <= move_y; i++)
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
         else if (m_matrix[x][y] == " W.Bishop ")
        {
            int lim_x,lim_y  = 8;
            bool a = false;
            if (move_x > x && move_y  > y)
            {
                for (int i = x; i <= move_x; i++)
                {
                    for (int j = y; j <= move_y; j++)
                    {
                        if (m_matrix[i][j] != " _______ ")
                        {
                            lim_x = i;
                            lim_y = j;
                            a = true;
                            break;
                        }
                        else if (i == move_x && j == move_y)
                        {
                            lim_x = 8;
                            lim_y = 8;
                            a = 1;
                            break;
                        }

                    }
                    if (a)
                    {
                        break;
                    }
                }
                a = false;
                for (int i = x; i <= lim_x; i++)
                {
                    for (int j = y; j <= lim_y; j++)
                    {
                        if (move_x <= lim_x && move_y <= lim_y && move_x == x + i && move_y == y + j)
                        {
                            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                            x = -1;
                            y = -1;
                            move_x = -1;
                            move_y = -1;
                            a = true;
                            break;
                        }
                    }
                    if (a)
                    {
                        break;
                    }
                }
            }
            else if (move_x < x && move_y < y)
            {
                for (int i = x; i >= move_x; i--)
                {
                    for (int j = y; j >= move_y; j--)
                    {
                        if (m_matrix[i][j] != " _______ ")
                        {
                            lim_x = i;
                            lim_y = j;
                            a = true;
                            break;
                        }
                    }
                    if (a)
                    {
                        break;
                    }
                }
                a = false;
                for (int i = x; i >= lim_x; i--)
                {
                    for (int j = y; j >= lim_y; j--)
                    {
                        if (move_x <= lim_x && move_y <= lim_y && move_x == x + i && move_y == y + j)
                        {
                            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                            x = -1;
                            y = -1;
                            move_x = -1;
                            move_y = -1;
                            a = true;
                            break;
                        }
                    }
                    if (a)
                    {
                        break;
                    }
                }
            }
            else if (move_x < x && move_y > y)
            {
                a = false;
                for (int i = x; i >= move_x; i--)
                {
                    for (int j = y; j <= move_y; j++)
                    {
                        if (m_matrix[i][j] != " _______ ")
                        {
                            lim_x = i;
                            lim_y = j;
                            a = true;
                            break;
                        }
                    }
                    if (a)
                    {
                        break;
                    }
                }
                a = false;
                for (int i = x; i >= lim_x; i--)
                {
                    for (int j = lim_y; j <= lim_y; j++)
                    {
                        if (move_x <= lim_x && move_y <= lim_y && move_x == x + i && move_y == y + i)
                        {
                            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                            x = -1;
                            y = -1;
                            move_x = -1;
                            a = true;
                            move_y = -1;
                            break;
                        }
                    }
                    if (a)
                    {
                        break;
                    }
                }
            }
            else if (move_x > x && move_y < y)
            {
                for (int i = x + 1; i <= move_x; i++)
                {
                    for (int j = i; j >= move_y; j--)
                    {
                        if (m_matrix[i][j] != " _______ ")
                        {
                            lim_x = i;
                            lim_y = j;
                            a = true;
                            break; 
                        }
                        else if (i == move_x && j == move_y)
                        {
                            lim_x = 8;
                            lim_y = 8;
                            a = 1;
                            break;
                        }
                        break;

                    }
                    if (a == true)
                    {
                        break;
                  }
                }
                a = false;
                for (int i = x + 1; i <= lim_x; i++)
                {
                    for (int j = y + 1; j >= lim_y; j--)
                    {
                        if (move_x <= lim_x && move_y <= lim_y && move_x == x + i && move_y == y + j)
                        {
                            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                            x = -1;
                            y = -1;
                            move_x = -1;
                            move_y = -1;
                            a = true;
                            break;
                        }
                    }
                    if (a)
                    {
                        break;
                    }
                }
            }
            else 
            {
                cerr << "Your bishop want to do illegal move\n";
                throw abort;
            }
        }
        else
        {
            cerr << "Dont Correct move\n";
            throw abort;
        }
    }
    void swap(string* a, string* b)
    {
        string temp = *a;
        *a = *b;
        *b = " _______ ";
    }
    void start() {
        def_init();
        cout << "Hello To Chess Game Play as you want to play\n";
        cout << "Instructions:For first you must to input the\n";
        cout << "coordinats of chessman that you want to play\n";
        cout << "the secont you must be right input the coordinats\n";
        cout << "where you want to go your figure\n Nice game\n";
        display();
       
        White_move_figure();
        system("cls");
        display();
        White_move_figure();
        system("cls");
        display();
        White_move_figure();
        system("cls");
        display();
        White_move_figure();
        system("cls");
        display();
        White_move_figure();
        system("cls");
        display();
        White_move_figure();
        system("cls");
        display();
        White_move_figure();
        system("cls");
        display();
    }
};
int main()
{

    using namespace std::this_thread;
    using namespace std::chrono; 
    Board a;
    a.start();
}

