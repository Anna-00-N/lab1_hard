#include <string> //строки
#include <sstream> //доп. строковые потоки - чтобы не использовать scrcat для объединения строк
#include <fstream> //для создания файла graphik.m
#include <vector> //вектор ( для передачи my_data() )

//#include "lines.h" 
//функции линия, круг

//#include "split.h" 
//выделение параметров из  текстовой строки из массива данных 

#include "auto_y.h"
// автоматическое определение Y по значению X и массиву данных о линиях 

#include "data.h" 
//массив данных о линиях

#include "mathlabscript.h"
//формирование plot для скрипта matlab, сюда передаются X и найденный Y,  а также значения границ графика


double way1(double X){
	return find_Y(my_data(), X);
}

double way2(double X){
	double Y;
	if(X<=-3){
		Y = line(1, 3, X);
	}
	else if(X<=0){
		Y = circle(0, 3, X);
	}
	else if(X<=6){
		Y = line(-0.5, 0, X, 0, 3);
	}
	else{
		Y = line(1, 0, X, 6, 0);
	}
	return Y;
}


void matlab(double X, double Y, double minx, double maxx, double miny, double maxy){
		//Создание скрипта для matlab(часть записана в mathlabscript.h)
		stringstream s1, s2;
		s1<<"x = ["; s2<<"y = [";
		for(double i=minx;i<=maxx;i+=0.03){ //запись значений x,y, удобнее через стр.потоки
			s1<<i<<" ";
			s2<<find_Y(my_data(), i)<<" ";
			}
		s1<<"];"<<endl; s2<<"];"<<endl;
		///////////////////////////////////////////
		std::ofstream fout("graphik.m"); //запись файла
		fout<<s1.str()<<s2.str()<<script(X,Y,minx,maxx,miny,maxy); 
		fout.close();
		////
		wcout<<L"\nСоздан файл graphik.m со скриптом для Matlab.\n Чтобы открыть его, введите 9999 и выйдите из цикла!\n\n___________________\n";
}