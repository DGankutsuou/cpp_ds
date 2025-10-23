#pragma once
# include "inputslib.h"
# include <iostream>
# include <ctime>
# include <string>
# include <vector>
# include "String.hpp"
using namespace std;

class Date
{
private:
	short _day;
	short _month;
	short _year;

	enum e_cmparation
	{
		before = -1,
		equal,
		after
	};

public:

	Date(void)
	{
		// Date now = get_system_date();
		// _day = now.get_day();
		// _month = now.get_month();
		// _year = now.get_year();
		_day = 1;
		_month = 1;
		_year = 0;
	}

	Date(short day, short month, short year)
	{
		_day = day;
		_month = month;
		_year = year;
	}

	~Date(){}

	short	get_day(void)
	{
		return (_day);
	}
	short	get_month(void)
	{
		return (_month);
	}
	short	get_year(void)
	{
		return (_year);
	}

	void	set_day(short day)
	{
		_day = day;
	}
	void	set_month(short month)
	{
		_month = month;
	}
	void	set_year(short year)
	{
		_year = year;
	}

	static void print_year_calender_header(short year)
	{
		cout << "\n  _________________________________\n";
		cout << "            Calender . " << year << "            ";
		cout << "\n  _________________________________" << endl;
	}

	static void print_month_calender_header(string month_symbol)
	{
		cout << "\n  _______________";
		printf("%s", month_symbol.c_str());
		cout << "_______________\n";
		cout << "  sun  mon  tue  wed  thu  fri  sat" << endl;
	}

	static bool is_leap_year(unsigned short year)
	{
		return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
	}

	static short number_of_days_in_year(short year)
	{
		return (is_leap_year(year) ? 366 : 365);
	}

	static short number_of_hours_in_year(short year)
	{
		return (number_of_days_in_year(year) * 24);
	}

	static int number_of_minutes_in_year(short year)
	{
		return (number_of_hours_in_year(year) * 60);
	}

	static int number_of_seconds_in_year(short year)
	{
		return (number_of_minutes_in_year(year) * 60);
	}

	static short number_of_days_in_month(short month, short year)
	{
		short number_of_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		return (month == 2 ? (is_leap_year(year) ? 29 : 28)
						   : number_of_days[month - 1]);
	}

	static short number_of_hours_in_month(short month, short year)
	{
		return (number_of_days_in_month(month, year) * 24);
	}

	static int number_of_minutes_in_month(short month, short year)
	{
		return (number_of_hours_in_month(month, year) * 60);
	}

	static int number_of_seconds_in_month(short month, short year)
	{
		return (number_of_minutes_in_month(month, year) * 60);
	}

	static short get_day_order_in_week(short day, short month, short year)
	{
		short a;
		short y;
		short m;
		short d;

		a = (14 - month) / 12;
		y = year - a;
		m = month + 12 * a - 2;
		d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
		return (d);
	}

	short get_day_order_in_week(void)
	{
		return (get_day_order_in_week(_day, _month, _year));
	}

	static string day_name(short index)
	{
		string week_days[7] = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday"};

		return (week_days[index]);
	}

	static string day_symbol(short index)
	{
		string week_days[7] = {
			"Sun", "Mon", "Tue",
			"Wed", "Thu", "Fri",
			"Sat"};

		return (week_days[index]);
	}

	static string get_month_symbol(short month)
	{
		string symbol[12] = {
			"Jan", "Feb", "Mar", "Apr",
			"May", "Jun", "Jul", "Aug",
			"Sep", "Oct", "Nov", "Dec"};

		return (symbol[month - 1]);
	}

	static void print_month_calender(short month, short year)
	{
		short day_idx;
		short number_of_days;

		print_month_calender_header(get_month_symbol(month));
		day_idx = get_day_order_in_week(1, month, year);
		number_of_days = number_of_days_in_month(month, year);
		for (int i = 0; i < day_idx; i++)
		{
			cout << "     ";
		}
		for (int i = 1; i <= number_of_days; i++)
		{
			// cout << right << setw(3) << i << "  ";
			printf("%5d", i);
			if (day_idx == 6)
			{
				cout << "\n";
				day_idx = 0;
				continue;
			}
			day_idx++;
		}
		cout << "\n"
			 << endl;
	}

	static void print_year_calender(short year)
	{
		print_year_calender_header(year);
		for (int m = 1; m <= 12; m++)
		{
			print_month_calender(m, year);
		}
	}

	static short get_day_order_in_year(short day, short month, short year)
	{
		short number_of_days = 0;

		for (int m = 1; m < month; m++)
		{
			number_of_days += number_of_days_in_month(m, year);
		}
		number_of_days += day;
		return (number_of_days);
	}

	short get_day_order_in_year(void)
	{
		return (get_day_order_in_year(_day, _month, _year));
	}

	static Date	get_date_from_day_order_in_year(short number_of_days, short year)
	{
		Date date;
		short number_of_days_of_month;

		date.set_year(year);
		date.set_month(1);
		while (true)
		{
			number_of_days_of_month = number_of_days_in_month(date.get_month(), year);
			if (number_of_days > number_of_days_of_month)
			{
				number_of_days -= number_of_days_of_month;
				date.set_month(date.get_month() + 1);
			}
			else
			{
				date.set_day(number_of_days);
				break;
			}
		}
		return (date);
	}

	void print_date(void)
	{
		cout << _day << "/" << _month << "/" << _year << endl;
	}

	void read_date(string message)
	{
		short number_of_days_of_month;

		cout << message;
		_year = input::read_number("Enter the year: ");
		_month = input::read_number_in_range(1, 12, "Enter a month ");
		number_of_days_of_month = number_of_days_in_month(_month, _year);
		_day = input::read_number_in_range(1, number_of_days_of_month, "Enter a day ");
	}

	static bool is_date1_before_date2(Date date1, Date date2)
	{
		return (date1.get_year() < date2.get_year() ? true : (date1.get_year() == date2.get_year() ? (date1.get_month() < date2.get_month() ? true : (date1.get_month() == date2.get_month() ? date1.get_day() < date2.get_day() : false)) : false));
	}

	static bool is_date1_equal_to_date2(Date date1, Date date2)
	{
		return (date1.get_year() == date2.get_year() ? (date1.get_month() == date2.get_month() ? date1.get_day() == date2.get_day() : false) : false);
	}

	static bool is_last_day_in_month(Date date)
	{
		return (date.get_day() == number_of_days_in_month(date.get_month(), date.get_year()));
	}

	static bool is_last_month_in_year(Date date)
	{
		return (date.get_month() == 12);
	}

	static Date add_one_day_to_date(Date date)
	{
		if (is_last_day_in_month(date))
		{
			if (is_last_month_in_year(date))
			{
				date.set_year(date.get_year() + 1);
				date.set_month(1);
				date.set_day(1);
			}
			else
			{
				date.set_month(date.get_month() + 1);
				date.set_day(1);
			}
		}
		else
		{
			date.set_day(date.get_day() + 1);
		}
		return (date);
	}

	static int difference_between_two_dates(Date date1, Date date2, bool include_last_day = false)
	{
		int difference = 0;

		if (is_date1_before_date2(date1, date2))
		{
			while (!is_date1_equal_to_date2(date1, date2))
			{
				date1 = add_one_day_to_date(date1);
				difference++;
			}
			return (include_last_day ? ++difference : difference);
		}
		else if (is_date1_equal_to_date2(date1, date2) && include_last_day)
			return (1);
		return (difference);
	}

	static Date get_system_date(void)
	{
		time_t t = time(0);
		tm *now = localtime(&t);
		Date current_date;

		if (now == NULL)
		{
			current_date.set_year(0);
			current_date.set_month(1);
			current_date.set_day(1);
		}
		else
		{
			current_date.set_year(now->tm_year + 1900);
			current_date.set_month(now->tm_mon + 1);
			current_date.set_day(now->tm_mday);
		}
		return (current_date);
	}

	static string get_system_time(void)
	{
		time_t t = time(0);
		tm *now = localtime(&t);
		string current_time = "";

		if (now == NULL)
		{
			current_time += "00:";
			current_time += "00:";
			current_time += "00";
		}
		else
		{
			current_time += to_string(now->tm_hour);
			current_time += ":";
			current_time += to_string(now->tm_min);
			current_time += ":";
			current_time += to_string(now->tm_sec);
		}
		return (current_time);
	}

	static string get_system_date_and_time(void)
	{
		string current = "";

		current += get_system_date().date_to_string();
		current += " - ";
		current += get_system_time();
		return current;
	}

	static short get_age_as_days(Date birthday)
	{
		return (difference_between_two_dates(birthday, get_system_date(), true));
	}

	static void swap_dates(Date &date1, Date &date2)
	{
		Date tmp;

		tmp = date1;
		date1 = date2;
		date2 = tmp;
	}

	static int ultimate_difference_between_two_dates1(Date date1, Date date2, bool include_last_day = false)
	{
		int difference = 0;
		short flag = 1;

		if (!is_date1_before_date2(date1, date2))
		{
			swap_dates(date1, date2);
			flag = -1;
		}
		while (!is_date1_equal_to_date2(date1, date2))
		{
			date1 = add_one_day_to_date(date1);
			difference++;
		}
		return (include_last_day ? ++difference * flag : difference * flag);
	}

	static Date add_x_days_to_date(Date date, int x)
	{
		short counter = 0;

		while (counter < x)
		{
			date = add_one_day_to_date(date);
			counter++;
		}
		return (date);
	}

	static Date add_one_week_to_date(Date date)
	{
		short counter = 0;

		while (counter < 7)
		{
			date = add_one_day_to_date(date);
			counter++;
		}
		return (date);
	}

	static Date add_x_weeks_to_date(Date date, int x)
	{
		short counter = 0;

		while (counter < x)
		{
			date = add_one_week_to_date(date);
			counter++;
		}
		return (date);
	}

	static Date add_one_month_to_date(Date date)
	{
		short days;

		date.set_month(date.get_month() + 1);
		if (date.get_month() == 13)
		{
			date.set_month(1);
			date.set_year(date.get_year() + 1);
		}
		days = number_of_days_in_month(date.get_month(), date.get_year());
		if (date.get_day() > days)
		{
			date.set_day(days);
		}
		return (date);
	}

	static Date add_x_months_to_date(Date date, int x)
	{
		short counter = 0;

		while (counter < x)
		{
			date = add_one_month_to_date(date);
			counter++;
		}
		return (date);
	}

	static Date add_one_year_to_date(Date date)
	{
		date.set_year(date.get_year() + 1);
		return (date);
	}

	static Date add_x_years_to_date(Date date, int x)
	{
		date.set_year(date.get_year() + x);
		return (date);
	}

	static Date add_one_decade_to_date(Date date)
	{
		date.set_year(date.get_year() + 10);
		return (date);
	}

	static Date add_x_decades_to_date(Date date, int x)
	{
		date.set_year(date.get_year() + x * 10);
		return (date);
	}

	static Date add_one_century_to_date(Date date)
	{
		date.set_year(date.get_year() + 100);
		return (date);
	}

	static Date add_one_millemuim_to_date(Date date)
	{
		date.set_year(date.get_year() + 1000);
		return (date);
	}

	static Date decrease_one_day_from_date(Date date)
	{
		if (date.get_day() == 1)
		{
			if (date.get_month() == 1)
			{
				date.set_year(date.get_year() - 1);
				date.set_month(12);
				date.set_day(31);
			}
			else
			{
				date.set_month(date.get_month() - 1);
				date.set_day(number_of_days_in_month(date.get_month(), date.get_year()));
			}
		}
		else
		{
			date.set_day(date.get_day() - 1);
		}
		return (date);
	}

	static Date decrease_x_days_from_date(Date date, int x)
	{
		short counter = 0;

		while (counter < x)
		{
			date = decrease_one_day_from_date(date);
			counter++;
		}
		return (date);
	}

	static Date decrease_one_week_from_date(Date date)
	{
		short counter = 0;

		while (counter < 7)
		{
			date = decrease_one_day_from_date(date);
			counter++;
		}
		return (date);
	}

	static Date decrease_x_weeks_from_date(Date date, int x)
	{
		short counter = 0;

		while (counter < x)
		{
			date = decrease_one_week_from_date(date);
			counter++;
		}
		return (date);
	}

	static Date decrease_one_month_from_date(Date date)
	{
		short days;

		date.set_month(date.get_month() - 1);
		if (date.get_month() == 0)
		{
			date.set_month(12);
			date.set_year(date.get_year() - 1);
		}
		days = number_of_days_in_month(date.get_month(), date.get_year());
		if (date.get_day() > days)
		{
			date.set_day(days);
		}
		return (date);
	}

	static Date decrease_x_months_from_date(Date date, int x)
	{
		short counter = 0;

		while (counter < x)
		{
			date = decrease_one_month_from_date(date);
			counter++;
		}
		return (date);
	}

	static Date decrease_one_year_from_date(Date date)
	{
		date.set_year(date.get_year() - 1);
		return (date);
	}

	static Date decrease_x_years_from_date(Date date, int x)
	{
		date.set_year(date.get_year() - x);
		return (date);
	}

	static Date decrease_one_decade_from_date(Date date)
	{
		date.set_year(date.get_year() - 10);
		return (date);
	}

	static Date decrease_x_decades_from_date(Date date, int x)
	{
		date.set_year(date.get_year() - x * 10);
		return (date);
	}

	static Date decrease_one_century_from_date(Date date)
	{
		date.set_year(date.get_year() - 100);
		return (date);
	}

	static Date decrease_one_millemuim_from_date(Date date)
	{
		date.set_year(date.get_year() - 1000);
		return (date);
	}

	static void print_current_date()
	{
		Date date;

		date = get_system_date();
		cout << "Today is " << day_name(date.get_day_order_in_week());
		cout << " ";
		date.print_date();
	}

	bool is_end_of_week(void)
	{
		return (get_day_order_in_week() == 6);
	}

	bool is_weekend(void)
	{
		return (get_day_order_in_week() >= 5);
	}

	bool is_business_day(void)
	{
		return (!is_weekend());
	}

	short days_until_end_of_week(void)
	{
		return (6 - get_day_order_in_week());
	}

	short days_until_end_of_month(void)
	{
		Date end_of_month;

		end_of_month = *this;
		end_of_month.set_day(number_of_days_in_month(_month, _year));
		return (difference_between_two_dates(*this, end_of_month));
	}

	short days_until_end_of_year(void)
	{
		Date end_of_year;

		end_of_year.set_year(_year);
		end_of_year.set_month(12);
		end_of_year.set_day(31);
		return (difference_between_two_dates(*this, end_of_year));
	}

	static short calculate_vacation_days(Date start, Date end)
	{
		short counter = 0;

		while (is_date1_before_date2(start, end))
		{
			if (start.is_business_day())
				counter++;
			start = add_one_day_to_date(start);
		}
		return (counter);
	}

	static Date calculate_vacation_end(Date start, short vacation_days)
	{
		Date end;

		end = start;
		while (vacation_days)
		{
			if (end.is_business_day())
				vacation_days--;
			end = add_one_day_to_date(end);
		}
		return (end);
	}

	static bool is_date1_after_date2(Date date1, Date date2)
	{
		return (is_date1_before_date2(date2, date1));
	}

	static e_cmparation compare_two_dates(Date date1, Date date2)
	{
		if (is_date1_equal_to_date2(date1, date2))
			return (e_cmparation::equal);
		else if (is_date1_before_date2(date1, date2))
			return (e_cmparation::before);
		return (e_cmparation::after);
	}

	bool is_date_valid(void)
	{
		if (_day > 31 || _day < 1)
			return (false);
		if (_month > 12 || _month < 1)
			return (false);
		else if (_day > number_of_days_in_month(_month, _year))
			return (false);
		return (true);
	}

	string date_to_string(void)
	{
		string date_string = "";

		date_string += to_string(_day) + "/" + to_string(_month) + "/" + to_string(_year);
		return (date_string);
	}

	static Date string_to_date(string date)
	{
		Date date_ob;
		vector<string> date_splited;

		date_splited = String::spliter(date, "/");
		date_ob.set_day(stoi(date_splited[0]));
		date_ob.set_month(stoi(date_splited[1]));
		date_ob.set_year(stoi(date_splited[2]));
		return (date_ob);
	}

	void print_date_ob(void)
	{
		cout << "day: " << _day << endl;
		cout << "month: " << _month << endl;
		cout << "year: " << _year << endl;
	}
};
