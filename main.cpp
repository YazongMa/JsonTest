/*************************************************************************
	> File Name: main.cpp
	> Author: Tim.Ma
	> Mail: mayazong@126.com 
	> Created Time: 2019年03月28日 11:31:58
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJson.h"

using namespace std;

// Key
#define JK_Act_Type                         "ActType"
#define JK_Act_Value                        "ActValue"


// ActType
#define JV_Act_AidList                      "ActAidList"
#define JV_Act_AidConfim                    "ActAidConfim"
#define JV_Act_TotalAmt                     "ActTotalAmt"
#define JV_Act_CallUBank                    "ActCallUBank"
#define JV_Act_ExceptionCheck               "ActExecptFileCheck"


/* Our "days of the week" array: */
const char *strings[7] =
{
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};


void Test(const char* pszJsonStr)
{
    printf("%s\n\n", pszJsonStr);

	cJSON* pcJsonRoot= cJSON_Parse(pszJsonStr);
	cJSON* pcSubItem = cJSON_GetObjectItem(pcJsonRoot, JK_Act_Type);
	printf("ActType:%s\n", pcSubItem->valuestring);

	pcSubItem = cJSON_GetObjectItem(pcJsonRoot, JK_Act_Value);
	if(NULL == pcSubItem)
	{
		printf("NULL\n");
		return;
	}

	int nArraySize = cJSON_GetArraySize(pcSubItem);
	printf("nArraySize:%d\n", nArraySize);
	for (int i=0; i<nArraySize; ++i)
	{
		cJSON* pcArrayItem = cJSON_GetArrayItem(pcSubItem, i);
		if (pcArrayItem == NULL)
			continue;
		printf("Index:%d, ArrayItem:%s\n", i, pcArrayItem->valuestring);
	}
}


int main()
{
	char szAppLabel[][17] = { 0 };
	for (int i=0; i<7; ++i)
	{
		strcpy(szAppLabel[i], strings[i]);
	}

    cJSON* pcJsonArray = NULL;
	cJSON* pcJsonRoot = cJSON_CreateObject();
    cJSON_AddItemToObject(pcJsonRoot, JK_Act_Type, cJSON_CreateString(JV_Act_AidList));
    
    cJSON_AddItemToObject(pcJsonRoot, JK_Act_Value, pcJsonArray = cJSON_CreateArray());
	for (int i=0; i<7; ++i)
		cJSON_AddItemToArray(pcJsonArray, cJSON_CreateString(strings[i]));
    
    char* pszJsonStr = cJSON_Print(pcJsonRoot);

	Test(pszJsonStr);
    
    cJSON_Delete(pcJsonRoot);
    free(pszJsonStr);



	char* pszTest = "1256";
	char szTest[13] = {0};
	sprintf(szTest, "%012s", pszTest);
	printf("szTest:%s\n", szTest);
	return 0;
}
