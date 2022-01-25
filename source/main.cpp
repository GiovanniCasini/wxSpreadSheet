/************************************************************************************//**
* \file         main.cpp
* \brief        Application source file.
*
****************************************************************************************/

/****************************************************************************************
* Include files
****************************************************************************************/
#include "main.h"
/*#include "mainwindow.h"
#include "observer.h"*/
#include <wx/wxprec.h>
#include <wx/grid.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

/************************************************************************************//**
** \brief     Called upon application initialization. 
** \return    True if the initialization was successful. False if anything failed, which
**            prevents the application from continuing.
**
****************************************************************************************/

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Observer* OBS = new Observer();
    MyFrame *frame = new MyFrame(OBS);

    frame->Show(true);
    return true;
}

 /*** end of OnInit ***/
/*********************************** end of main.cpp ***********************************/