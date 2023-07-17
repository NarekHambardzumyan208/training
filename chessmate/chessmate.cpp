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
        if (m_matrix[x][y] == "  W.Pawn " &&(( move_x == ++x )||( x == 1 && move_x == x + 2) ||( check_coords(++x,++y) && move_x == ++x && move_y == ++y)))
        {
            swap(m_matrix[move_x][move_y], m_matrix[x][y]);
            m_matrix[x][y] = " _______ ";
        }
        if(m_matrix[x][y] == "W.Knight" && ((move_x == x) || (move_y == y) )){}
        else
        {
            cerr << "Dont Correct move\n";
            throw abort;
        }
    }
    void swap(string& a, string& b)
    {
        string temp = a;
        a = b;
        b = temp;
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
    }
};
int main()
{

    using namespace std::this_thread;
    using namespace std::chrono; 
    Board a;
    a.start();
}

