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

#include "../data.h" 
//массив данных о линиях

#include "mathlabscript.h"
//формирование plot для скрипта matlab, сюда передаются X и найденный Y,  а также значения границ графика


double way1(double X, string r_vars){
	return find_Y(my_data(), X, r_vars);
}



void matlab2(double X, double Y, double minx, double maxx, double miny, double maxy, string r_vars, std::vector<std::string> v){
		//Создание скрипта для matlab(часть записана в mathlabscript.h)
		string *data = v.data(); string d; double maxx0, minx0=minx;
		double len = v.size();  //определить длину вектора, т.е., уже и массива
		stringstream main;
		stringstream s1, s2; string text;
		double xc, yc, k1, k2; int j,m=1;

		for (j=0;  j<len; j++){ 
			text = data[j];
			stringstream s(text);
			s>>d;
			if(d!="N") maxx0=atof(d.c_str()); else maxx0=maxx; //определяется максимум
			s>>d; 

			if(d=="circle"){ //обозначаются линии к центру кругов
				 find_points(my_data(), (maxx0+minx0)/2, r_vars, &xc, &yc);
				 s1<<"m"<<m<<"= ["<<minx0<<" "<<xc<<"]; "<<"t"<<m<<"= ["<<way1(minx0, r_vars)<<" "<<yc<<"]; "<<endl;
				 s1<<"m"<<m+1<<"= ["<<xc<<" "<<maxx0<<"]; "<<"t"<<m+1<<"= ["<<yc<<" "<<way1(maxx0, r_vars)<<"]; "<<endl;
				 m+=2;
			}
		
			s1<<"x"<<j+1<<" = ["; s2<<"y"<<j+1<<" = [";
			for(double i=minx0;i<=maxx0;i+=0.01){ //запись значений x,y, удобнее через стр.потоки
				s1<<i<<" ";
				s2<<way1(i, r_vars)<<" ";
			}
			s1<<maxx0; s2<<way1(maxx0, r_vars);
			s1<<"];"<<endl; s2<<"];"<<endl;

			minx0=maxx0+0.00001; //если не будет не будет разрыва
		}

		std::ofstream fout("graphik.m"); //запись файла
		fout<<s1.str()<<s2.str()<<script(X,Y,minx,maxx,miny,maxy, j, m-1); 
		fout.close();
		wcout<<L"\nСоздан файл graphik.m со скриптом для Matlab.\n Чтобы открыть его, введите 9999 и выйдите из цикла!\n\n___________________\n";
}


void matlab(double X, double Y, double minx, double maxx, double miny, double maxy, string r_vars){
	matlab2(X, Y, minx, maxx, miny, maxy, r_vars, my_data());
}


int r_kolvo(){ //возвращает количество R
    std::vector<std::string> v = my_data();
	string *data = v.data();
	double len = v.size();  //определить длину вектора, т.е., уже и массива
    string text, d; //text - каждая строка, d - каждый элемент строки
    int k = 0; //количество значений R
    for (int i=0;  i<len; i++){ 
		text=data[i];
		stringstream s(text);
		while(s>>d){
            if(d[0]=='R') k++;
        }
	}
	return k;
}

string r_N(int N){  //возвращает R с n-ым значением
    std::vector<std::string> v = my_data();
    string *data = v.data();
	double len = v.size();  //определить длину вектора, т.е., уже и массива
    string text, d; //text - каждая строка, d - каждый элемент строки
    int k = 0; //количество значений R
    for (int i=0;  i<len; i++){ 
		text=data[i];
		stringstream s(text);
		while(s>>d){
            if(d[0]=='R'){
                if(k==N) return d;
                k++;
            }
        }
	}
}