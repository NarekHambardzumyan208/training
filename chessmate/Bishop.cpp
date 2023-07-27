#include "Bishop.h"
#include "Chess_Board.h"
class Bishop{
public:
	static void Move_Bishop() {
         else if (m_matrix[x][y] == " W.Bishop " || m_matrix[x][y] == " B.Bishop ")
         {
             int lim_x = 8, lim_y = 8;
             if (move_x > x && move_y > y)
             {
                 for (int i = x + 1, j = y + 1; i < 8 && j < 8; ++i, ++j) {
                     if (m_matrix[i][j] != " _______ ") {
                         lim_x = i;
                         lim_y = j;
                         break;
                     }
                 }
                 for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
                 {
                     if (move_x <= lim_x && move_y <= lim_y && move_x == x + i && move_y == y + j || lim_x == 8 && lim_y == 8 && move_x == x + i && move_y == y + j)
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
                 for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; --i, --j) {
                     if (m_matrix[i][j] != " _______ ") {
                         lim_x = i;
                         lim_y = j;
                         break;
                     }
                 }
                 for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
                 {
                     if (move_x >= lim_x && move_y >= lim_y && move_x == x - i && move_y == y - j || lim_x == 8 && lim_y == 8 && move_x == x - i && move_y == y - j)
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
                 for (int i = x - 1, j = y + 1; i >= 0 && j < 8; --i, ++j) {
                     if (m_matrix[i][j] != " _______ ") {
                         lim_x = i;
                         lim_y = j;
                         break;
                     }
                 }
                 for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
                 {
                     if (move_x >= lim_x && move_y <= lim_y && move_x == x - i && move_y == y + j || lim_x == 8 && lim_y == 8 && move_x == x - i && move_y == y + j)
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
                 for (int i = x + 1, j = y - 1; i < 8 && j >= 0; ++i, --j) {
                     if (m_matrix[i][j] != " _______ ") {
                         lim_x = i;
                         lim_y = j;
                         break;
                     }
                 }
                 for (int i = 0, j = 0; i < 8 && j < 8; ++i, ++j)
                 {
                     if (move_x <= lim_x && move_y >= lim_y && move_x == x + i && move_y == y - j || lim_x == 8 && lim_y == 8 && move_x == x + i && move_y == y - j)
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
                 cerr << "Your bishop want to do illegal move\n";
                 throw abort;
             }
        }
	};
};