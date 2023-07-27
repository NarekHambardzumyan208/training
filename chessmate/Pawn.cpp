#include "Pawn.h"
#include "Chess_Board.h"
class Pawn {
public:
	static void Move_Pawn() {
        if (m_matrix[x][y] == "  W.Pawn " && ((x + 1 != 8 && y + 1 != 8 && check_coords(1 + x, 1 + y) && move_x == 1 + x && move_y == 1 + y) || (x == 1 && move_x == x + 2 && move_y == y) || (x + 1 != 8 && move_x == x + 1) || (x + 1 != 8 && y - 1 != 0 && check_coords(1 + x, y - 1) && move_x == 1 + x && move_y == y - 1)))
        {
            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
            x = -1;
            y = -1;
            move_x = -1;
            move_y = -1;
        }
        if (m_matrix[x][y] == "  B.Pawn " && ((x + 1 != 8 && y + 1 != 8 && check_coords(1 + x, 1 + y) && move_x == 1 + x && move_y == 1 + y) || (x == 1 && move_x == x + 2 && move_y == y) || (x + 1 != 8 && move_x == x + 1) || (x + 1 != 8 && y - 1 != 0 && check_coords(1 + x, y - 1) && move_x == 1 + x && move_y == y - 1)))
        {
            swap(&m_matrix[move_x][move_y], &m_matrix[x][y]);
            x = -1;
            y = -1;
            move_x = -1;
            move_y = -1;
        }
        
	}
    static void Cast_Pawn(){}
};
