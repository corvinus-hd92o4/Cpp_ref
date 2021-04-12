/***************************************************************
 * Name:      wxkit16App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-09-06
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wxkit16App.h"

//(*AppHeaders
#include "wxkit16Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxkit16App);

bool wxkit16App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxkit16Frame* Frame = new wxkit16Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
