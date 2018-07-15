#pragma once

#include <fstream>
#include "iniSection.h"

namespace leptIni
{
	const size_t buff_size = 2048;

	class iniFile
	{
	public:
		iniFile(const std::string& filename);
		~iniFile();

		void insertSection(const std::string& name);
		void eraseSection(const std::string& name);

		void insertProperty(const std::string& name ,const std::string& key, double d);
		void insertProperty(const std::string& name, const std::string& key, const char* s);
		void insertProperty(const std::string& name, const std::string& key, bool b);

		void setProperty(const std::string& name, const std::string& key, double d);
		void setProperty(const std::string& name, const std::string& key, const char* s);
		void setProperty(const std::string& name, const std::string& key, bool b);

		double getNumberProperty(const std::string& name, const std::string& key, double def = 0.0);
		const char* getStringProperty(const std::string& name, const std::string& key, const char* def = "");
		bool getBooleanProperty(const std::string& name, const std::string& key, bool def = false);

		void eraseProperty(const std::string& name ,const std::string& key);

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