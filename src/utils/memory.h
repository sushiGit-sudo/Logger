
// Copyright (c) 2025 'Bitwise Studio'
// Licensed under the Apache 2.0 License. See LICENSE file in the project root for full license information.

#pragma once


namespace memory
{
	void cpyFromToo(void* dest, void* src, unsigned int size);
	void memoryCount(void* src, unsigned int& count);
	bool memoryCmp(void* src1, void* src2, unsigned int size);
}