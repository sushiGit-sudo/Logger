
// Copyright (c) 2025 'Bitwise Studio'
// Licensed under the Apache 2.0 License. See LICENSE file in the project root for full license information.

#include "memory.h"

void memory::cpyFromToo(void* dest, void* src, unsigned int size)
{
	unsigned char* d = (unsigned char*)dest;
	unsigned char* s = (unsigned char*)src;

	for (unsigned int i = 0; i < size; i++)
		d[i] = s[i];
}

void memory::memoryCount(void* src, unsigned int& count)
{
	unsigned char* s = (unsigned char*)src;

	for (unsigned int i = 0; s[i]; i++)
		count++;
}

bool memory::memoryCmp(void* src1, void* src2, unsigned int size)
{
	unsigned char* s1 = (unsigned char*)src1;
	unsigned char* s2 = (unsigned char*)src2;
	
	for (unsigned int i = 0; i < size; i++)
	{
		if (!s1[i])
			return false;

		if (!s2[i])
			return false;

		if (s1[i] != s2[i])
			return false;
	}

	return true;
}
