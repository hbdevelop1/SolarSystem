


#include <math.h>

#include <limits>

//#define	    IsZero(x)	(fabs(x) <= std::numeric_limits<double>::epsilon())  
//std::numeric_limits<double>::epsilon() is too little, particularly for "test 12/07/2011-13:19:56".
#define	    IsZero(x)	(fabs(x) <= 1.e-06)  



#define M_PI          3.14159265358979323846
