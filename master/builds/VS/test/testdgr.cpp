#include <iostream>
#include "myLogMacros.h"
using namespace std;
USING_DGR
USING_LGT

int main()
{
    InitLoggers();
    int x = 10;
    const xCharT* y = XT("fdfdf");
    float z = 20.15f;
// 			
    MY_LOG_DBG(XT("x=%d y=%s z = %f\r\n"), x, y, z);
    MY_LOG_INFO(XT("x=%d y=%s z = %f\r\n"), x, y, z);
    MY_LOG_WARN(XT("x=%d y=%s z = %f\r\n"), x, y, z);
    MY_LOG_ERR(XT("x=%d y=%s z = %f\r\n"), x, y, z);
    MY_LOG_FATAL(XT("x=%d y=%s z = %f\r\n"), x, y, z);
// 
    MY_LOG_DBG2 << lbt << x << " " << y << "  0 " << z <<lbt << endt;
    MY_LOG_INFO2 << lbt << x << " " << y << " 1 " << z << endt;
    MY_LOG_WARN2 << lbt << x << " " << y << " 2 " << z << endt;
    MY_LOG_ERR2 << lbt << x << " " << y << " 2 " << z << endt;
    MY_LOG_FATAL2 << lbt << x << " " << y << " 2 " << z << endt;
}

