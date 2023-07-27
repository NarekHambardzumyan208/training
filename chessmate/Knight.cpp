#include "Chess_Board.h"
#include "Knight.h"
class Knight{
public:
	static void Move_Knight(){
           if (m_matrix[x][y] == " W.Knight "&& ((move_x == 1 + x && move_y == y + 2) || (move_y == 1 + y && move_x == x + 2) || (y - 2 > -1 && move_x == 1 + x && move_y == y - 2) || (y - 1 > -1 && move_y == y - 1 && move_x == x + 2) || (y - 2 > -1 && x - 1 > -1 && move_x == x - 1 && move_y == y - 2) || (x - 1 > -1 && move_y == y + 2 && move_x == x - 1) || (y - 1 >= 0 && x - 2 >= 0 && move_y == y - 1 && move_x == x - 2) || (y + 1 >= 0 && x - 2 >= 0 && move_y == y + 1 && move_x == x - 2)))
           {
               swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
               x = -1;
               y = -1;
               move_x = -1;
               move_y = -1;
           }
           else if (m_matrix[x][y] == " B.Knight " && ((move_x == 1 + x && move_y == y + 2) || (move_y == 1 + y && move_x == x + 2) || (y - 2 > -1 && move_x == 1 + x && move_y == y - 2) || (y - 1 > -1 && move_y == y - 1 && move_x == x + 2) || (y - 2 > -1 && x - 1 > -1 && move_x == x - 1 && move_y == y - 2) || (x - 1 > -1 && move_y == y + 2 && move_x == x - 1) || (y - 1 >= 0 && x - 2 >= 0 && move_y == y - 1 && move_x == x - 2) || (y + 1 >= 0 && x - 2 >= 0 && move_y == y + 1 && move_x == x - 2)))
           {
               swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
               x = -1;
               y = -1;
               move_x = -1;
               move_y = -1;
           }
           else {
               cerr << "Your Knight want to do illegal move\n";
           }
	}
};