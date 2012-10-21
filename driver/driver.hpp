#ifndef __DRIVER_HPP_
#define __DRIVER_HPP_
namespace xclang
{
class XClangDriver
    {
    public:
        XClangDriver(const int argc,const char **argv);
        int exce(void);
    private:
        XClangDriver();
    private:
        const int m_OrigArgc;
        const char **m_OrigArgv;
    };
}
#endif // __DRIVER_HPP_
