#include <fstream>
#include <iostream>
using namespace std;
ofstream outFile("output.txt",ios::out);
template<typename Type>
class class_matrix {
private:
    char c;
    size_t m_rows = -1;
    size_t m_columns = -1;
    Type** m_matrix = nullptr;
public:
    class_matrix(int m_rows,int m_cols): m_rows(m_rows),m_columns(m_cols) {
        m_matrix = new Type* [m_rows];
        for (int i = 0; i < m_rows; i++)
        {
            m_matrix[i] = new Type [m_columns];
        }
        outFile << "m_matrix was created\n";
    }
    void init() {
        int count;
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_columns; j++)
            {
                m_matrix[i][j] = rand() % 10 + 1;
            }
        }
    }
    void display() {
        for (int i = 0; i < m_rows; i++)
        {
            outFile << "[";
            for (int j = 0; j < m_columns; j++)
            {
                outFile << m_matrix[i][j] << "|";
            }
            outFile << "]\n";
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
        if (m_rows < 2)
        {
            outFile << "m_matrix dont have 3 m_rows";
            return;
        }
        for (int j = 0; j < m_rows; j++)
        {
            swap(&m_matrix[j][0], &m_matrix[j][2]);
        }
    }
    ~class_matrix() {
        outFile << "m_matrix beeing deleted\n";
        for (int i = 0; i < m_rows; i++)
        {
            delete[] m_matrix[i];
            m_matrix[i] = nullptr;
        }
        delete[] m_matrix;
        m_matrix = nullptr;
    }
    void swpmtx1_3cols() {
        if (m_columns < 2)
        {
            outFile << "This m_matrix dont have 3 column";
            return;
        }
        for (int j = 0; j < m_columns; j++)
        {
            swap(&m_matrix[0][j], &m_matrix[2][j]);
        }
    }
    class_matrix(class_matrix&& other) : m_rows(other.m_rows), m_columns(other.m_columns), m_matrix(other.m_matrix) {
        other.m_rows = 0;
        other.m_columns = 0;
        other.m_matrix = nullptr;
        outFile << "Move constructor called\n";
    }
    class_matrix(const class_matrix& other) : m_rows(other.m_rows),m_columns(other.m_columns){
         m_matrix = new Type*[m_rows];
         for(int i = 0;i < m_rows;++i)
             {
                 m_matrix[i] = new Type[m_columns];
             }
        for(int i = 0;i < m_rows; ++i)
            {
             for(int j = 0; j < m_columns; j++)
                 {
                     m_matrix[i][j] = other.m_matrix[i][j];
                 }
            }
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
        outFile << "Move assignment operator called\n";
        return *this;
    }
};
int main()
{
    class_matrix<int> newer(3,3);
    newer.init();
    class_matrix<int> m_matrix(move(newer));
    outFile << "this is default created m_matrix\n";
    m_matrix.display();
    outFile << "the sum of m_matrix diagonal\n" << m_matrix.diagonal() << endl;
    m_matrix.swpmtx1_3cols();
    outFile << "The swapped m_matrix(cols)\n";
    m_matrix.display();
    outFile << "The swapped m_matrix(m_rows)\n";
    m_matrix.swpmtx1_3m_rows();
    m_matrix.display();
    outFile.close();
}

