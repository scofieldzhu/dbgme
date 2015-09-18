#include <iostream>
#include "levels.h"
#include "xtime.h"
// #include "myLogMacros.h"
// #include "loggerParser.h"
using namespace std;
USING_DBGER2
USING_LGT

//LoggerParser parser(XT("logger-conf.xml"));

int main()
{    
    std::xStrT x;
    DateTime::Now().ReprTo(x);

    
    std::cout << x << endl;
  //  parser.Parse();

// 	InitLoggers();
// 	int x = 10;
// 	const char* y = "fdfdf";
// 	float z = 20.15f;
// 			
// 	MY_LOG_DBG("x=%d y=%s z = %f\r\n", x, y, z);
//     MY_LOG_INFO("x=%d y=%s z = %f\r\n", x, y, z);
//     MY_LOG_WARN("x=%d y=%s z = %f\r\n", x, y, z);
//     MY_LOG_ERR("x=%d y=%s z = %f\r\n", x, y, z);
//     MY_LOG_FATAL("x=%d y=%s z = %f\r\n", x, y, z);
// 
// 	MY_LOG_DBG2 << lbt << x << " " << y << "  0 " << z <<lbt << endt;
// 	MY_LOG_INFO2 << lbt << x << " " << y << " 1 " << z << endt;
// 	MY_LOG_WARN2 << lbt << x << " " << y << " 2 " << z << endt;
// 	MY_LOG_ERR2 << lbt << x << " " << y << " 2 " << z << endt;
// 	MY_LOG_FATAL2 << lbt << x << " " << y << " 2 " << z << endt;

	return 0;
}