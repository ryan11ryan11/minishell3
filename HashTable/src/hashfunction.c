/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashfunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:50:01 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 14:00:03 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../NearestPrime/libft/libft.h"
#include <stdint.h>
#include <stdlib.h>
#include "../hdrs/hashfuncconst.h"

static uint32_t	getuint_32t(const uint8_t *blocks)
{
	const int	blocksize = sizeof(uint32_t);
	int			i;
	uint32_t	tmp;

	i = 0;
	tmp = 0;
	while (i < blocksize && blocks[i])
	{
		tmp |= (uint32_t)(*blocks) << (i * HT_C_NBITS);
		++i;
	}
	return (tmp);
}

uint32_t	handlelastbts(uint32_t hash, const uint8_t *blocks, int len)
{
	uint32_t	tmp;
	uint32_t	data;

	data = 0;
	len &= 3;
	if (len == 3)
	{
		data ^= blocks[2] << MURMURSIZE / 2;
		--len;
	}
	if (len == 2)
	{
		data ^= blocks[1] << MURMURSIZE / 4;
		--len;
	}
	data ^= blocks[0];
	data *= C_1;
	data = (data << R_BYTES) | (data >> (MURMURSIZE - R_BYTES));
	data *= C_2;
	hash ^= data;
	return (hash);
}

uint32_t	setfinalhash(uint32_t hash, int len)
{
	hash ^= len;
	hash ^= hash >> 16;
	hash *= 0x85ebca6b;
	hash ^= hash >> 13;
	hash *= 0xc2b2ae35;
	hash ^= hash >> 16;
	return (hash);
}

uint32_t	murmur3_32(const char *str, int len, uint32_t hash)
{
	int				i;
	uint32_t		data;
	const uint32_t	*blocks;

	blocks = (const uint32_t *)str;
	i = len >> 2;
	while (i)
	{
		--i;
		data = *blocks;
		data *= C_1;
		data = (data << R_BYTES) | (data >> (MURMURSIZE - R_BYTES));
		data *= C_2;
		hash ^= data;
		hash = (hash << R_HASH) | (hash >> (MURMURSIZE - R_HASH));
		hash = hash * M + N;
		++blocks;
	}
	hash = handlelastbts(hash, (uint8_t *)blocks, len);
	return (setfinalhash(hash, len));
}

// int	main()
// {
// 	const char str[] = "Ing. Pavlo Olenych";
// 	printf("Result of hash function:\t%ld\n",
	// murmur3_32(str, sizeof(str), 0) % 101);
// 	return (0);
// }
	// switch (len & 3)
	// {
	// 	case (3):
	// 		data ^= blocks[2] << MURMURSIZE / 2;
	// 	case (2):
	// 		data ^= blocks[1] << MURMURSIZE / 4;
	// 	case (0):
	// 		data ^= blocks[0];#include <stdio.h>
	// 		data *= C_1;
	// 		data = (data << R_BYTES) | (data >> (MURMURSIZE - R_BYTES));
	// 		data *= C_2;
	// 		hash ^= data;
	// }