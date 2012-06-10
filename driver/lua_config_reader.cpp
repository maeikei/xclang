#include "lua_config_reader.hpp"

#include <iostream>
#include <map>
using namespace std;

#define __XCLANG_ERROR__

lua_config_reader::lua_config_reader(const string &xc_home)
:m_state(NULL)
,m_xc_home(xc_home)
,m_error(0)
{
//	ttcode_log << endl;
	m_ls_home = m_xc_home + "/luaScript";
	m_state = luaL_newstate();
	luaL_openlibs(m_state);
	
	string initLuaStr;

	initLuaStr = "package.path = package.path..\";";
	initLuaStr += m_ls_home + "/?.lua\"";
	m_error = luaL_dostring(m_state,initLuaStr.c_str());
	if( m_error )
	{
		const char *msgError = lua_tostring(m_state, -1);
#ifdef __XCLANG_ERROR__
		cout << "msgError=<" << msgError << ">" << endl;
#endif
	}
}

lua_config_reader::~lua_config_reader()
{
	if(m_state)
	{
		lua_close(m_state);
		m_state = NULL;
	}
}



void lua_config_reader::getGlobal(const string &val,vector<string> &out)
{
	if( m_error )
	{
		const char *msgError = lua_tostring(m_state, -1);
#ifdef __XCLANG_ERROR__
		cout << "msgError=<" << msgError << ">" << endl;
#endif
		return;
	}
#ifdef __XCLANG_DEBUG__
	cout << "getGlobal start" << endl;
#endif
//	luabind::object table = luabind::globals(m_state)[val];
//	luabind::iterator it(table);
//	luabind::iterator itEnd;
//	for( ; it != itEnd ; it++ )
	{
//		string cmd = luabind::object_cast<string>(*it);
#ifdef __XCLANG_DEBUG__
//		cout << "cmd=<" << cmd << ">" << endl;
#endif
//		out.push_back(cmd);
	}
#ifdef __XCLANG_DEBUG__
	cout << "getGlobal end" << endl;
#endif
}
void lua_config_reader::getGlobal(const string &val,string &out)
{
	if( m_error )
	{
		const char *msgError = lua_tostring(m_state, -1);
#ifdef __XCLANG_ERROR__
		cout << "msgError=<" << msgError << ">" << endl;
#endif
		return;
	}
	try
	{
#ifdef __XCLANG_DEBUG__
		cout << "getGlobal start val=<" << val << ">>" << endl;
#endif
//		luabind::object obj = luabind::globals(m_state)[val];
//		string stringVal = luabind::object_cast<string>(obj);
//		out = stringVal.substr();
//		if(obj) 
		{
//			out = luabind::object_cast<string>(obj);
		}
#ifdef __XCLANG_DEBUG__
		cout << "out=<" << out << ">" << endl;
#endif
	}
	catch(const std::exception &e) 
	{
#ifdef __XCLANG_ERROR__
		cout << "getGlobal start val=<" << val << ">>" << endl;
		cout << "e=<" << e.what() << ">" << endl;
#endif
	}
}

int lua_config_reader::getCommandRet()
{
	int ret = 0;
	try
	{
#ifdef __XCLANG_DEBUG__
		cout << "getGlobal start val=<" << "globalExeRet" << ">>" << endl;
#endif
//		luabind::object obj = luabind::globals(m_state)["globalExeRet"];
//		if(obj) 
		{
//			ret = luabind::object_cast<int>(obj);
		}
#ifdef __XCLANG_DEBUG__
		cout << "ret=<" << ret << ">" << endl;
#endif
	}
	catch(const std::exception &e) 
	{
#ifdef __XCLANG_ERROR__
		cout << "getGlobal start val=<" << "globalExeRet" << ">>" << endl;
		cout << "e=<" << e.what() << ">" << endl;
#endif
	}
	return ret;
}
