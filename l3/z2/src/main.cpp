#include <stdio.h>
#include <cmath>

#define START 0
#define DOWN -5
#define UP 3
#define STEP 0.2
#define Y(i) 2.1 * cos(2 * i)
#define dY(i) -4.2 * sin(2 * i)

float foo(float k, float i, float max);
float foundMax(int down, int up, float step);

int main()
{

    float max = foundMax(DOWN, UP, 0.1);
    float k = START;
    float k2 = START;
    float i = DOWN;
    int iter = 0;
    while (i <= UP)
    {
        i += STEP;
        k = foo(k, i, max);
        if (k != k2)
        {
            k2 = k;
            iter++;
        }
    }
    printf("%.2f, %.2f\n", k, k / iter);
    return 0;
}

float foo(float k, float i, float max)
{
    float y = Y(i);
    if (y > max / 3)
        return k + y;
    else
        return k;
}

float foundMax(int down, int up, float step)
{
    float i = down;
    float max = Y(i);
    float dy = dY(i);
    while (i != up)
    {
        i += step;
        dy -= dY(i);
        if (dy > 0)
            max = Y(i);
        if (dy - dY(i + step) < 0)
            break;
    }
    return max;
}