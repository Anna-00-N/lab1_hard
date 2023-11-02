#include <vector> 
#include <string>

std::vector<std::string> my_data(){
	/*реагирует только на line и circle*/
	return {
		"-5 line 0 -3",
		"-3 line 1 3",
		"0 circle minus R1 -3 0 3",
		"3 circle minus R2 0 3 0",
		"8 line 0.6 0 3 0",
		"N line 0 3"
		//"-3 line 1 3",
		/*значения x до -3, тип, k, m*/
		//"0 circle plus R1 -3 0 3", 
		/*0 = x2, значения х берутся до 0, plus - верхняя половина круга, радиус R1, 
		x1=-3, y1=0, y2=3*/
		//"6 line -0.5 0 0 3"/*0, 3 - сдвиги по х, y*/,
		//"N line 1 0 6 0" /*N - бесконечность*/

	};
}