#include <iostream>
using namespace std;
class matrixclass {
private:
    int rows = -1;
    int columns = -1;
    int** matrix;
public:
    void inputsize()
    {
        while (rows <= 0 || columns <= 0) {
            cout << "input the rows of matrix\n";
            cin >> rows;
            cout << "input the columns of matrix\n";
            cin >> columns;
        }
    }
    void creatematrix()
    {
        matrix = (int**)malloc(sizeof(int*) * rows);
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = (int*)malloc(sizeof(int) * columns);
        }
    }
    matrixclass() {
        cout << "matrix class was created\n";
    }
    void init() {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = rand() % 100 + 1;
            }
        }
    }
    matrixclass(const matrixclass&obj) {
        rows = obj.rows;
        columns = obj.columns; 
        matrix = (int**)malloc(sizeof(int*)*rows);
        for (int i = 0; i < rows; i++) {
            matrix[i] = (int*)malloc(sizeof(int)*columns);
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = obj.matrix[i][j];
            }
        }
    }
    matrixclass& operator=(const matrixclass& obj)
    {
        
        if (this != &obj)
        {
            for (int i = 0; i < rows; i++)
            {
                free(matrix[i]);
                matrix[i] = nullptr;
            }
            free(matrix);
            matrix = nullptr;
            rows = obj.rows;
            columns = obj.columns;
            matrix = (int**)malloc(sizeof(int*) * rows);
            for (int i = 0; i < rows; i++)
            {
                matrix[i] = (int*)malloc(sizeof(int) * columns);
                for (int j = 0; j < columns; j++)
                {
                    matrix[i][j] = obj.matrix[i][j];
                }
            }
        }
         return *this;
    }

    void display() {
        for (int i = 0; i < rows; i++)
        {
            cout << "[";
            for (int j = 0; j < columns; j++)
            {
                cout << matrix[i][j] << "|";
            }
            cout << "]\n";
        }
    }
    int diagonal() {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if ( i != j && i < j)
                {
                    sum += matrix[i][j];
                }
            }
        }
        return sum;
    }
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void swpmtx1_3(string condition)
    {
        if (condition == "rows" || condition == "Rows")
        {
            if (rows <= 3)
            {
                std::cout << "matrix dont have 3 rows";
                return;
            }
            for (int j = 0; j < rows; j++)
            {
                swap(&matrix[j][1], &matrix[j][3]);
            }
        }
        else
        {

            if (columns <= 3)
            {
                std::cout << "This matrix dont have 3 column";
                return;
            }
            for (int j = 0; j < columns; j++)
            {
                swap(&matrix[1][j], &matrix[3][j]);
            }
        }
    }
    ~matrixclass() {
        cout << "Matrix beeing deleted\n";
        for (int i = 0; i < rows; i++)
        {
            free(matrix[i]);
            matrix[i] = nullptr;
        }
        free(matrix);
        matrix = nullptr;
    }
};
int main()
{
    
    matrixclass matrix;
    matrix.inputsize();
    matrix.creatematrix();
    matrix.init();
    cout << "this is default created matrix\n";
    matrix.display();
    cout << "the sum of matrix diagonal\n" <<matrix.diagonal() << endl;
    matrix.swpmtx1_3("cols");
    cout << "The swapped matrix(cols)\n";
    matrix.display();
    cout << "The swapped matrix(rows)\n";
    matrix.swpmtx1_3("rows");
    matrix.display();
}

