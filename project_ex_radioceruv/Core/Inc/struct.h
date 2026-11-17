
#ifndef INC_STRUCT_H_
#define INC_STRUCT_H_

#include "main.h"
#include <stdint.h>





#pragma pack(push, 1)
typedef struct
{

	bool redLight;
	bool yellowLight;
	bool greenLight;

} LedStatus;
#pragma pack(pop)



#endif
