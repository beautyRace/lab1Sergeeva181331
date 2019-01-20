#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>

int main()
{
	std::cout << "lab13task2\n" << std::endl;
	std::stack<char> sta;
	std::string all;
	std::cout << "Input string:\t";
	std::getline(std::cin, all);
	int len = all.length();
	for (int i = 0; i < len; i++)
	{
		if ((all[i] == '(') || (all[i] == '[') || (all[i] == '{'))
		{
			sta.push(all[i]);
		}
		if (all[i] == ')')
		{
			if (sta.empty())
			{
				if (sta.top() == '(')
				{
					sta.pop();
				}
			}
		}
		if (all[i] == ']')
		{
			if (sta.empty())
			{
				if (sta.top() == '[')
				{
					sta.pop();
				}
			}
		}
		if (all[i] == '}')
		{
			if (sta.empty())
			{
				if (sta.top() == '{')
				{
					sta.pop();
				}
			}
		}
	}
	if (all.empty())
		std::cout << "no" << std::endl;
	else
		std::cout << "yes" << std::endl;
	system("pause");
	return 0;
}