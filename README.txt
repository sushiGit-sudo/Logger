
# Error Codes - See 'Logger.h' In src To See Variables:
	- 0: LOGGER_NONE_ERROR - There was no Error.
	- 1: LOGGER_VERTEX_EXISTS_ERROR - There Is No Error Vertex Or Warning Vertex.
	- 2: LOGGER_INDEX_ERROR - Your Index Is Greater Than Or Equal To The Vertex Size.
	- 3: LOGGER_INDEX_EXISTS_ERROR - The Index In Either Vertex Already Exists Or Doesn't Exist.

# How to Use - See 'Logger.cpp' In src To See Function Definitions:

	- Logger(unsigned int vertexSize) ###
		- Initalizes The Logger Object, 'vertexSize' Is The Size For Both Vertexs.

	- void AddError(int code, const char* message, const char* file, unsigned int line, unsigned int index) ###
		- Adds An Error Object To The Logger's Error Vertex.

	- Error* GetError(unsigned int index) const ###
		- Returns An Error Structure With The 'Error Code', 'Error Message', 'Error File', and 'Error Line'.

	- void RemoveError(unsigned int index) ###
		- Removes An Error Structure At The Given Index In Error Vertex.

	- void AssertError(unsigned int index) const ###
		- Prints The 'Error Message' Along With The 'Error File' and 'Error Line', Then Quits The Program.

	- void AddWarning(const char* message, unsigned int index) ###
		- Adds A Warning Message To The Logger's Warning Vertex.

	- const char* GetWarning(unsigned int index) const ###
		- Returns A Warning Message As A 'const char*'.

	- void RemoveWarning(unsigned int index) ###
		- Removes A Warning Message At The Given Index In Warning Vertex.

	- void PrintWarning(unsigned int index) const ###
		- Prints The Warning Message To The Screen. (Doesn't Quit The Program)

// Copyright (c) 2025 'Bitwise Studio'
// Licensed under the Apache 2.0 License. See LICENSE file in the project root for full license information.