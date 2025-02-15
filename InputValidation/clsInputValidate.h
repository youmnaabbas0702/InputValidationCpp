#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:
	 template<typename T> static bool IsNumberBetween(T Number, T From, T To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (Date.IsDate1EqualDate2(DateFrom) || Date.IsDate1EqualDate2(DateTo))
			return true;
		if (DateFrom.IsDate1AfterDate2(DateTo))
			clsDate::SwapDates(DateFrom, DateTo);
		return Date.IsDate1AfterDate2(DateFrom) && Date.IsDate1BeforeDate2(DateTo);
	}

	template<typename T> static T ReadNumber(string ErrorMsg)
	{
		T Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMsg;
		}
		return Number;
	}

	template<typename T> static T ReadNumberBetween(T From, T To, string ErrorMsg)
	{
		T Number = ReadNumber<T>(ErrorMsg);
		while (!IsNumberBetween<T>(Number, From, To))
		{
			cout << ErrorMsg;
			Number = ReadIntNumber(ErrorMsg);
		}

		return Number;
	}
};

