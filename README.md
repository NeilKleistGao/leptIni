# leptIni
leptIni是一个基于C++的ini文件读写库。<br/>
leptIni is a library based on C++.<br/>
这个库完全是作者拍脑袋决定并实现的，所以目前仅支持数字，字符串，布尔值三种数据类型，并且代码写得比较糟糕，性能得不到保证。如果你感兴趣，希望你可以帮助作者完善这部分内容。<br/>
This library is developed by accident. So It can only operate number, string, boolean data. The code may be horrible, and the performance may also be bad.If you are interested in it, I sincerely hope you can help me make it better.<br/>
使用leptIni时，你需要将所有的文件全部拷贝，但在代码中仅需包含一个头文件：<br/>
Before using leptIni, you should copy all files to your project, but only one header file need be included:
```c++
#include "iniFile.h"
```
如果你希望减少敲击键盘的次数，在保证没有重名的情况下，可以引用命名空间：<br/>
If you want to write less code, you can use namespace when there is no function having the same name:
```c++
using namespace leptIni;
```
你必须在创建对象时提供ini文件的文件名，这样我们可以及时解析文件：<br/>
You have to give the name of ini file when you create the object, which help to parse the file:
```c++
iniFile file("test.ini");
```
`iniFile`对象中包含了文件中的所有数据，你可以仅使用这个对象就实现对其中的节和属性进行操作：<br/>
`iniFile`object has all data in the ini file, so you can just use it to operate the sections and the properties in the file:
```c++
std::cout << file.getStringProperty("section1", "b") << std::endl;
file.insertSection("section3");
file.insertProperty("section3", "e", "EE Sama No Mercy");
```
对于所有的基本操作，都可以使用以下的函数完成。你不必阅读其他文件：<br/>
You can finish most of the basic operation using these functions below. Reading other files is not needed:
```c++
void insertSection(const std::string& name);
/*
插入一个节，这个节没有任何属性。如果有同名的节存在，则不做任何操作
Insert a new section to the file, which doesn't have any property. If there is already a section having the same name, no action will be done.

name:节的名称
name: the name of section
*/

void eraseSection(const std::string& name);
/*
删除一个节，以及其下的所有属性。如果不存在该名字的节，则不做任何操作
Delete a section and the properties in the section. If there is no section having this name, no action will be done.

name:节的名称
name: the name of section
*/

void insertProperty(const std::string& name ,const std::string& key, double d);
void insertProperty(const std::string& name, const std::string& key, const char* s);
void insertProperty(const std::string& name, const std::string& key, bool b);

/*
插入一个属性。属性所属的节必须已经存在。
Insert a property. The goal section must exist.

name:节的名称   key：属性的键   d/s/b：属性的值
name: the name of section   key: the key of property    d/s/b: the value of property
*/

void setProperty(const std::string& name, const std::string& key, double d);
void setProperty(const std::string& name, const std::string& key, const char* s);
void setProperty(const std::string& name, const std::string& key, bool b);
/*
修改一个属性。属性所属的节和属性必须已经存在。
Modify a property. The goal section and property must exist.

name:节的名称   key：属性的键   d/s/b：属性的值
name: the name of section   key: the key of property    d/s/b: the value of property
*/

double getNumberProperty(const std::string& name, const std::string& key, double def = 0.0);
const char* getStringProperty(const std::string& name, const std::string& key, const char* def = "");
bool getBooleanProperty(const std::string& name, const std::string& key, bool def = false);
/*
从属性中获取值。如果属性不存在，或属性的类型不匹配，则返回默认值
Get a value from the property. If the property doesn't exist, or the type is not matched, it will return the default value.

name:节的名称   key：属性的键   d/s/b：属性的默认值，可以忽略
name: the name of section   key: the key of property    d/s/b: the default value of property, which can be ignored
*/

void eraseProperty(const std::string& name ,const std::string& key);
/*
删除一个属性。
Delete a property.

name:节的名称   key：属性的键
name: the name of section   key: the key of property
*/

void save();
/*
保存文件。该函数在对象销毁时不会自动运行。这个函数会删掉文件中的所有注释！
Save the file. This function will not run automatically, and it will destroy all comment in the file!
*/
```
如果你希望阅读其它文件，我已经在其中加上了中文版的注释，并会在稍后补充英文版，以方便您的阅读。<br/>
If you are going to read other files, I will attach the English comment on them in order that you can read them more conviniently. Besides, Chinese comment has already been done.<br/>
非常感谢您的阅读和使用！<br/>
Thank you for your reading and using!<br/>