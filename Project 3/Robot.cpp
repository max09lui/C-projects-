#include <iostream>
#include <cmath>
#include "Arena.h"
#include "Robot.h"
#include "Globals.h"
using namespace std;
Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "A robot must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
    {
        cout << "Robot created with invalid coordinates (" << r << ","
            << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_health = 2;
}

int Robot::row() const
{
    return m_row;
}

int Robot::col() const
{
    return m_col;
}

void Robot::move()
{
    switch (rand() % 4)
    {
    case UP:
        if (m_row - 1 > 0 && m_row - 1 <= m_arena->rows())
        {
            m_row--;
        }
        break;
    case DOWN:
        if (m_row + 1 > 0 && m_row + 1 <= m_arena->rows())
        {
            m_row++;
        }
        break;
    case LEFT:
        if (m_col - 1 > 0 && m_col - 1 <= m_arena->cols())
        {
            m_col--;
        }
        break;

    case RIGHT:
        if (m_col + 1 > 0 && m_col + 1 <= m_arena->cols())
        {
            m_col++;
        }
        break;
    }
}

bool Robot::takeDamageAndLive()
{
    m_health--;
    if (m_health <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}