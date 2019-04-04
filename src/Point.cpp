#include "Point.h"


void Point::gotoxy(int x, int y)
{
	COORD Pos = {x, y}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Point::gotoxy(Point pos)
{
	gotoxy(pos.getX(), pos.getY());
}

Point Point::GetScrPosFromCurPos(Point &pos) // �迭��ǥ�� ȭ����ǥ�� �����´�.
{
	pos.setX(2 * pos.m_x + 2);
	pos.setY(pos.m_y + 1);
}