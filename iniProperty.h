#pragma once

#include <iostream>

namespace leptIni
{
	enum propertyType
	{
		null = 0,
		number,
		boolean,
		string
	};

	class iniProperty
	{
	private:
		propertyType _property;
	public:
		iniProperty();
		~iniProperty();

		double getNumber(const double& def = 0.0);
		bool getBoolean(const bool& def = false);
		const char* getString(const char* def = "");

		void setNumber(const double& d);
		void setBoolean(const bool& b);
		void setString(const char* s);

		propertyType getType();

	private:
		union
		{
			double d;
			char* s;
			bool b;
		} _value;
	};
}