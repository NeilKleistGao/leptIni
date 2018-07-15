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

		void insert(const std::string& key, double d);
		void insert(const std::string& key, const char* s);
		void insert(const std::string& key, bool b);

		void setValue(const std::string& key, double d);
		void setValue(const std::string& key, const char* s);
		void setValue(const std::string& key, bool b);

		void erase(const std::string& key);

		double getNumber(const std::string& key, double def = 0.0);
		const char* getString(const std::string& key, const char* def = "");
		bool getBoolean(const std::string& key, bool def = false);

		std::string toString();

	private:
		std::map<std::string, iniProperty> _map;
	};
}