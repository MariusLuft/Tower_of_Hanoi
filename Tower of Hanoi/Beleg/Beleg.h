
// Beleg.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CBelegApp:
// Siehe Beleg.cpp für die Implementierung dieser Klasse
//

class CBelegApp : public CWinApp
{
public:
	CBelegApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CBelegApp theApp;
