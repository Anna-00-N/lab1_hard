#include <vector>
#include <string>

std::vector<std::string> my_data(){
	/*реагирует только на line и circle*/
	return {
		"-3 line 1 3",
		/*значения x до -3, тип, k, m*/
		"0 circle plus 3", /*значения х от -3 до 0, верхняя половина круга, радиус 3*/
		"6 line -0.5 0 0 3"/*0, 3 - сдвиги по х, y*/,
		"N line 1 0 6 0" /*N - бесконечность*/
	};
}