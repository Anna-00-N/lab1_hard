#include <vector>
#include <string>

#include "lines.h"
#include "split.h"


double find_Y(std::vector<std::string> v, double X){
	string *data = v.data();
	double len = v.size();  //определить длину вектора, т.е., уже и массива
	double Y;
	int flag = 0;//если X оказалось меньше before_x, то дальше цикл остановится
	double before_x; //параметр, до какого максимального числа по оси Х действует функция
	int tip; //0 - прямая, 1 - круг, можно добавить, добавив функцию в lines.h, и определение типа в split.h
	double par1, par2, par3, par4; //параметры - k/половина круга по y, m/R, сдвиги по х и по у
	string text; //для выбора строка
	for (int i=0;  i<len; i++){ 
		text=data[i];
		text_to_params(text, &before_x, &tip, &par1, &par2, &par3, &par4);//выполняем функцию из split.h
		//если х меньше наибольшего на заданном промежутке
		if(X <= before_x||before_x==999999){
			switch(tip){
				case 0: Y = line(par1, par2, X, par3, par4);break;
				case 1: Y = circle(par1, par2, X, par3, par4); break;
				//можно добавить еще функции
				}
				flag=1;
		}
		if(flag==1) break; //прерывание цикла
	}

	//delete []data;
	return Y;
}