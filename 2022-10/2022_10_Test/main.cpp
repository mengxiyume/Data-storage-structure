#define _CRT_SECURE_NO_WARNINGS

#include<graphics.h>
#include<Windows.h>
#include<math.h>

#define PI 3.1415926

#define HEIGHT 800
#define WIDTH 800

int drawCircle(float x, float y, float r, int n)
{
	float angle = 0;
	circle(x, y, r);

	if (n / r > 1)
	{
		return 0;
	}

	for (angle = -0.5 * PI; angle < 1.5 * PI + 0.01; angle = angle + 2 * PI / n)
	{
		double xs = x + 2 * r * cos(angle);
		double ys = y + 2 * r * sin(angle);
		drawCircle(xs, ys, 0.5 * r, n);
	}
}

int main()
{
	initgraph(WIDTH, HEIGHT);
	setbkcolor(0xFFFFFF);
	cleardevice();
	setlinecolor(0x000000);

	drawCircle(WIDTH / 2, HEIGHT / 2, 100, 100);

	system("pause");
	return 0;
}