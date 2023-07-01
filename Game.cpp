#include <iostream>
using namespace std;
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
    void checkwinnercolumns(){

        if ((matrix[0][0]) == *("X") && matrix[1][0] == *("X") && matrix[2][0] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[0][1]) == *("X") && matrix[1][1] == *("X") && matrix[2][1] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[0][2]) == *("X") && matrix[1][2] == *("X") && matrix[2][2] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        if ((matrix[0][0]) == *("O") && matrix[1][0] == *("O") && matrix[2][0] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[0][1]) == *("O") && matrix[1][1] == *("O") && matrix[2][1] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[0][2]) == *("O") && matrix[1][2] == *("O") && matrix[2][2] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
    
    
    
    
    }
    void checkwinnerrows() {
        if ((matrix[0][0]) == *("X") && matrix[0][1] == *("X") && matrix[0][2] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[1][0]) == *("X") && matrix[1][1] == *("X") && matrix[1][2] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[2][0]) == *("X") && matrix[2][1] == *("X") && matrix[2][2] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }

        if ((matrix[0][0]) == *("O") && matrix[0][1] == *("O") && matrix[0][2] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[1][0]) == *("O") && matrix[1][1] == *("O") && matrix[1][2] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        else if ((matrix[2][0]) == *("O") && matrix[2][1] == *("O") && matrix[2][2] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
    }
    void checkwinnerdiagonal() {
        if ((matrix[0][0]) == *("X") && matrix[1][1] == *("X") && matrix[2][2] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        if ((matrix[0][2]) == *("X") && matrix[1][1] == *("X") && matrix[2][0] == *("X")) {
            cout << "\nHey who played for X You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        if ((matrix[0][0]) == *("O") && matrix[1][1] == *("O") && matrix[2][2] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
   
           
     
 
        }
        if ((matrix[0][2]) == *("O") && matrix[1][1] == *("O") && matrix[2][0] == *("O")) {
            cout << "\nHey who played for O You win\n";
            std::cout << "   __     ______  _    _ _   _ _     _\n"
                "   \\ \\   / / __ \\| |  | | \\ | | |   (_)\n"
                "    \\ \\_/ / |  | | |  | |  \\| | |    _ _ __ ___   __ _ _ __\n"
                "     \\   /| |  | | |  | | . ` | |   | | '_ ` _ \\ / _` | '_ \\\n"
                "      | | | |__| | |__| | |\\  | |___| | | | | | | (_| | | | |\n"
                "      |_|  \\____/ \\____/|_| \\_|_____|_|_| |_| |_|\\__,_|_| |_|\n" << std::endl;
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
        for (int i = 0; i < rows; i++)
        {
            short a = i;
            cout << ++a << " / [";
            for (int j = 0; j < columns; j++)
            {
                cout << matrix[i][j] << " | ";
            }
            cout << "]\n";
        }
    }
    void InputX() {
        int i;
        int j;
        cin >> i;
        cin >> j;
        --i;
        --j;
        if (2 < i || 2 < j)
        {
            cerr << "The inputed number cant be a bigger than three\n";
            throw abort;
             
        }
            while (matrix[i][j] == *("X") || matrix[i][j] == *("O"))
            {
                cerr << "You Cant Place above other played location\n";
                cin >> i;
                cin >> j;
                --i;
                --j;
                if (2 < i || 2 < j)
                {
                    cerr << "The inputed number cant be a bigger than three\n";
                    throw abort;
                }
            }
        matrix[i][j] = *("X");
    }
    void InputO() {
        int i;
        int j;
        cin >> i;
        cin >> j;
        --i;
        --j;
        if (2 < i || 2 < j)
        {
            cerr << "The inputed number cant be a bigger than three\n";
            throw abort;

        }
        while (matrix[i][j] == *("X") || matrix[i][j] == *("O"))
        {
            cerr << "You Cant Place above other played location\n";
            cin >> i;
            cin >> j;
            --i;
            --j;
            if (2 < i || 2 < j)
            {
                cerr << "The inputed number cant be a bigger than three\n";
                throw abort;
            }
        }
        matrix[i][j] = *("O");
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
