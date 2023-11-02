#include <vector>
#include <string>
#include <sstream>

#include "lines.h"
#include "split.h" 




double find_Y(std::vector<std::string> v, double X, string r_vars){ //находит Y
	//r_vars - строка со значениями R для круга
	string *data = v.data();
	double len = v.size();  //определить длину вектора, т.е., уже и массива
	double Y;
	int flag = 0;//если X оказалось меньше before_x, то дальше цикл остановится
	double before_x; //параметр, до какого максимального числа по оси Х действует функция
	int tip; //0 - прямая, 1 - круг, можно добавить, добавив функцию в lines.h, и определение типа в split.h
	double par1, par2, par3, par4, par5; //параметры - k/половина круга по y, m/R, сдвиги по х и по у
	string text; //для выбора строка
	double R=0; int f; 
	string d;

	int tnum=0;
	for (int i=0;  i<len; i++){ 
		text=data[i];
		stringstream s(text);
		s>>d;
		if(d=="N"||atof(d.c_str())>=X) break;
		tnum++;
	}

	text=data[tnum];
	f=0; 
	text_to_params(text, &before_x, &tip, &par1, &par2, &par3, &par4, &par5, r_vars, &R, &f);//выполняем функцию из split.h

	switch(tip){
		case 0: 
			Y = line(par1, par2, X, par3, par4);
		break;
		case 1: 
			Y = circle_by_points(par1, (f==1)?(R):(par2), X, par3, par4, before_x, par5);
		break;
		//можно добавить еще функции
		}
	flag=1;

	//delete []data;
	return Y;
}




void find_points(std::vector<std::string> v, double X, string r_vars, double *x0, double *y0){ //находит середину текущего круга
	//r_vars - строка со значениями R для круга
	string *data = v.data();
	double len = v.size();  //определить длину вектора, т.е., уже и массива
	double Y;
	int flag = 0;//если X оказалось меньше before_x, то дальше цикл остановится
	double before_x; //параметр, до какого максимального числа по оси Х действует функция
	int tip; //0 - прямая, 1 - круг, можно добавить, добавив функцию в lines.h, и определение типа в split.h
	double par1, par2, par3, par4, par5; //параметры - k/половина круга по y, m/R, сдвиги по х и по у
	string text; //для выбора строка
	double R=0; int f; 
	string d;
	double xc,  yc;

	int tnum=0;
	for (int i=0;  i<len; i++){ 
		text=data[i];
		stringstream s(text);
		s>>d;
		if(d=="N"||atof(d.c_str())>=X) break;
		tnum++;
	}

	text=data[tnum];
	f=0; 
	text_to_params(text, &before_x, &tip, &par1, &par2, &par3, &par4, &par5, r_vars, &R, &f);//выполняем функцию из split.h

	switch(tip){
		case 1: 
			circle_points(par1, (f==1)?(R):(par2), X, par3, par4, before_x, par5, &xc, &yc);
		break;
		}
	flag=1;

	*x0 = xc; *y0 = yc;
	//delete []data;
}