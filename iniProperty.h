#pragma once

#include <iostream>

namespace leptIni
{
	/*
		属性的类型
	*/
	enum propertyType
	{
		null = 0,//空，默认值
		number,//数字
		boolean,//布尔值
		string//字符串
	};

	class iniProperty
	{
	private:
		propertyType _property;//当前属性的类型
	public:
		iniProperty();
		~iniProperty();

		/*
			获取数字，若属性类型为非数字，返回默认值
			def：默认值，默认为0
		*/
		double getNumber(const double& def = 0.0);
		/*
			获取布尔值，若属性类型为非布尔，返回默认值
			def：默认值，默认为false
		*/
		bool getBoolean(const bool& def = false);
		/*
			获取字符串，若属性类型为非字符串，返回默认值
			def：默认值，默认为""
		*/
		const char* getString(const char* def = "");

		/*
			设置数字，若属性类型为非数字且非空，跳过该操作
			d：设置的值
		*/
		void setNumber(const double& d);
		/*
			设置布尔，若属性类型为非布尔且非空，跳过该操作
			b：设置的值
		*/
		void setBoolean(const bool& b);
		/*
		设置字符串，若属性类型为非字符串且非空，跳过该操作
		b：设置的值
		*/
		void setString(const char* s);

		/*
			获取该属性的类型
		*/
		propertyType getType();

	private:
		union
		{
			double d;
			char* s;
			bool b;
		} _value;//存储数据
	};
}