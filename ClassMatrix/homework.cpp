

#include <iostream>
using namespace std;
class clsmatrix {
private:
    int rows = -1;
    int columns = -1;
    int** matrix;
public:
    clsmatrix() {
        getsize();
        matrix = new int**[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int*[columns];
        }
        cout << "matrix was created\n";
    }
    void getsize(){        while (rows <= 0 || columns <= 0){
            cout << "input the rows of matrix\n";
        cin >> rows;
        cout << "input the columns of matrix\n";
        cin >> columns;
    }}
    void init() {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = rand() % 100 + 1;
            }
        }
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
    void swpmtx1_3rows()
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
    ~clsmatrix() {
        cout << "Matrix beeing deleted\n";
        for (int i = 0; i < rows; i++)
        {
            free(matrix[i]);
            matrix[i] = nullptr;
        }
        free(matrix);
        matrix = nullptr;
    }
    void swpmtx1_3cols(){
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
    clsmatrix(clsmatrix&& other): rows(other.rows), columns(other.columns), matrix(other.matrix) {
        other.rows = 0;
        other.columns = 0;
        other.matrix = nullptr;
        std::cout << "Move constructor called\n";
    }

    clsmatrix& operator=(clsmatrix&& other)  {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;

            rows = other.rows;
            columns = other.columns;
            matrix = other.matrix;

            other.rows = 0;
            other.columns = 0;
            other.matrix = nullptr;
        }
        std::cout << "Move assignment operator called\n";
        return *this;
    }
};
int main()
{
    cout << "Hello world";
    clsmatrix newer;
    newer.init();
    clsmatrix matrix(std::move(clsmatrix()));
    cout << "this is default created matrix\n";
    matrix.display();
    cout << "the sum of matrix diagonal\n" <<matrix.diagonal() << endl;
    matrix.swpmtx1_3cols();
    cout << "The swapped matrix(cols)\n";
    matrix.display();
    cout << "The swapped matrix(rows)\n";
    matrix.swpmtx1_3rows();
    matrix.display();
}

