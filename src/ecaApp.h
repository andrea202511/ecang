/***************************************************************
 * Name:      ecaApp.h
 * Purpose:   Defines Application Class
 * Author:    AF ()
 * Created:   2021-11-11
 * Copyright: AF ()
 * License:
 **************************************************************/

#ifndef ECAAPP_H
#define ECAAPP_H

#include <wx/app.h>
#include <wx/config.h>
#include <wx/help.h>
#include <wx/fs_zip.h>



class ecaApp : public wxApp
{
    public:
        virtual bool OnInit();
        int OnExit();

    private:
        wxConfig* econfig;
        wxLocale* m_locale;

};

wxDECLARE_APP(ecaApp);

#endif // ECAAPP_H
