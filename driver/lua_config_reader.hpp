#ifndef __lua_config_reader_H__
#define __lua_config_reader_H__

#include <lua.hpp>
#include <string>
#include <vector>
using namespace std;

#define __DEBUG__ 


class lua_config_reader
{
public:
    lua_config_reader(const string &xc_home);
    ~lua_config_reader();

	void getGlobal(const string &val,string &out);
	void getGlobal(const string &val,vector<string> &out);
protected:
	lua_State 	*m_state;
	string 		m_xc_home;
	string 		m_ls_home;
	int 		m_error;
private:
	int getCommandRet();
};

#endif // __lua_config_reader_H__