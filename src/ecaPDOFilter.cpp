#include "ecaPDOFilter.h"
#include "ecaPDO.h"
#include "ecaSlaves.h"


extern PDOArray ArrayPDO;
extern SLVArray ArraySlaves;


//(*InternalHeaders(ecaPDOFilter)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ecaPDOFilter)
const long ecaPDOFilter::ID_BUTTON2 = wxNewId();
const long ecaPDOFilter::ID_BUTTON3 = wxNewId();
const long ecaPDOFilter::ID_CHECKLISTBOX1 = wxNewId();
const long ecaPDOFilter::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ecaPDOFilter,wxDialog)
	//(*EventTable(ecaPDOFilter)
	//*)
END_EVENT_TABLE()

ecaPDOFilter::ecaPDOFilter(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ecaPDOFilter)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(300,420));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(300,400));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button2 = new wxButton(this, ID_BUTTON2, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 1, wxALL|wxEXPAND, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("Set all"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
	CheckListBox1 = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxVSCROLL, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	BoxSizer1->Add(CheckListBox1, 6, wxALL|wxEXPAND, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button1, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton3Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton1Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&ecaPDOFilter::OnInit);
	//*)
}

ecaPDOFilter::~ecaPDOFilter()
{
	//(*Destroy(ecaPDOFilter)
	//*)
}


void ecaPDOFilter::OnButton1Click(wxCommandEvent& event)
{
  uint16_t nr_slaves,d;
  nr_slaves=ArraySlaves.GetCount();
  d=nr_slaves*2;

  for(uint16_t i=0 ; i<nr_slaves;i++) {
    ArraySlaves[i].Reg_enable=CheckListBox1->IsChecked(i*2);
    ArraySlaves[i].Sdo_enable=CheckListBox1->IsChecked(i*2+1);
  }

  for(uint16_t i=d ; i<CheckListBox1->GetCount();i++) {
    ArrayPDO[i-d].enabled=CheckListBox1->IsChecked(i);
  }
  EndModal(wxID_OK);
}


void ecaPDOFilter::OnInit(wxInitDialogEvent& event)
{
  wxString str1;
  int ii=0;
  if (CheckListBox1->GetCount()==0) {
    for (unsigned int i=0; i<ArraySlaves.GetCount();i++) {
      str1="REG-";
      str1+=(ArraySlaves[i].Slave_name);
      CheckListBox1->InsertItems(1,&str1,ii);
      CheckListBox1->Check(i,ArraySlaves[i].Reg_enable);
      ii++;
      str1="SDO-";
      str1+=(ArraySlaves[i].Slave_name);
      CheckListBox1->InsertItems(1,&str1,ii);
      CheckListBox1->Check(i,ArraySlaves[i].Sdo_enable);
      ii++;
    }
    for (unsigned int i=0; i<ArrayPDO.GetCount();i++) {
      str1="PDO-";
      str1+=(ArrayPDO[i].PDO_name);
      CheckListBox1->InsertItems(1,&str1,ii);
      CheckListBox1->Check(i,ArrayPDO[i].enabled);
      ii++;
    }
  }
}

void ecaPDOFilter::OnButton2Click(wxCommandEvent& event)
{
  for(unsigned int i=0 ; i<CheckListBox1->GetCount();i++) {
    CheckListBox1->Check(i,false);
  }
}

void ecaPDOFilter::OnButton3Click(wxCommandEvent& event)
{
  for(unsigned int i=0 ; i<CheckListBox1->GetCount();i++) {
    CheckListBox1->Check(i,true);
  }
}
