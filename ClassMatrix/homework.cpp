

#include <iostream>
using namespace std;
class class_matrix {
private:
    int m_rows = -1;
    int m_columns = -1;
    int** m_matrix;
public:
<<<<<<< HEAD
    class_matrix() {
        getsize();
        m_matrix = new int* [m_rows];
        for (int i = 0; i < m_rows; i++)
        {
            m_matrix[i] = new int [m_columns];
        }
        cout << "m_matrix was created\n";
    }
    void getsize() {
        while (m_rows <= 0 || m_columns <= 0) {
            cout << "input the m_rows of m_matrix\n";
            cin >> m_rows;
            cout << "input the m_columns of m_matrix\n";
            cin >> m_columns;
        }
    }
=======
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
>>>>>>> 5daf7641e5364c0aef8e850d5400fc0478dc7832
    void init() {
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_columns; j++)
            {
                m_matrix[i][j] = rand() % 100 + 1;
            }
        }
    }
    void display() {
        for (int i = 0; i < m_rows; i++)
        {
            cout << "[";
            for (int j = 0; j < m_columns; j++)
            {
                cout << m_matrix[i][j] << "|";
            }
            cout << "]\n";
        }
    }
    int diagonal() {
        int sum = 0;
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_columns; j++)
            {
                if (i != j && i < j)
                {
                    sum += m_matrix[i][j];
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
    void swpmtx1_3m_rows()
    {
        if (m_rows <= 3)
        {
            std::cout << "m_matrix dont have 3 m_rows";
            return;
        }
        for (int j = 0; j < m_rows; j++)
        {
<<<<<<< HEAD
            swap(&m_matrix[j][1], &m_matrix[j][3]);
        }
=======
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
        delete[] matrix;
        matrix = nullptr;
>>>>>>> 5daf7641e5364c0aef8e850d5400fc0478dc7832
    }
    ~class_matrix() {
        cout << "m_matrix beeing deleted\n";
        for (int i = 0; i < m_rows; i++)
        {
            delete[] m_matrix[i];
            m_matrix[i] = nullptr;
        }
        delete[] m_matrix;
        m_matrix = nullptr;
    }
    void swpmtx1_3cols() {
        if (m_columns <= 3)
        {
            std::cout << "This m_matrix dont have 3 column";
            return;
        }
        for (int j = 0; j < m_columns; j++)
        {
            swap(&m_matrix[1][j], &m_matrix[3][j]);
        }
    }
    class_matrix(class_matrix&& other) : m_rows(other.m_rows), m_columns(other.m_columns), m_matrix(other.m_matrix) {
        other.m_rows = 0;
        other.m_columns = 0;
        other.m_matrix = nullptr;
        std::cout << "Move constructor called\n";
    }

    class_matrix& operator=(class_matrix&& other) {
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
};
int main()
{
    class_matrix newer;
    newer.init();
    class_matrix m_matrix(std::move(class_matrix()));
    cout << "this is default created m_matrix\n";
    m_matrix.display();
    cout << "the sum of m_matrix diagonal\n" << m_matrix.diagonal() << endl;
    m_matrix.swpmtx1_3cols();
    cout << "The swapped m_matrix(cols)\n";
    m_matrix.display();
    cout << "The swapped m_matrix(m_rows)\n";
    m_matrix.swpmtx1_3m_rows();
    m_matrix.display();
}

