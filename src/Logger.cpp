
// Copyright (c) 2025 'Bitwise Studio'
// Licensed under the Apache 2.0 License. See LICENSE file in the project root for full license information.

#include "Logger.h"
#include "utils/memory.h"

#include <iostream>

void ASSERT(int code, const char* message, const char* file, unsigned int line)
{
	std::cout << message << " | File: " << file << ":" << line << std::endl;
	exit(code);
}

void WARN(const char* message, const char* file, unsigned int line)
{
	std::cout << message << " | File: " << file << ":" << line;
}

Logger::Logger(unsigned int vertexSize)
	: m_ErrorVertex(nullptr), m_WarningVertex(nullptr), m_VertexSize(vertexSize)
{
	m_ErrorVertex = new Error*[m_VertexSize];
	m_WarningVertex = new char*[m_VertexSize];
	SetValuesError();
	SetValuesWarning();
}

Logger::~Logger()
{
	if (m_ErrorVertex)
		delete[] m_ErrorVertex;

	if (m_WarningVertex)
		delete[] m_WarningVertex;
}

void Logger::AddError(int code, const char* message, const char* file, unsigned int line, unsigned int index)
{
	if (!m_ErrorVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Error Vertex does NOT exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (m_ErrorVertex[index])
		ASSERT(LOGGER_INDEX_EXISTS_ERROR, "[LOGGER]: Error Vertex Index Exists", __FILE__, __LINE__);

	Error* error = new Error;
	error->ErrorCode = code;
	error->ErrorMessage = (char*)message;
	error->ErrorFile = (char*)file;
	error->ErrorLine = line;

	m_ErrorVertex[index] = error;
}

Error* Logger::GetError(unsigned int index) const
{
	if (!m_ErrorVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Error Vertex Does NOT Exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (!m_ErrorVertex[index])
		ASSERT(LOGGER_INDEX_EXISTS_ERROR, "[LOGGER]: Error Vertex Index Does NOT Exist", __FILE__, __LINE__);

	return m_ErrorVertex[index];
}

void Logger::RemoveError(unsigned int index)
{
	if (!m_ErrorVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Error Vertex does NOT exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (!m_ErrorVertex[index])
	{
		WARN("[LOGGER]: Error Vertex Index Does NOT Exist", __FILE__, __LINE__);
		return;
	}

	delete m_ErrorVertex[index];
	m_ErrorVertex[index] = nullptr;
}

void Logger::AssertError(unsigned int index) const
{
	if (!m_ErrorVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Error Vertex does NOT exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (!m_ErrorVertex[index])
		ASSERT(LOGGER_INDEX_EXISTS_ERROR, "[LOGGER]: Error Vertex Index Does NOT Exist", __FILE__, __LINE__);

	ASSERT(m_ErrorVertex[index]->ErrorCode, m_ErrorVertex[index]->ErrorMessage, m_ErrorVertex[index]->ErrorFile, m_ErrorVertex[index]->ErrorLine);
}

void Logger::AddWarning(const char* message, unsigned int index)
{
	if (!m_WarningVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex does NOT exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (!m_WarningVertex[index])
		ASSERT(LOGGER_INDEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex Index Exists", __FILE__, __LINE__);

	unsigned int warningSize;
	memory::memoryCount((void*)message, warningSize);
	const char* warning = new char[warningSize];
	memory::cpyFromToo((void*)warning, (void*)message, warningSize);

	m_WarningVertex[index] = (char*)warning;
}

const char* Logger::GetWarning(unsigned int index) const
{
	if (!m_WarningVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex does NOT exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (!m_WarningVertex[index])
		ASSERT(LOGGER_INDEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex Index Does NOT Exist", __FILE__, __LINE__);

	return m_WarningVertex[index];
}

void Logger::RemoveWarning(unsigned int index)
{
	if (!m_WarningVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex does NOT exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (m_WarningVertex[index])
	{
		WARN("[LOGGER]: Warning Vertex Index Does NOT Exist", __FILE__, __LINE__);
		return;
	}

	delete[] m_WarningVertex[index];
	m_WarningVertex[index] = nullptr;
}

void Logger::PrintWarning(unsigned int index) const
{
	if (!m_WarningVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex does NOT exist.", __FILE__, __LINE__);

	if (index >= m_VertexSize)
		ASSERT(LOGGER_INDEX_ERROR, "[LOGGER]: Index is greater than or equal to Vertex Size.", __FILE__, __LINE__);

	if (!m_WarningVertex[index])
		ASSERT(LOGGER_INDEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex Index Does NOT Exist", __FILE__, __LINE__);

	std::cout << m_WarningVertex[index];
}

void Logger::SetValuesError()
{
	if (!m_ErrorVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Error Vertex does NOT exist.", __FILE__, __LINE__);

	for (unsigned int i = 0; i < m_VertexSize; i++)
	{
		m_ErrorVertex[i] = nullptr;
	}
}

void Logger::SetValuesError(int code, const char* message)
{
	if (!m_ErrorVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Error Vertex does NOT exist.", __FILE__, __LINE__);

	for (unsigned int i = 0; i < m_VertexSize; i++)
	{
		Error* error = new Error;
		error->ErrorCode = code;
		error->ErrorMessage = (char*)message;

		m_ErrorVertex[i] = error;
	}
}

void Logger::SetValuesWarning()
{
	if (!m_WarningVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex does NOT exist.", __FILE__, __LINE__);

	for (unsigned int i = 0; i < m_VertexSize; i++)
	{
		m_WarningVertex[i] = nullptr;
	}
}

void Logger::SetValuesWarning(const char* message)
{
	if (!m_WarningVertex)
		ASSERT(LOGGER_VERTEX_EXISTS_ERROR, "[LOGGER]: Warning Vertex does NOT exist.", __FILE__, __LINE__);

	for (unsigned int i = 0; i < m_VertexSize; i++)
	{
		unsigned int warningSize;
		memory::memoryCount((void*)message, warningSize);
		const char* warning = new char[warningSize];
		memory::cpyFromToo((void*)warning, (void*)message, warningSize);

		m_WarningVertex[i] = (char*)warning;
	}
}
