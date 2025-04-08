
// Copyright (c) 2025 'Bitwise Studio'
// Licensed under the Apache 2.0 License. See LICENSE file in the project root for full license information.

#pragma once


#define LOGGER_NONE_ERROR				0
#define LOGGER_VERTEX_EXISTS_ERROR		1
#define LOGGER_INDEX_ERROR				2
#define LOGGER_INDEX_EXISTS_ERROR		3


void ASSERT(int code, const char* message, const char* file, unsigned int line);
void WARN(const char* message, const char* file, unsigned int line);

struct Error
{
	int ErrorCode;
	char* ErrorMessage;
	char* ErrorFile;
	unsigned int ErrorLine;
};

class Logger
{
private:
	Error** m_ErrorVertex;
	char** m_WarningVertex;
	unsigned int m_VertexSize;
public:
	Logger(unsigned int vertexSize);
	~Logger();

	void AddError(int code, const char* message, const char* file, unsigned int line, unsigned int index);
	Error* GetError(unsigned int index) const;
	void RemoveError(unsigned int index);
	void AssertError(unsigned int index) const;

	void AddWarning(const char* message, unsigned int index);
	const char* GetWarning(unsigned int index) const;
	void RemoveWarning(unsigned int index);
	void PrintWarning(unsigned int index) const;
private:
	void SetValuesError();
	void SetValuesError(int code, const char* message);
	void SetValuesWarning();
	void SetValuesWarning(const char* message);
};