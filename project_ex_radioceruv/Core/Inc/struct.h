
#ifndef INC_STRUCT_H_
#define INC_STRUCT_H_

#include "main.h"
#include <stdint.h>
#include <stdbool.h>

#define STANDART_DEL 2000


#pragma pack(push, 1)
typedef struct
{

	bool redLight;
	bool yellowLight;
	bool greenLight;

} LedStatus;
#pragma pack(pop)



#pragma pack(push, 1)
typedef struct
{

	uint8_t redLight;
	uint8_t yellowLight;
	uint8_t greenLight;

} LedPWMStatus;
#pragma pack(pop)





#endif
