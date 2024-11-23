#include "pixel.h"
#include "draw_line.h"

void drawLine(Mat& image, Point start, Point end, string color)
{
    int x = start.x;
    int y = start.y;
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int ix, iy;
    int e;
    int i;


    if (dx > 0)
    {
        ix = 1;
    }
    else
    {
        if (dx < 0)
        {
            ix = -1;
            dx = -dx;
        }
        else
        {
            ix = 0;
        }
    }

    if (dy > 0)
    {
        iy = 1;
    }
    else
    {
        if (dy < 0)
        {
            iy = -1;
            dy = -dy;
        }
        else
        {
            iy = 0;
        }
    }

    if (dx >= dy)
    {
        e = 2 * dy - dx; //инициализация ошибки с поправкой на половину пиксела
        if (iy >= 0)
        { //увеличиваем или не изменяем y
            //основной цикл
            for (i = 0; i <= dx; i++)
            {
                outputPixel(image, x, y, color);
                if (e >= 0)
                { //ошибка стала неотрицательной
                    y += iy; //изменяем y
                    e -= 2 * dx; //уменьшаем ошибку
                }
                x += ix; //всегда изменяем x
                e += dy * 2; //и увеличиваем ошибку
            }
        }
        else
        { //y уменьшается
            for (i = 0; i <= dx; i++)
            {
                outputPixel(image, x, y, color);
                if (e > 0)
                { // ошибка стала положительной. Условие изменилось с >= на >
                    y += iy;
                    e -= 2 * dx;
                }
                x += ix;
                e += dy * 2;
            }
        }
    }
    else //dy>dx
    {
        e = 2 * dx - dy; //инициализация ошибки с поправкой на половину пиксела
        if (ix >= 0)
        { //увеличиваем или не изменяем y
            //основной цикл
            for (i = 0; i <= dy; i++)
            {
                outputPixel(image, x, y, color);
                if (e >= 0)
                { //ошибка стала неотрицательной
                    x += ix; //изменяем y
                    e -= 2 * dy; //уменьшаем ошибку
                }
                y += iy; //всегда изменяем x
                e += dx * 2; //и увеличиваем ошибку
            }
        }
        else
        { //y уменьшается
            for (i = 0; i <= dy; i++)
            {
                outputPixel(image, x, y, color);
                if (e > 0)
                { // ошибка стала положительной. Условие изменилось с >= на >
                    x += ix;
                    e -= 2 * dy;
                }
                y += iy;
                e += dx * 2;
            }
        }

    }
}