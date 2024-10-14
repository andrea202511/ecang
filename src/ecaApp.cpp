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
  wxString sss;
    int language;
    bool bb;
    econfig=new wxConfig("ecang","AndreaF");
    econfig->Read(wxT("/language"),&language);
    delete econfig;

    m_locale=new wxLocale();

//   m_locale->AddCatalogLookupPathPrefix("/usr/share/locale");

    if (language==1)
      bb=m_locale->Init(wxLANGUAGE_ITALIAN,wxLOCALE_DONT_LOAD_DEFAULT);
    else if (language==2)
      bb=m_locale->Init(wxLANGUAGE_ENGLISH);
    else
      bb=m_locale->Init(wxLANGUAGE_DEFAULT);

    m_locale->AddCatalogLookupPathPrefix("/usr/share/locale");
    m_locale->AddCatalogLookupPathPrefix(".");

    if (bb)
      bb=m_locale->AddCatalog(wxT("ecang"));


    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
      ecaFrame* Frame = new ecaFrame(0);
      Frame->Show();
      SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}


