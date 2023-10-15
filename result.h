#ifndef _RESULT_H
#define _RESULT_H

#ifndef Result
#define Result(errType, dataType) struct { errType error; dataType data; }
#endif

#endif /* result.h  */
