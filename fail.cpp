#include "fail.h"

void outArr(std::string fail, int** arr, int n, int m)
{
	std::ofstream fout;
	fout.open(fail);
	if (!fout.is_open())
		std::cout << "file cannot be opened\n";
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				fout << arr[i][j] << ' ';
			fout << '\n';
		}
		fout.close();
	}
}
bool cond(int i)
{
	return i % 2 == 0;
}
void overWriting(int* arr,int n, bool(*cond)(int))
{
	std::ofstream fout;
	fout.open("file2.txt");
	for (int i = 0; i < n; i++)
		if (cond(i))
			fout << arr[i] << ' ';
	fout.close();
}

void createFile(std::string name)
{
	std::ofstream fout;

	fout.open(name);
	for (int i = 0; i < rand() % 100 + 1; i++)
		fout << rand() % 10 << ' ';
	fout.close();
}

void number3()
{
	createFile("f.txt");

	createFile("g.txt");
	
	std::ifstream fin, gin;
	std::ofstream hout;
	fin.open("f.txt");
	gin.open("g.txt");
	hout.open("h.txt");
	int n;
	while (fin >> n)
		hout << n << ' ';
	fin.close();
	while (gin >> n)
		hout << n << ' ';
	gin.close();
	hout.close();
}
void createBreakets()
{
	const char* const numbers[] = { "more.txt", "less.txt", "equaval.txt", "end"};
	std::ofstream fout;
	for (int j = 0; numbers[j] != "end"; j++)
	{
		fout.open(numbers[j]);
		if (fout.is_open())
		{
			if (numbers[j] == "more.txt")
				fout << "(2x + 3y) * ((x + y) - 3(xy - 4) + 5))";
			if (numbers[j] == "less.txt")
				fout << "(2x + 3y) * ((x + y) - 3(xy - 4) + 5";
			if (numbers[j] == "equaval.txt")
				fout << "(2x + 3y) * ((x + y) - 3(xy - 4) + 5)";
		}
		else
			std::cout << "Error\n";
		fout.close();
	}
}
const char* checkBreakets(const char* fail)
{
	std::ifstream fin;
	fin.open(fail);
	char sim;
	int left = 0, right = 0;
	const char* const otvet[] = { "error", "more left", "equaval", "more right" };
	if (fin.is_open())
	{
		while (fin.get(sim))
		{
			left += (sim == '(');
			right += (sim == ')');
		}
	}
	else
		return otvet[0];
	fin.close();

	if (left > right)
		return otvet[1];
	if (left == right)
		return otvet[2];
	if (left < right)
		return otvet[3];
}
std::map<std::string, int> createVoc()
{
	char t;
	std::map<std::string, int> voc;
	std::string word;
	std::cin.ignore();
	std::map <std::string, int> ::iterator it;
	while ((t = getchar()) != '\n')
	{
		if (t != ' ' && !ispunct(t))
			word.push_back(t);
		else 
		{
			it = voc.find(word);
			if (it == voc.end())
				voc[word] = 1;
			else
				voc[word] += 1;
			word = "";
		}
	}
	it = voc.find(word);
	if (it == voc.end())
		voc[word] = 1;
	else
		voc[word] += 1;
	word = "";

	return voc;
}
bool isEntryWord(std::string file, std::string word)
{
	std::ifstream fin;
	fin.open(file);
	std::string w;
	while (fin >> w)
		if (w == word) {
			fin.close();
			return true;
		}
	fin.close();
	return false;
}