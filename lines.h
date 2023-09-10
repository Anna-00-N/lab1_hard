#include <math.h>
/*
ПОИСК КООРДИНАТЫ У ОТ Х НА ЛИНИИ
k, m - коээффициенты уравнения прямой kx+m
x - неизвестная
x_sdvig, y_sdvig - сдвиги от начала координат по х и y, их можно указать вместо m*/
double line(double k, double m, double x, double x_sdvig=0, double y_sdvig=0)
{
	return (k*(x-x_sdvig)+m+y_sdvig);
}


/*
ПОИСК КООРДИНАТЫ У ОТ Х НА ЛИНИИ
flag - часть круга, которую нужно показать относительно оси x: 0 - положительная, 1 - отрицательная
R - радиус круга
x - неизвестная
x_sdvig, y_sdvig - сдвиги от начала координат по х и y*/
double circle(int flag, double R, double x, double x_sdvig=0, double y_sdvig=0)
{
	int half = (flag==0)?(1):(-1);
	double sqrR = R*R-(x-x_sdvig)*(x-x_sdvig);
	return (sqrR<0)?(NAN):(half*sqrt(sqrR)+y_sdvig);
}
