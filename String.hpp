#pragma once
# include <iostream>
# include <vector>
using namespace std;

class String
{
	private:
		string	_value;

		static bool	ft_islower(char c)
		{
			if (c <= 'z' && c >= 'a')
				return (true);
			return (false);
		}

		static bool	ft_isupper(char c)
		{
			if (c <= 'Z' && c >= 'A')
				return (true);
			return (false);
		}

		static char	ft_invert_char(char c)
		{
			if (ft_isupper(c))
				c += 32;
			else if (ft_islower(c))
				c -= 32;
			return (c);
		}
	public:
		String(void){}

		String(string value)
		{
			_value = value;
		}

		string	value(void)
		{
			return (_value);
		}

		void	set_value(string value)
		{
			_value = value;
		}

		static string	ft_strinvert(string str)
		{
			for (int i = 0; i < str.length(); i++)
			{
				str[i] = ft_invert_char(str[i]);
			}
			return (str);
		}

		static string	joiner(vector <string> words, string delim)
		{
			string	joined;

			joined = "";
			for (string &word : words)
				joined += word + delim;
			return (joined.substr(0, joined.length() - delim.length()));
		}

		static vector <string>	spliter(string str, string delim)
		{
			string	word;
			short	pos;
			vector <string> words;

			while ((pos = str.find(delim)) != string::npos)
			{
				word = str.substr(0, pos);
				if (word != "")
					words.push_back(word);
				str.erase(0, pos + delim.length());
			}
			if (str != "")
				words.push_back(str);
			return (words);
		}

		static string	ft_str_replace(string str, string to_replace, string replace_to)
		{
			short	pos;

			pos = str.find(to_replace);
			while (pos != string::npos)
			{
				str.replace(pos, to_replace.length(), replace_to);
				pos = str.find(to_replace);
			}
			return (str);
		}

		static string	lowerizer(string str)
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] = tolower(str[i]);
			}
			return (str);
		}

		static string	capitalizer(string str)
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] = toupper(str[i]);
			}
			return (str);
		}

		string	ft_strinvert(void)
		{
			return (_value);
		}

		vector <string>	spliter(string delim)
		{
			return (spliter(_value, delim));
		}

		string	ft_str_replace(string to_replace, string replace_to)
		{
			return (ft_str_replace(_value, to_replace, replace_to));
		}

		string	lowerizer(void)
		{
			return (lowerizer(_value));
		}

		string	capitalizer(void)
		{
			return (capitalizer(_value));
		}
};
