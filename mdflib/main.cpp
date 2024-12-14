﻿#include "stdafx.h"
#include "ImportMdf4.h"
#include "mdf4.h"
#include <stdio.h>
#include <time.h>

int read() {
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

int main()
{
	read();
}

