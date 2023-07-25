

#include <iostream>
using namespace std;
template<typename Type>
class class_matrix {
private:
    size_t m_rows = -1;
    size_t m_columns = -1;
    Type** m_matrix;
public:
    class_matrix() {
        getsize();
        m_matrix = new Type* [m_rows];
        for (int i = 0; i < m_rows; i++)
        {
            m_matrix[i] = new Type [m_columns];
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
    Type diagonal() {
        Type sum = 0;
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
    void swap(Type* a, Type* b)
    {
        Type temp = *a;
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
            swap(&m_matrix[j][1], &m_matrix[j][3]);
        }
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
    class_matrix<int> newer;
    newer.init();
    class_matrix<int> m_matrix(std::move(class_matrix<int>()));
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

