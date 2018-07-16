#pragma once

#include <iostream>

namespace leptIni
{
	/*
		���Ե�����
	*/
	enum propertyType
	{
		null = 0,//�գ�Ĭ��ֵ
		number,//����
		boolean,//����ֵ
		string//�ַ���
	};

	class iniProperty
	{
	private:
		propertyType _property;//��ǰ���Ե�����
	public:
		iniProperty();
		~iniProperty();

		/*
			��ȡ���֣�����������Ϊ�����֣�����Ĭ��ֵ
			def��Ĭ��ֵ��Ĭ��Ϊ0
		*/
		double getNumber(const double& def = 0.0);
		/*
			��ȡ����ֵ������������Ϊ�ǲ���������Ĭ��ֵ
			def��Ĭ��ֵ��Ĭ��Ϊfalse
		*/
		bool getBoolean(const bool& def = false);
		/*
			��ȡ�ַ���������������Ϊ���ַ���������Ĭ��ֵ
			def��Ĭ��ֵ��Ĭ��Ϊ""
		*/
		const char* getString(const char* def = "");

		/*
			�������֣�����������Ϊ�������ҷǿգ������ò���
			d�����õ�ֵ
		*/
		void setNumber(const double& d);
		/*
			���ò���������������Ϊ�ǲ����ҷǿգ������ò���
			b�����õ�ֵ
		*/
		void setBoolean(const bool& b);
		/*
		�����ַ���������������Ϊ���ַ����ҷǿգ������ò���
		b�����õ�ֵ
		*/
		void setString(const char* s);

		/*
			��ȡ�����Ե�����
		*/
		propertyType getType();

	private:
		union
		{
			double d;
			char* s;
			bool b;
		} _value;//�洢����
	};
}