#include <cstring>
#include "iniFile.h"

using namespace leptIni;

iniFile::iniFile(const std::string& filename)
{
	_stream.open(filename, std::fstream::in | std::fstream::out);
	_name = filename;
	parse();
}

iniFile::~iniFile()
{
	_map.clear();

	if (_stream.is_open())
	{
		_stream.close();
	}
}

void iniFile::insertSection(const std::string& name)
{
	if (_map.find(name) == _map.end())
	{
		_map[name] = iniSection();
	}
}

void iniFile::eraseSection(const std::string& name)
{
	auto it = _map.find(name);
	if (it != _map.end())
	{
		_map.erase(it);
	}
}

void iniFile::insertProperty(const std::string& name, const std::string& key, double d)
{
	if (_map.find(name) != _map.end())
	{
		_map[name].insert(key, d);
	}
}

void iniFile::insertProperty(const std::string& name, const std::string& key, const char* s)
{
	if (_map.find(name) != _map.end())
	{
		_map[name].insert(key, s);
	}
}

void iniFile::insertProperty(const std::string& name, const std::string& key, bool b)
{
	if (_map.find(name) != _map.end())
	{
		_map[name].insert(key, b);
	}
}

void iniFile::setProperty(const std::string& name, const std::string& key, double d)
{
	if (_map.find(name) != _map.end())
	{
		_map[name].setValue(key, d);
	}
}

void iniFile::setProperty(const std::string& name, const std::string& key, const char* s)
{
	if (_map.find(name) != _map.end())
	{
		_map[name].setValue(key, s);
	}
}

void iniFile::setProperty(const std::string& name, const std::string& key, bool b)
{
	if (_map.find(name) != _map.end())
	{
		_map[name].setValue(key, b);
	}
}

double iniFile::getNumberProperty(const std::string& name, const std::string& key, double def)
{
	if (_map.find(name) != _map.end())
	{
		return _map[name].getNumber(key, def);
	}

	return def;
}

const char* iniFile::getStringProperty(const std::string& name, const std::string& key, const char* def)
{
	if (_map.find(name) != _map.end())
	{
		return _map[name].getString(key, def);
	}

	return def;
}

bool iniFile::getBooleanProperty(const std::string& name, const std::string& key, bool def)
{
	if (_map.find(name) != _map.end())
	{
		return _map[name].getBoolean(key, def);
	}

	return def;
}

void iniFile::eraseProperty(const std::string& name, const std::string& key)
{
	if (_map.find(name) != _map.end())
	{
		_map[name].erase(key);
	}
}

void iniFile::save()
{
	_stream.open(_name, std::fstream::in | std::fstream::out);
	for (auto it = _map.begin(); it != _map.end(); it++)
	{
		_stream << "[" << (*it).first.c_str() << "]" << std::endl;
		iniSection sec = (*it).second;
		_stream << sec.toString().c_str() << std::endl;
	}
	_stream.close();
}

void iniFile::parse()
{
	std::string name = "";
	while (!_stream.eof())
	{
		char buff[buff_size];
		_stream.getline(buff, sizeof(buff));
		
		if (buff[0] == '[')
		{
			name = "";
			char* p = buff + 1;

			while (*p != ']')
			{
				name += *p;
				p++;
			}

			insertSection(name);
		}
		else if (buff[0] == ';')
		{
			continue;
		}
		else
		{
			parseProperty(name.c_str(), buff);
		}
	}

	_stream.close();
}

void iniFile::parseProperty(const char* name, const char* line)
{
	std::string key = "", s = "";
	bool b = false, sflag = false, dflag = false, bflag = false;
	double d = 0.0;

	size_t len = strlen(line);
	for (int i = 0; i < len; i++)
	{
		if (sflag)
		{
			if (line[i] == '\"')
			{
				break;
			}
			s += line[i];
		}
		else if (dflag)
		{
			char* end = nullptr;
			d = strtod(line + i, &end);
			break;
		}
		else if (bflag)
		{
			if (line[i] == 't' && line[i + 1] == 'r' && line[i + 2] == 'u' && line[i + 3] == 'e')
			{
				b = true;
				break;
			}

			if (line[i] == 'f' && line[i + 1] == 'a' && line[i + 2] == 'l' && line[i + 3] == 's' && line[i + 4] == 'e')
			{
				b = false;
				break;
			}
		}
		else
		{
			if (isWhiteSpace(line[i]))
			{
				continue;
			}

			if (line[i] == '=')
			{
				i++;
				while (isWhiteSpace(line[i]))
				{
					i++;
				}

				if (line[i] == '\"')
				{
					sflag = true;
				}
				else if (line[i] == 't' ||  line[i] == 'f')
				{
					bflag = true;
					i--;
				}
				else
				{
					dflag = true;
					i--;
				}
			}
			else
			{
				key += line[i];
			}
		}
	}

	if (sflag)
	{
		insertProperty(name, key.c_str(), s.c_str());
	}
	else if (dflag)
	{
		insertProperty(name, key.c_str(), d);
	}
	else if (bflag)
	{
		insertProperty(name, key.c_str(), b);
	}
}

bool iniFile::isWhiteSpace(char c)
{
	return (c == ' ' || c == '\r' || c == '\n' || c == '\t' || c == '\r\n');
}