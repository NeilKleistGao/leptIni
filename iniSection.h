#pragma once

#include <map>
#include <unordered_map>
#include "iniProperty.h"

namespace leptIni
{
	class iniSection
	{
	public:
		iniSection();
		~iniSection();

		/*
			插入属性，若同名属性已存在，则什么也不做
			key：属性的键
			d/s/b：属性的值
		*/
		void insert(const std::string& key, double d);
		void insert(const std::string& key, const char* s);
		void insert(const std::string& key, bool b);

		/*
			修改属性，若属性不存在，则什么也不做
			key：属性的键
			d/s/b：属性的值
		*/
		void setValue(const std::string& key, double d);
		void setValue(const std::string& key, const char* s);
		void setValue(const std::string& key, bool b);

		/*
			删除属性，若属性不存在，则什么也不做
			key：属性的键
		*/
		void erase(const std::string& key);

		/*
			获取数字，若属性不存在，返回默认值
			key：属性的键
			def：默认值，默认为0
		*/
		double getNumber(const std::string& key, double def = 0.0);
		/*
			获取字符串，若属性不存在，返回默认值
			key：属性的键
			def：默认值，默认为""
		*/
		const char* getString(const std::string& key, const char* def = "");
		/*
			获取布尔值，若属性不存在，返回默认值
			key：属性的键
			def：默认值，默认为false
		*/
		bool getBoolean(const std::string& key, bool def = false);

		/*
			将节中的所有键改写为ini文件格式的字符串并返回
		*/
		std::string toString();

	private:
		std::unordered_map<std::string, iniProperty> _map;//存储节中的属性
	};
}