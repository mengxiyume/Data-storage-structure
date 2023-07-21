#pragma once

#include"IncludeLib.h"

typedef int LinkListStackDataType;
typedef LinkListStackDataType LLSDataType;

typedef struct LinkListStackNode {
	LLSDataType* data;
	struct LinkListStaccNode* prev;
	struct LinkListStaccNode* next;
}LLStack;