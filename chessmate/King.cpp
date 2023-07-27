#include "King.h"
#include "Chess_Board.h"
class King {
public:
	static void Move_King() {
          else if (m_matrix[x][y] == " W.King " && ((x != 7 && move_x == x + 1) && (x != 0 && move_x == x - 1) && (y != 7 && move_y == y + 1) && (y != 0 && move_y == y + 1) && (x + 1 != 8 && y + 1 != 8 && move_x == x + 1 && move_y == y + 1) && (x + 1 != 8 && y - 1 != -1 && move_x == x + 1 && move_y == y - 1)
              && (x - 1 != -1 && y - 1 != -1 && move_x == x - 1 && move_y == y - 1) && (x - 1 != -1 && y + 1 != 8 && move_x == x - 1 && move_y == y + 1)))
              {
                  swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                  x = -1;
                  y = -1;
                  move_x = -1;
                  move_y = -1;
              }
              else if (m_matrix[x][y] == " B.King " && ((x != 7 && move_x == x + 1) && (x != 0 && move_x == x - 1) && (y != 7 && move_y == y + 1) && (y != 0 && move_y == y + 1) && (x + 1 != 8 && y + 1 != 8 && move_x == x + 1 && move_y == y + 1) && (x + 1 != 8 && y - 1 != -1 && move_x == x + 1 && move_y == y - 1)
              && (x - 1 != -1 && y - 1 != -1 && move_x == x - 1 && move_y == y - 1) && (x - 1 != -1 && y + 1 != 8 && move_x == x - 1 && move_y == y + 1)))
              {
                  swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
                  x = -1;
                  y = -1;
                  move_x = -1;
                  move_y = -1;
              }
	}
    void King::Check_mate()
    {
    }
    static void Check_Mate() {

    }
};