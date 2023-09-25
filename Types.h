/*
 * Types.h
 *
 * Created: 8/22/2023 11:11:04 PM
 *  Author: Bolis
 */

#ifndef TYPES_H_
#define TYPES_H_

#define F_CPU 8000000UL

#define NULL	((void*)0)

typedef unsigned char	uint8_t;
typedef signed char		int8_t;
typedef unsigned short	uint16_t;
typedef signed short	int16_t;
typedef unsigned int	uint32_t;
typedef signed int		int32_t;

#define SET_BIT(ADDRESS, BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS, BIT) (ADDRESS &= ~(1<<BIT))
#define TOGGLE_BIT(ADDRESS, BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS, BIT) ((ADDRESS & (1<<BIT)) >> BIT)

#endif /* TYPES_H_ */