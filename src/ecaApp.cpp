/***************************************************************
 * Name:      ecaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    AF ()
 * Created:   2021-11-11
 * Copyright: AF ()
 * License:
 **************************************************************/

#include "ecaApp.h"

//(*AppHeaders
#include "ecaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ecaApp);

bool ecaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ecaDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
