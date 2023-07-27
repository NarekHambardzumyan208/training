#include "Rook.h"
#include "Chess_Board.h"
class Rook {
public:
	static void Move_Rook() {
           else if (m_matrix[x][y] == " W.Rook " || m_matrix[x][y] == " B.Rook ")
           {
               int j = 20;
               if (move_x == x && move_y > y)
               {
                   for (int i = y + 1; i <= move_y; i++)
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
	}
};