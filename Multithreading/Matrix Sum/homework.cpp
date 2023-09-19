#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;
mutex  mtx;
template<typename Type>
class class_matrix {
private:
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
        cout << "m_matrix was created\n";
    }
    int sum()
    {
        int sum = 0;
        vector<thread> thread_vec;
        for (size_t i = 0; i < m_rows; i++)
        {
            thread_vec.push_back(thread([&, i]() { 
                int local_sum = 0; 
            for (int j = 0; j < m_columns; j++) {
                mtx.lock();
                local_sum += m_matrix[i][j];
                mtx.unlock();
            }
            mtx.lock();
            sum += local_sum; 
            mtx.unlock();
                }));
        }
        for (size_t i = 0; i < m_rows; i++)
        {
            thread_vec[i].join();
        }

        return sum;
    }

    void init() {
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
        if (m_rows < 2)
        {
            cout << "m_matrix dont have 3 m_rows";
            return;
        }
        for (int j = 0; j < m_rows; j++)
        {
            swap(&m_matrix[j][0], &m_matrix[j][2]);
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
        if (m_columns < 2)
        {
            cout << "This m_matrix dont have 3 column";
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
        cout << "Move constructor called\n";
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
        cout << "Move assignment operator called\n";
        return *this;
    }
};
int main()
{
    
    class_matrix<int> m_matrix(3, 3);
    m_matrix.init();
        cout << "this is default created m_matrix\n";
        m_matrix.display();
        cout << "The sum of the matrix(all)\n";
        cout << m_matrix.sum();
    

    return 0;
}
