#ifndef POSTION_H
#define POSTION_H

struct Position {
    Position(int i_x = 0, int i_y = 0);
    int x;
    int y;
};

bool operator==(const Position& lhs, const Position& rhs);
bool operator!=(const Position& lhs, const Position& rhs);
Position operator+(const Position& lhs, const Position& rhs);
Position operator-(const Position& lhs, const Position& rhs);

#endif // POSTION_H

