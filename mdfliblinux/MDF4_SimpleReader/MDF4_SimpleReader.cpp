// MDF4_SimpleReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ImportMdf4.h"
#include "mdf4.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	CMdf4FileImport *pImport = new CMdf4FileImport;
	if (pImport->ImportFile("./Test.mf4"))
	{
		// Display the content of the file
		for (int i = 0; i < pImport->m_nDataGroups; i++)
		{
			CMdf4DataGroup *pGroup = pImport->m_vDataGroups[i];
			pImport->DisplayGroup(pGroup);
		}
	}
	else
	{
		printf("Error reading file\n");
	}
	return 0;
}

