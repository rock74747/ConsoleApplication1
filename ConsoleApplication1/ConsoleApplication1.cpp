#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <stack>

#define LINES 120


int main()
{
	setlocale(0, "");




	std::stack<std::string> stack;
	std::stack<std::string> st;
	std::stack<std::string> stat;
	std::string path = "Name.txt";
	std::ifstream in;
	std::ifstream inout;
	std::ofstream out;
	std::string word;
	std::string path_s = "2.txt";
	int length = 0;


	in.open(path);
	if (in.is_open()) {
		std::cout << "Файл открыт. \n";
		while (!in.eof()) { // Пословное считывание
			in >> word;
			stack.push(word);
		}
	}
	else {
		std::cout << "Ошибка открытия файла \n";
	}
	in.close();
	int size = stack.size();

	while (stack.size() > 19) {
		st.push(stack.top());
		stack.pop();
	}
	while (stack.size() > 0) {
		stat.push(stack.top());
		stack.pop();
	}

	out.open(path_s, std::ios::app ); //  Файл для записи
	if (out.is_open()) {
		std::cout << "Файл открыт. \n";
		out << "The first       | The second      " << '\n';
		for (int i = 0; i < st.size(); i++) {
			out << st.top() << ' ';
			if ((i + 1) % 4 == 0) {
				out << '\n';
			}
			st.pop(); // Удаляем последний элемент из стэка (последний добавленный в стэк элемент)
		}
		out.flush();
		for (int i = 0; i < stat.size(); i++) {
			out << stat.top() << ' ';
			if ((i + 1) % 4 == 0) {
				out << '\n';
			}
			stat.pop(); // Удаляем последний элемент из стэка (последний добавленный в стэк элемент)
		}
		out.close();
	}
	else {
		std::cout << "Ошибка открытия файла \n";
	}
	return 0;
}