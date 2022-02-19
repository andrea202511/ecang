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

class ecaApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ECAAPP_H
