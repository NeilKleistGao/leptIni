#include <cstring>
#include "iniProperty.h"

using namespace leptIni;

iniProperty::iniProperty()
{
	_property = propertyType::null;
}

iniProperty::~iniProperty()
{

}

double iniProperty::getNumber(const double& def)
{
	if (_property == propertyType::number)
	{
		return _value.d;
	}
	else
	{
		return def;
	}
}

bool iniProperty::getBoolean(const bool& def)
{
	if (_property == propertyType::boolean)
	{
		return _value.b;
	}
	else
	{
		return def;
	}
}

const char* iniProperty::getString(const char* def)
{
	if (_property == propertyType::string)
	{
		return _value.s;
	}
	else
	{
		return def;
	}
}

void iniProperty::setNumber(const double& d)
{
	if (_property == propertyType::null)
	{
		_property = propertyType::number;
	}

	if (_property == propertyType::number)
	{
		_value.d = d;
	}
}

void iniProperty::setBoolean(const bool& b)
{
	if (_property == propertyType::null)
	{
		_property = propertyType::boolean;
	}

	if (_property == propertyType::boolean)
	{
		_value.b = b;
	}
}

void iniProperty::setString(const char* s)
{
	if (_property == propertyType::null)
	{
		_property = propertyType::string;
	}

	if (_property == propertyType::string)
	{
		size_t len = strlen(s);
		_value.s = new char[len + 1];
		memcpy(_value.s, s, len);
		_value.s[len] = '\0';
	}
}

propertyType iniProperty::getType()
{
	return _property;
}