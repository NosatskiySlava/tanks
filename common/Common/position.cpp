#include "position.h"

Position::Position(int i_x, int i_y)
    : x(i_x)
    , y(i_y)
{

}

bool operator==(const Position &lhs, const Position &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator !=(const Position &lhs, const Position &rhs) {
    return !operator==(lhs, rhs);
}

Position operator+(const Position& lhs, const Position& rhs) {
    return Position(lhs.x + rhs.x, lhs.y + rhs.y);
}

Position operator-(const Position& lhs, const Position& rhs) {
    return Position(lhs.x - rhs.x, lhs.y - rhs.y);
}
