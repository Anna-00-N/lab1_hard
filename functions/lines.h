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



void circle_points(int flag, double R, double x, double a, double b, double c, double d, double *xc, double *yc){
	double x0 = (a+c)/2, y0 = (b+d)/2, i,j, xc0, yc0;
	
	if((d-b)==0){
		for(j=0; ( sqrt(pow(a-i,2) + pow(b-j,2)) )<R; j+=pow(-1,flag+1)*0.001);
		xc0=x0; yc0=j;
	}
	else{
		for( i=x0, j=y0; ( sqrt(pow(a-i,2) + pow(b-j,2)) )<R; i+=pow(-1,((c-a)/(d-b)>0)?(flag):(flag+1))*0.001)
			j = (i-x0)*(a-c)/(d-b)+y0;
		xc0 = round(i*100)/100; yc0 = (xc0-x0)*(a-c)/(d-b)+y0; 
	}
	*xc = xc0; *yc = yc0;
}

/*
ПОИСК КООРДИНАТЫ У ОТ Х НА ЛИНИИ
flag - часть круга, которую нужно показать относительно оси x: 0 - положительная, 1 - отрицательная
R - радиус круга
x - неизвестная
(a;b), (c;d)  - точки на дуге)*/
double circle_by_points(int flag, double R, double x, double a, double b, double c, double d){
	if(x==a) return b; if(x==c) return d; 
	double xc, yc, res;
	circle_points(flag, R, x, a, b, c, d, &xc, &yc);
	return pow(-1,flag)*sqrt(R*R-pow(x-xc,2))+yc;
}
