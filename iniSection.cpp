#include <sstream>
#include "iniSection.h"

using namespace leptIni;

iniSection::iniSection()
{

}

iniSection::~iniSection()
{
	_map.clear();
}

void iniSection::insert(std::string key, double d)
{
	if (_map.find(key) != _map.end())
	{
		return;
	}

	iniProperty ip;
	ip.setNumber(d);
	_map[key] = ip;
}

void iniSection::insert(std::string key, const char* s)
{
	if (_map.find(key) != _map.end())
	{
		return;
	}

	iniProperty ip;
	ip.setString(s);
	_map[key] = ip;
}

void iniSection::insert(std::string key, bool b)
{
	if (_map.find(key) != _map.end())
	{
		return;
	}

	iniProperty ip;
	ip.setBoolean(b);
	_map[key] = ip;
}

void iniSection::setValue(std::string key, double d)
{
	if (_map.find(key) != _map.end())
	{
		_map[key].setNumber(d);
	}
}

void iniSection::setValue(std::string key, const char* s)
{
	if (_map.find(key) != _map.end())
	{
		_map[key].setString(s);
	}
}

void iniSection::setValue(std::string key, bool b)
{
	if (_map.find(key) != _map.end())
	{
		_map[key].setBoolean(b);
	}
}

void iniSection::erase(std::string key)
{
	auto it = _map.find(key);
	if (it != _map.end())
	{
		_map.erase(it);
	}
}

double iniSection::getNumber(std::string key, double def)
{
	if (_map.find(key) != _map.end())
	{
		return _map[key].getNumber(def);
	}
	else
	{
		return def;
	}
}

const char* iniSection::getString(std::string key, const char* def)
{
	if (_map.find(key) != _map.end())
	{
		return _map[key].getString(def);
	}
	else
	{
		return def;
	}
}

bool iniSection::getBoolean(std::string key, bool def)
{
	if (_map.find(key) != _map.end())
	{
		return _map[key].getBoolean(def);
	}
	else
	{
		return def;
	}
}

std::string iniSection::toString()
{
	std::string ret = "";
	for (auto it = _map.begin(); it != _map.end(); it++)
	{
		ret += (*it).first;
		ret += " = ";
		
		iniProperty ip = (*it).second;
		propertyType type = ip.getType();
		std::stringstream stream;
		std::string val = "";
		double d = 0.0;
		bool b = false;

		switch (type)
		{
		case leptIni::number:
			d = ip.getNumber();
			stream << d;
			stream >> val;
			break;
		case leptIni::boolean:
			b = ip.getBoolean();
			stream << b;
			stream >> val;
			break;
		case leptIni::string:
			val = ip.getString();
			break;
		}

		if (type == propertyType::string)
		{
			ret += "\"";
		}
		ret += val;
		if (type == propertyType::string)
		{
			ret += "\"";
		}
		ret += '\n';
	}

	return ret;
}