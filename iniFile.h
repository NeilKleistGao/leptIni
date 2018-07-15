#pragma once

#include <fstream>
#include "iniSection.h"

namespace leptIni
{
	const size_t buff_size = 2048;

	class iniFile
	{
	public:
		iniFile(std::string filename);
		~iniFile();

		void insertSection(std::string name);
		void eraseSection(std::string name);

		void insertProperty(std::string name ,std::string key, double d);
		void insertProperty(std::string name, std::string key, const char* s);
		void insertProperty(std::string name, std::string key, bool b);

		void setProperty(std::string name, std::string key, double d);
		void setProperty(std::string name, std::string key, const char* s);
		void setProperty(std::string name, std::string key, bool b);

		double getNumberProperty(std::string name, std::string key, double def = 0.0);
		const char* getStringProperty(std::string name, std::string key, const char* def = "");
		bool getBooleanProperty(std::string name, std::string key, bool def = false);

		void eraseProperty(std::string name ,std::string key);

		void save();

	private:
		void parse();
		void parseProperty(const char* name, const char* line);
		bool isWhiteSpace(char c);

	private:
		std::map<std::string, iniSection> _map;
		std::fstream _stream;
		std::string _name;
	};
}