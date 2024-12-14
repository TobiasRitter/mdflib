#include "stdafx.h"
#include "ImportMdf4.h"
#include "mdf4.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <emscripten/emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
	int mf4read() {
		CMdf4FileImport* pImport = new CMdf4FileImport;
		if (pImport->ImportFile("./Test.mf4"))
		{
			for (int i = 0; i < pImport->m_nDataGroups; i++)
			{
				CMdf4DataGroup *pGroup = pImport->m_vDataGroups[i];
				pImport->DisplayGroup(pGroup);
			}
		}
		else
		{
			std::cout << "Error reading file\n";
		}
		delete pImport;
		return 0;
	}
}
