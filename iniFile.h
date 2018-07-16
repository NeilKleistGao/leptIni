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
		/*
			解析ini文件，在构造函数中自动调用
		*/
		void parse();
		
		/*
			解析单个属性
			name: 属性所在节的名称 line：属性所在行的内容
		*/
		void parseProperty(const char* name, const char* line);
		
		/*
			判断是否为空白字符
			c：将要判断字符
			返回值：true->空白字符
		*/
		bool isWhiteSpace(char c);

	private:
		std::unordered_map<std::string, iniSection> _map;// 存储文件中的节
		std::fstream _stream;//文件流
		std::string _name;//文件名
	};
}