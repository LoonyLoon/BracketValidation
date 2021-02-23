#include <iostream>
#include <string>
#include <map>
#include <stack>	


class BracketValidation
{

private:	
	std::map<char, char> brackets = {
		{')', '('},
		{'}', '{'},
		{']', '['}
	};
	std::stack<char> st;
	std::string m_TempString;


public:
	BracketValidation(std::string String)
	{
		for (int i = 0; i <= String.size(); i++) // Removing unnecessary charackters besides brackets
		{
			if (String[i] == '(' || String[i] == ')' ||
				String[i] == '[' || String[i] == ']' ||
				String[i] == '{' || String[i] == '}')
			{;
			
			m_TempString += String.substr(i, 1);
			}
		}
	}
	~BracketValidation()
	{

	};

	bool validation()
	{
		
		
		if (m_TempString.size() % 2 != 0) // Parity check 
		{
			return false;
		}

		for (auto ch : m_TempString) 
		{
			if (ch == '(' || ch == '{' || ch == '[') // if brackets are open then put on the stack
			{
				st.push(ch); 
			}
			else if (ch == ')' || ch == '}' || ch == ']') 
			{
				if (!st.empty() && st.top() == brackets[ch])
				{
					st.pop(); //if brackets are true and stack is't empty then removing pair brackets from the stack 
				}
				else
					return false;
			}
		}
		return st.empty();
	};


};


int main()
{
	std::string str;
	std::cout << "Enter expression" << std::endl;
	std::cin >> str;

	BracketValidation* obj = new BracketValidation(str);
	if (obj->validation())
	{
		std::cout << "True";
	}
	else {

		std::cout << "False";
	}

	delete obj;
	return 0;
}