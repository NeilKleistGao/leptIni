#pragma once

#include <map>
#include "iniProperty.h"

namespace leptIni
{
	class iniSection
	{
	public:
		iniSection();
		~iniSection();

		void insert(std::string key, double d);
		void insert(std::string key, const char* s);
		void insert(std::string key, bool b);

		void setValue(std::string key, double d);
		void setValue(std::string key, const char* s);
		void setValue(std::string key, bool b);

		void erase(std::string key);

		double getNumber(std::string key, double def = 0.0);
		const char* getString(std::string key, const char* def = "");
		bool getBoolean(std::string key, bool def = false);

		std::string toString();

	private:
		std::map<std::string, iniProperty> _map;
	};
}