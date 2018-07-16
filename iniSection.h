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
			�������ԣ���ͬ�������Ѵ��ڣ���ʲôҲ����
			key�����Եļ�
			d/s/b�����Ե�ֵ
		*/
		void insert(const std::string& key, double d);
		void insert(const std::string& key, const char* s);
		void insert(const std::string& key, bool b);

		/*
			�޸����ԣ������Բ����ڣ���ʲôҲ����
			key�����Եļ�
			d/s/b�����Ե�ֵ
		*/
		void setValue(const std::string& key, double d);
		void setValue(const std::string& key, const char* s);
		void setValue(const std::string& key, bool b);

		/*
			ɾ�����ԣ������Բ����ڣ���ʲôҲ����
			key�����Եļ�
		*/
		void erase(const std::string& key);

		/*
			��ȡ���֣������Բ����ڣ�����Ĭ��ֵ
			key�����Եļ�
			def��Ĭ��ֵ��Ĭ��Ϊ0
		*/
		double getNumber(const std::string& key, double def = 0.0);
		/*
			��ȡ�ַ����������Բ����ڣ�����Ĭ��ֵ
			key�����Եļ�
			def��Ĭ��ֵ��Ĭ��Ϊ""
		*/
		const char* getString(const std::string& key, const char* def = "");
		/*
			��ȡ����ֵ�������Բ����ڣ�����Ĭ��ֵ
			key�����Եļ�
			def��Ĭ��ֵ��Ĭ��Ϊfalse
		*/
		bool getBoolean(const std::string& key, bool def = false);

		/*
			�����е����м���дΪini�ļ���ʽ���ַ���������
		*/
		std::string toString();

	private:
		std::unordered_map<std::string, iniProperty> _map;//�洢���е�����
	};
}