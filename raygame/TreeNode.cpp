#include "TreeNode.h"
#include <stdio.h>
#include "raylib.h"

void TreeNode::draw(int x, int y, bool selected)
{
	static char buffer[10];
	sprintf_s(buffer, "%d", m_value);
	DrawCircle(x, y, 30, YELLOW);

	if (selected) {
		DrawCircle(x, y, 28, BROWN);
	}
	else {
		DrawCircle(x, y, 28, BLACK);
	}

	DrawText(buffer, x - 12, y - 10, 20, WHITE);
}