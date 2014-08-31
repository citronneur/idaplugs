
/*****************************************************************************
 *                                                                           *
 *  plugrare.cpp: ida plugins shared code                                    *
 *  (c) 2003-2008 servil                                                     *
 *                                                                           *
 *****************************************************************************/

#include <cstdio>
#define NOMINMAX 1
#include <windows.h>
#include <CommCtrl.h>
#include <Richedit.h>

#define CB_MULTIPLEADDSTRING            0x0163
#define LB_MULTIPLEADDSTRING            0x01B1

const char *GetMessageName(UINT uMsg) {
	switch (uMsg) {
#define TOKENIZE_EVENT(x) case x: return #x;
		TOKENIZE_EVENT(WM_ACTIVATE)
		TOKENIZE_EVENT(WM_ACTIVATEAPP)
		TOKENIZE_EVENT(WM_AFXFIRST)
		TOKENIZE_EVENT(WM_AFXLAST)
		TOKENIZE_EVENT(WM_APP)
		TOKENIZE_EVENT(WM_APPCOMMAND)
		TOKENIZE_EVENT(WM_ASKCBFORMATNAME)
		TOKENIZE_EVENT(WM_CANCELJOURNAL)
		TOKENIZE_EVENT(WM_CANCELMODE)
		TOKENIZE_EVENT(WM_CAPTURECHANGED)
		TOKENIZE_EVENT(WM_CLEAR)
		TOKENIZE_EVENT(WM_CLOSE)
		TOKENIZE_EVENT(WM_COMMAND)
		TOKENIZE_EVENT(WM_COMMNOTIFY)
		TOKENIZE_EVENT(WM_COMPACTING)
		TOKENIZE_EVENT(WM_COMPAREITEM)
		TOKENIZE_EVENT(WM_CONTEXTMENU)
		TOKENIZE_EVENT(WM_COPY)
		TOKENIZE_EVENT(WM_COPYDATA)
		TOKENIZE_EVENT(WM_CREATE)
		TOKENIZE_EVENT(WM_CTLCOLORBTN)
		TOKENIZE_EVENT(WM_CTLCOLORDLG)
		TOKENIZE_EVENT(WM_CTLCOLOREDIT)
		TOKENIZE_EVENT(WM_CTLCOLORLISTBOX)
		TOKENIZE_EVENT(WM_CTLCOLORMSGBOX)
		TOKENIZE_EVENT(WM_CTLCOLORSCROLLBAR)
		TOKENIZE_EVENT(WM_CTLCOLORSTATIC)
		TOKENIZE_EVENT(WM_CUT)
		TOKENIZE_EVENT(WM_DDE_ACK)
		TOKENIZE_EVENT(WM_DDE_ADVISE)
		TOKENIZE_EVENT(WM_DDE_DATA)
		TOKENIZE_EVENT(WM_DDE_EXECUTE)
		TOKENIZE_EVENT(WM_DDE_INITIATE)
		TOKENIZE_EVENT(WM_DDE_POKE)
		TOKENIZE_EVENT(WM_DDE_REQUEST)
		TOKENIZE_EVENT(WM_DDE_TERMINATE)
		TOKENIZE_EVENT(WM_DDE_UNADVISE)
		TOKENIZE_EVENT(WM_DEADCHAR)
		TOKENIZE_EVENT(WM_DELETEITEM)
		TOKENIZE_EVENT(WM_DESTROY)
		TOKENIZE_EVENT(WM_DESTROYCLIPBOARD)
		TOKENIZE_EVENT(WM_DEVICECHANGE)
		TOKENIZE_EVENT(WM_DEVMODECHANGE)
		TOKENIZE_EVENT(WM_DISPLAYCHANGE)
		TOKENIZE_EVENT(WM_DRAWCLIPBOARD)
		TOKENIZE_EVENT(WM_DRAWITEM)
		TOKENIZE_EVENT(WM_DROPFILES)
		TOKENIZE_EVENT(WM_ENABLE)
		TOKENIZE_EVENT(WM_ENDSESSION)
		TOKENIZE_EVENT(WM_ENTERIDLE)
		TOKENIZE_EVENT(WM_ENTERMENULOOP)
		TOKENIZE_EVENT(WM_ENTERSIZEMOVE)
		TOKENIZE_EVENT(WM_ERASEBKGND)
		TOKENIZE_EVENT(WM_EXITMENULOOP)
		TOKENIZE_EVENT(WM_EXITSIZEMOVE)
		TOKENIZE_EVENT(WM_FONTCHANGE)
		TOKENIZE_EVENT(WM_GETDLGCODE)
		TOKENIZE_EVENT(WM_GETFONT)
		TOKENIZE_EVENT(WM_GETHOTKEY)
		TOKENIZE_EVENT(WM_GETICON)
		TOKENIZE_EVENT(WM_GETMINMAXINFO)
		TOKENIZE_EVENT(WM_GETOBJECT)
		TOKENIZE_EVENT(WM_GETTEXT)
		TOKENIZE_EVENT(WM_GETTEXTLENGTH)
		TOKENIZE_EVENT(WM_HANDHELDFIRST)
		TOKENIZE_EVENT(WM_HANDHELDLAST)
		TOKENIZE_EVENT(WM_HELP)
		TOKENIZE_EVENT(WM_HOTKEY)
		TOKENIZE_EVENT(WM_HSCROLL)
		TOKENIZE_EVENT(WM_HSCROLLCLIPBOARD)
		TOKENIZE_EVENT(WM_CHANGECBCHAIN)
		TOKENIZE_EVENT(WM_CHANGEUISTATE)
		TOKENIZE_EVENT(WM_CHAR)
		TOKENIZE_EVENT(WM_CHARTOITEM)
		TOKENIZE_EVENT(WM_CHILDACTIVATE)
		TOKENIZE_EVENT(WM_ICONERASEBKGND)
		TOKENIZE_EVENT(WM_IME_COMPOSITION)
		TOKENIZE_EVENT(WM_IME_COMPOSITIONFULL)
		TOKENIZE_EVENT(WM_IME_CONTROL)
		TOKENIZE_EVENT(WM_IME_ENDCOMPOSITION)
		TOKENIZE_EVENT(WM_IME_CHAR)
		TOKENIZE_EVENT(WM_IME_KEYDOWN)
		TOKENIZE_EVENT(WM_IME_KEYUP)
		//TOKENIZE_EVENT(WM_IME_KEYLAST)
		TOKENIZE_EVENT(WM_IME_NOTIFY)
		TOKENIZE_EVENT(WM_IME_REQUEST)
		TOKENIZE_EVENT(WM_IME_SELECT)
		TOKENIZE_EVENT(WM_IME_SETCONTEXT)
		TOKENIZE_EVENT(WM_IME_STARTCOMPOSITION)
		TOKENIZE_EVENT(WM_INITDIALOG)
		TOKENIZE_EVENT(WM_INITMENU)
		TOKENIZE_EVENT(WM_INITMENUPOPUP)
		TOKENIZE_EVENT(WM_INPUT)
		TOKENIZE_EVENT(WM_INPUTLANGCHANGE)
		TOKENIZE_EVENT(WM_INPUTLANGCHANGEREQUEST)
		//TOKENIZE_EVENT(WM_KEYFIRST)
		TOKENIZE_EVENT(WM_KEYDOWN)
		TOKENIZE_EVENT(WM_KEYUP)
		//TOKENIZE_EVENT(WM_KEYLAST)
		TOKENIZE_EVENT(WM_KILLFOCUS)
		TOKENIZE_EVENT(WM_LBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_LBUTTONDOWN)
		TOKENIZE_EVENT(WM_LBUTTONUP)
		TOKENIZE_EVENT(WM_MBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_MBUTTONDOWN)
		TOKENIZE_EVENT(WM_MBUTTONUP)
		TOKENIZE_EVENT(WM_MDIACTIVATE)
		TOKENIZE_EVENT(WM_MDICASCADE)
		TOKENIZE_EVENT(WM_MDICREATE)
		TOKENIZE_EVENT(WM_MDIDESTROY)
		TOKENIZE_EVENT(WM_MDIGETACTIVE)
		TOKENIZE_EVENT(WM_MDIICONARRANGE)
		TOKENIZE_EVENT(WM_MDIMAXIMIZE)
		TOKENIZE_EVENT(WM_MDINEXT)
		TOKENIZE_EVENT(WM_MDIREFRESHMENU)
		TOKENIZE_EVENT(WM_MDIRESTORE)
		TOKENIZE_EVENT(WM_MDISETMENU)
		TOKENIZE_EVENT(WM_MDITILE)
		TOKENIZE_EVENT(WM_MEASUREITEM)
		TOKENIZE_EVENT(WM_MENUCOMMAND)
		TOKENIZE_EVENT(WM_MENUDRAG)
		TOKENIZE_EVENT(WM_MENUGETOBJECT)
		TOKENIZE_EVENT(WM_MENUCHAR)
		TOKENIZE_EVENT(WM_MENURBUTTONUP)
		TOKENIZE_EVENT(WM_MENUSELECT)
		TOKENIZE_EVENT(WM_MOUSEACTIVATE)
		//TOKENIZE_EVENT(WM_MOUSEFIRST)
		TOKENIZE_EVENT(WM_MOUSEHOVER)
		TOKENIZE_EVENT(WM_MOUSELEAVE)
		TOKENIZE_EVENT(WM_MOUSEMOVE)
		TOKENIZE_EVENT(WM_MOUSEWHEEL)
		//TOKENIZE_EVENT(WM_MOUSELAST)
		TOKENIZE_EVENT(WM_MOVE)
		TOKENIZE_EVENT(WM_MOVING)
		TOKENIZE_EVENT(WM_NCACTIVATE)
		TOKENIZE_EVENT(WM_NCCALCSIZE)
		TOKENIZE_EVENT(WM_NCCREATE)
		TOKENIZE_EVENT(WM_NCDESTROY)
		TOKENIZE_EVENT(WM_NCLBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_NCLBUTTONDOWN)
		TOKENIZE_EVENT(WM_NCLBUTTONUP)
		TOKENIZE_EVENT(WM_NCMBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_NCMBUTTONDOWN)
		TOKENIZE_EVENT(WM_NCMBUTTONUP)
		TOKENIZE_EVENT(WM_NCMOUSEHOVER)
		TOKENIZE_EVENT(WM_NCMOUSELEAVE)
		TOKENIZE_EVENT(WM_NCMOUSEMOVE)
		TOKENIZE_EVENT(WM_NCPAINT)
		TOKENIZE_EVENT(WM_NCRBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_NCRBUTTONDOWN)
		TOKENIZE_EVENT(WM_NCRBUTTONUP)
		TOKENIZE_EVENT(WM_NCXBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_NCXBUTTONDOWN)
		TOKENIZE_EVENT(WM_NCXBUTTONUP)
		TOKENIZE_EVENT(WM_NEXTDLGCTL)
		TOKENIZE_EVENT(WM_NEXTMENU)
		TOKENIZE_EVENT(WM_NCHITTEST)
		TOKENIZE_EVENT(WM_NOTIFY)
		TOKENIZE_EVENT(WM_NOTIFYFORMAT)
		TOKENIZE_EVENT(WM_NULL)
		TOKENIZE_EVENT(WM_PAINT)
		TOKENIZE_EVENT(WM_PAINTCLIPBOARD)
		TOKENIZE_EVENT(WM_PAINTICON)
		TOKENIZE_EVENT(WM_PALETTECHANGED)
		TOKENIZE_EVENT(WM_PALETTEISCHANGING)
		TOKENIZE_EVENT(WM_PARENTNOTIFY)
		TOKENIZE_EVENT(WM_PASTE)
		TOKENIZE_EVENT(WM_PENWINFIRST)
		TOKENIZE_EVENT(WM_PENWINLAST)
		TOKENIZE_EVENT(WM_POWER)
		TOKENIZE_EVENT(WM_POWERBROADCAST)
		TOKENIZE_EVENT(WM_PRINT)
		TOKENIZE_EVENT(WM_PRINTCLIENT)
		TOKENIZE_EVENT(WM_QUERYDRAGICON)
		TOKENIZE_EVENT(WM_QUERYENDSESSION)
		TOKENIZE_EVENT(WM_QUERYNEWPALETTE)
		TOKENIZE_EVENT(WM_QUERYOPEN)
		TOKENIZE_EVENT(WM_QUERYUISTATE)
		TOKENIZE_EVENT(WM_QUEUESYNC)
		TOKENIZE_EVENT(WM_QUIT)
		TOKENIZE_EVENT(WM_RBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_RBUTTONDOWN)
		TOKENIZE_EVENT(WM_RBUTTONUP)
		TOKENIZE_EVENT(WM_RENDERALLFORMATS)
		TOKENIZE_EVENT(WM_RENDERFORMAT)
		TOKENIZE_EVENT(WM_SETCURSOR)
		TOKENIZE_EVENT(WM_SETFOCUS)
		TOKENIZE_EVENT(WM_SETFONT)
		TOKENIZE_EVENT(WM_SETHOTKEY)
		TOKENIZE_EVENT(WM_SETICON)
		TOKENIZE_EVENT(WM_SETREDRAW)
		TOKENIZE_EVENT(WM_SETTEXT)
		TOKENIZE_EVENT(WM_SETTINGCHANGE)
		TOKENIZE_EVENT(WM_SHOWWINDOW)
		TOKENIZE_EVENT(WM_SIZE)
		TOKENIZE_EVENT(WM_SIZECLIPBOARD)
		TOKENIZE_EVENT(WM_SIZING)
		TOKENIZE_EVENT(WM_SPOOLERSTATUS)
		TOKENIZE_EVENT(WM_STYLECHANGED)
		TOKENIZE_EVENT(WM_STYLECHANGING)
		TOKENIZE_EVENT(WM_SYNCPAINT)
		TOKENIZE_EVENT(WM_SYSCOLORCHANGE)
		TOKENIZE_EVENT(WM_SYSCOMMAND)
		TOKENIZE_EVENT(WM_SYSDEADCHAR)
		TOKENIZE_EVENT(WM_SYSCHAR)
		TOKENIZE_EVENT(WM_SYSKEYDOWN)
		TOKENIZE_EVENT(WM_SYSKEYUP)
		TOKENIZE_EVENT(WM_TABLET_FIRST)
		TOKENIZE_EVENT(WM_TABLET_LAST)
		TOKENIZE_EVENT(WM_TCARD)
		TOKENIZE_EVENT(WM_THEMECHANGED)
		TOKENIZE_EVENT(WM_TIMECHANGE)
		TOKENIZE_EVENT(WM_TIMER)
		TOKENIZE_EVENT(WM_UNDO)
		TOKENIZE_EVENT(WM_UNICHAR)
		TOKENIZE_EVENT(WM_UNINITMENUPOPUP)
		TOKENIZE_EVENT(WM_UPDATEUISTATE)
		//TOKENIZE_EVENT(WM_USER)
		TOKENIZE_EVENT(WM_USERCHANGED)
		TOKENIZE_EVENT(WM_VKEYTOITEM)
		TOKENIZE_EVENT(WM_VSCROLL)
		TOKENIZE_EVENT(WM_VSCROLLCLIPBOARD)
		TOKENIZE_EVENT(WM_WINDOWPOSCHANGED)
		TOKENIZE_EVENT(WM_WINDOWPOSCHANGING)
		//TOKENIZE_EVENT(WM_WININICHANGE)
		TOKENIZE_EVENT(WM_WTSSESSION_CHANGE)
		TOKENIZE_EVENT(WM_XBUTTONDBLCLK)
		TOKENIZE_EVENT(WM_XBUTTONDOWN)
		TOKENIZE_EVENT(WM_XBUTTONUP)
		// Dialog specific
		TOKENIZE_EVENT(DM_GETDEFID)
		TOKENIZE_EVENT(DM_SETDEFID)
		TOKENIZE_EVENT(DM_REPOSITION)
		// MFC specific
		case 0x0019: return "WM_CTLCOLOR";
		case 0x0363: return "WM_IDLEUPDATECMDUI";
		case 0x0366: return "WM_HELPHITTEST";
		case 0x0368: return "WM_RECALCPARENT";
		case 0x036A: return "WM_KICKIDLE";
		case 0x036D: return "WM_FLOATSTATUS";
		// Edit
		TOKENIZE_EVENT(EM_CANUNDO)
		TOKENIZE_EVENT(EM_CHARFROMPOS)
		TOKENIZE_EVENT(EM_EMPTYUNDOBUFFER)
		TOKENIZE_EVENT(EM_FMTLINES)
		TOKENIZE_EVENT(EM_GETFIRSTVISIBLELINE)
		TOKENIZE_EVENT(EM_GETHANDLE)
		TOKENIZE_EVENT(EM_GETIMESTATUS)
		TOKENIZE_EVENT(EM_GETLIMITTEXT)
		TOKENIZE_EVENT(EM_GETLINE)
		TOKENIZE_EVENT(EM_GETLINECOUNT)
		TOKENIZE_EVENT(EM_GETMARGINS)
		TOKENIZE_EVENT(EM_GETMODIFY)
		TOKENIZE_EVENT(EM_GETPASSWORDCHAR)
		TOKENIZE_EVENT(EM_GETRECT)
		TOKENIZE_EVENT(EM_GETSEL)
		TOKENIZE_EVENT(EM_GETTHUMB)
		TOKENIZE_EVENT(EM_GETWORDBREAKPROC)
		TOKENIZE_EVENT(EM_LIMITTEXT)
		TOKENIZE_EVENT(EM_LINEFROMCHAR)
		TOKENIZE_EVENT(EM_LINEINDEX)
		TOKENIZE_EVENT(EM_LINELENGTH)
		TOKENIZE_EVENT(EM_LINESCROLL)
		TOKENIZE_EVENT(EM_POSFROMCHAR)
		TOKENIZE_EVENT(EM_REPLACESEL)
		TOKENIZE_EVENT(EM_SCROLL)
		TOKENIZE_EVENT(EM_SCROLLCARET)
		TOKENIZE_EVENT(EM_SETHANDLE)
		TOKENIZE_EVENT(EM_SETIMESTATUS)
		TOKENIZE_EVENT(EM_SETMARGINS)
		TOKENIZE_EVENT(EM_SETMODIFY)
		TOKENIZE_EVENT(EM_SETPASSWORDCHAR)
		TOKENIZE_EVENT(EM_SETREADONLY)
		TOKENIZE_EVENT(EM_SETRECT)
		TOKENIZE_EVENT(EM_SETRECTNP)
		TOKENIZE_EVENT(EM_SETSEL)
		TOKENIZE_EVENT(EM_SETTABSTOPS)
		TOKENIZE_EVENT(EM_SETWORDBREAKPROC)
		TOKENIZE_EVENT(EM_UNDO)
		// ComboBox
		TOKENIZE_EVENT(CB_ADDSTRING)
		TOKENIZE_EVENT(CB_DELETESTRING)
		TOKENIZE_EVENT(CB_DIR)
		TOKENIZE_EVENT(CB_FINDSTRING)
		TOKENIZE_EVENT(CB_FINDSTRINGEXACT)
		TOKENIZE_EVENT(CB_GETCOMBOBOXINFO)
		TOKENIZE_EVENT(CB_GETCOUNT)
		TOKENIZE_EVENT(CB_GETCURSEL)
		TOKENIZE_EVENT(CB_GETDROPPEDCONTROLRECT)
		TOKENIZE_EVENT(CB_GETDROPPEDSTATE)
		TOKENIZE_EVENT(CB_GETDROPPEDWIDTH)
		TOKENIZE_EVENT(CB_GETEDITSEL)
		TOKENIZE_EVENT(CB_GETEXTENDEDUI)
		TOKENIZE_EVENT(CB_GETHORIZONTALEXTENT)
		TOKENIZE_EVENT(CB_GETITEMDATA)
		TOKENIZE_EVENT(CB_GETITEMHEIGHT)
		TOKENIZE_EVENT(CB_GETLBTEXT)
		TOKENIZE_EVENT(CB_GETLBTEXTLEN)
		TOKENIZE_EVENT(CB_GETLOCALE)
		TOKENIZE_EVENT(CB_GETTOPINDEX)
		TOKENIZE_EVENT(CB_INITSTORAGE)
		TOKENIZE_EVENT(CB_INSERTSTRING)
		TOKENIZE_EVENT(CB_LIMITTEXT)
		TOKENIZE_EVENT(CB_MSGMAX)
		TOKENIZE_EVENT(CB_MULTIPLEADDSTRING)
		TOKENIZE_EVENT(CB_RESETCONTENT)
		TOKENIZE_EVENT(CB_SELECTSTRING)
		TOKENIZE_EVENT(CB_SETCURSEL)
		TOKENIZE_EVENT(CB_SETDROPPEDWIDTH)
		TOKENIZE_EVENT(CB_SETEDITSEL)
		TOKENIZE_EVENT(CB_SETEXTENDEDUI)
		TOKENIZE_EVENT(CB_SETHORIZONTALEXTENT)
		TOKENIZE_EVENT(CB_SETITEMDATA)
		TOKENIZE_EVENT(CB_SETITEMHEIGHT)
		TOKENIZE_EVENT(CB_SETLOCALE)
		TOKENIZE_EVENT(CB_SETTOPINDEX)
		TOKENIZE_EVENT(CB_SHOWDROPDOWN)
		// ListBox
		TOKENIZE_EVENT(LB_ADDFILE)
		TOKENIZE_EVENT(LB_ADDSTRING)
		TOKENIZE_EVENT(LB_DELETESTRING)
		TOKENIZE_EVENT(LB_DIR)
		TOKENIZE_EVENT(LB_FINDSTRING)
		TOKENIZE_EVENT(LB_FINDSTRINGEXACT)
		TOKENIZE_EVENT(LB_GETANCHORINDEX)
		TOKENIZE_EVENT(LB_GETCARETINDEX)
		TOKENIZE_EVENT(LB_GETCOUNT)
		TOKENIZE_EVENT(LB_GETCURSEL)
		TOKENIZE_EVENT(LB_GETHORIZONTALEXTENT)
		TOKENIZE_EVENT(LB_GETITEMDATA)
		TOKENIZE_EVENT(LB_GETITEMHEIGHT)
		TOKENIZE_EVENT(LB_GETITEMRECT)
		TOKENIZE_EVENT(LB_GETLOCALE)
		TOKENIZE_EVENT(LB_GETSEL)
		TOKENIZE_EVENT(LB_GETSELCOUNT)
		TOKENIZE_EVENT(LB_GETSELITEMS)
		TOKENIZE_EVENT(LB_GETTEXT)
		TOKENIZE_EVENT(LB_GETTEXTLEN)
		TOKENIZE_EVENT(LB_GETTOPINDEX)
		TOKENIZE_EVENT(LB_INITSTORAGE)
		TOKENIZE_EVENT(LB_INSERTSTRING)
		TOKENIZE_EVENT(LB_ITEMFROMPOINT)
		TOKENIZE_EVENT(LB_MULTIPLEADDSTRING)
		TOKENIZE_EVENT(LB_RESETCONTENT)
		TOKENIZE_EVENT(LB_SELECTSTRING)
		TOKENIZE_EVENT(LB_SELITEMRANGE)
		TOKENIZE_EVENT(LB_SELITEMRANGEEX)
		TOKENIZE_EVENT(LB_SETANCHORINDEX)
		TOKENIZE_EVENT(LB_SETCARETINDEX)
		TOKENIZE_EVENT(LB_SETCOLUMNWIDTH)
		TOKENIZE_EVENT(LB_SETCOUNT)
		TOKENIZE_EVENT(LB_SETCURSEL)
		TOKENIZE_EVENT(LB_SETHORIZONTALEXTENT)
		TOKENIZE_EVENT(LB_SETITEMDATA)
		TOKENIZE_EVENT(LB_SETITEMHEIGHT)
		TOKENIZE_EVENT(LB_SETLOCALE)
		TOKENIZE_EVENT(LB_SETSEL)
		TOKENIZE_EVENT(LB_SETTABSTOPS)
		TOKENIZE_EVENT(LB_SETTOPINDEX)
		// Button
		TOKENIZE_EVENT(BM_GETCHECK)
		TOKENIZE_EVENT(BM_SETCHECK)
		TOKENIZE_EVENT(BM_GETSTATE)
		TOKENIZE_EVENT(BM_SETSTATE)
		TOKENIZE_EVENT(BM_SETSTYLE)
		TOKENIZE_EVENT(BM_CLICK)
		TOKENIZE_EVENT(BM_GETIMAGE)
		TOKENIZE_EVENT(BM_SETIMAGE)
		// ScrollBar
		TOKENIZE_EVENT(SBM_ENABLE_ARROWS)
		TOKENIZE_EVENT(SBM_GETPOS)
		TOKENIZE_EVENT(SBM_GETRANGE)
		TOKENIZE_EVENT(SBM_GETSCROLLBARINFO)
		TOKENIZE_EVENT(SBM_GETSCROLLINFO)
		TOKENIZE_EVENT(SBM_SETPOS)
		TOKENIZE_EVENT(SBM_SETRANGE)
		TOKENIZE_EVENT(SBM_SETRANGEREDRAW)
		TOKENIZE_EVENT(SBM_SETSCROLLINFO)
		// Animation
		TOKENIZE_EVENT(ACM_OPEN)
		TOKENIZE_EVENT(ACM_PLAY)
		TOKENIZE_EVENT(ACM_STOP)
		// ComboBoxEx
		TOKENIZE_EVENT(CBEM_GETCOMBOCONTROL)
		TOKENIZE_EVENT(CBEM_GETEDITCONTROL)
		TOKENIZE_EVENT(CBEM_GETEXTENDEDSTYLE)
		TOKENIZE_EVENT(CBEM_GETITEM)
		TOKENIZE_EVENT(CBEM_GETUNICODEFORMAT)
		TOKENIZE_EVENT(CBEM_HASEDITCHANGED)
		//TOKENIZE_EVENT(CBEM_INSERTITEM)
		//TOKENIZE_EVENT(CBEM_KILLCOMBOFOCUS)
		//TOKENIZE_EVENT(CBEM_SETCOMBOFOCUS)
		TOKENIZE_EVENT(CBEM_SETEXTENDEDSTYLE)
		//TOKENIZE_EVENT(CBEM_SETIMAGELIST)
		TOKENIZE_EVENT(CBEM_SETITEM)
		TOKENIZE_EVENT(CBEM_SETUNICODEFORMAT)
		TOKENIZE_EVENT(CBEM_SETWINDOWTHEME)
		// DateTime Picker
		TOKENIZE_EVENT(DTM_GETMCCOLOR)
		TOKENIZE_EVENT(DTM_GETMCFONT)
		TOKENIZE_EVENT(DTM_GETMONTHCAL)
		TOKENIZE_EVENT(DTM_GETRANGE)
		TOKENIZE_EVENT(DTM_GETSYSTEMTIME)
		TOKENIZE_EVENT(DTM_SETFORMAT)
		TOKENIZE_EVENT(DTM_SETMCCOLOR)
		TOKENIZE_EVENT(DTM_SETMCFONT)
		TOKENIZE_EVENT(DTM_SETRANGE)
		TOKENIZE_EVENT(DTM_SETSYSTEMTIME)
		// Header
		TOKENIZE_EVENT(HDM_CLEARFILTER)
		TOKENIZE_EVENT(HDM_CREATEDRAGIMAGE)
		TOKENIZE_EVENT(HDM_DELETEITEM)
		TOKENIZE_EVENT(HDM_EDITFILTER)
		TOKENIZE_EVENT(HDM_GETBITMAPMARGIN)
		TOKENIZE_EVENT(HDM_GETIMAGELIST)
		TOKENIZE_EVENT(HDM_GETITEM)
		TOKENIZE_EVENT(HDM_GETITEMCOUNT)
		TOKENIZE_EVENT(HDM_GETITEMRECT)
		TOKENIZE_EVENT(HDM_GETORDERARRAY)
		TOKENIZE_EVENT(HDM_HITTEST)
		TOKENIZE_EVENT(HDM_INSERTITEM)
		TOKENIZE_EVENT(HDM_LAYOUT)
		TOKENIZE_EVENT(HDM_ORDERTOINDEX)
		TOKENIZE_EVENT(HDM_SETBITMAPMARGIN)
		TOKENIZE_EVENT(HDM_SETFILTERCHANGETIMEOUT)
		TOKENIZE_EVENT(HDM_SETHOTDIVIDER)
		TOKENIZE_EVENT(HDM_SETIMAGELIST)
		TOKENIZE_EVENT(HDM_SETITEM)
		TOKENIZE_EVENT(HDM_SETORDERARRAY)
		// IP Address
		TOKENIZE_EVENT(IPM_ISBLANK)
		TOKENIZE_EVENT(IPM_SETFOCUS)
		TOKENIZE_EVENT(IPM_SETRANGE)
		// ListView
		TOKENIZE_EVENT(LVM_APPROXIMATEVIEWRECT)
		TOKENIZE_EVENT(LVM_ARRANGE)
		TOKENIZE_EVENT(LVM_CANCELEDITLABEL)
		TOKENIZE_EVENT(LVM_CREATEDRAGIMAGE)
		TOKENIZE_EVENT(LVM_DELETECOLUMN)
		TOKENIZE_EVENT(LVM_EDITLABEL)
		TOKENIZE_EVENT(LVM_ENABLEGROUPVIEW)
		TOKENIZE_EVENT(LVM_ENSUREVISIBLE)
		TOKENIZE_EVENT(LVM_FINDITEM)
		TOKENIZE_EVENT(LVM_GETBKCOLOR)
		TOKENIZE_EVENT(LVM_GETBKIMAGE)
		TOKENIZE_EVENT(LVM_GETCOLUMN)
		TOKENIZE_EVENT(LVM_GETCOLUMNORDERARRAY)
		TOKENIZE_EVENT(LVM_GETCOLUMNWIDTH)
		TOKENIZE_EVENT(LVM_GETCOUNTPERPAGE)
		TOKENIZE_EVENT(LVM_GETEDITCONTROL)
		TOKENIZE_EVENT(LVM_GETEXTENDEDLISTVIEWSTYLE)
		TOKENIZE_EVENT(LVM_GETGROUPINFO)
		TOKENIZE_EVENT(LVM_GETGROUPMETRICS)
		TOKENIZE_EVENT(LVM_GETHEADER)
		TOKENIZE_EVENT(LVM_GETHOTCURSOR)
		TOKENIZE_EVENT(LVM_GETHOTITEM)
		TOKENIZE_EVENT(LVM_GETHOVERTIME)
		TOKENIZE_EVENT(LVM_GETINSERTMARK)
		TOKENIZE_EVENT(LVM_GETINSERTMARKCOLOR)
		TOKENIZE_EVENT(LVM_GETINSERTMARKRECT)
		TOKENIZE_EVENT(LVM_GETISEARCHSTRING)
		TOKENIZE_EVENT(LVM_GETITEMPOSITION)
		TOKENIZE_EVENT(LVM_GETITEMRECT)
		TOKENIZE_EVENT(LVM_GETITEMSPACING)
		TOKENIZE_EVENT(LVM_GETITEMSTATE)
		TOKENIZE_EVENT(LVM_GETITEMTEXT)
		TOKENIZE_EVENT(LVM_GETNEXTITEM)
		TOKENIZE_EVENT(LVM_GETNUMBEROFWORKAREAS)
		TOKENIZE_EVENT(LVM_GETORIGIN)
		TOKENIZE_EVENT(LVM_GETOUTLINECOLOR)
		TOKENIZE_EVENT(LVM_GETSELECTEDCOLUMN)
		TOKENIZE_EVENT(LVM_GETSELECTEDCOUNT)
		TOKENIZE_EVENT(LVM_GETSELECTIONMARK)
		TOKENIZE_EVENT(LVM_GETSTRINGWIDTH)
		TOKENIZE_EVENT(LVM_GETSUBITEMRECT)
		TOKENIZE_EVENT(LVM_GETTEXTBKCOLOR)
		TOKENIZE_EVENT(LVM_GETTEXTCOLOR)
		TOKENIZE_EVENT(LVM_GETTILEINFO)
		TOKENIZE_EVENT(LVM_GETTILEVIEWINFO)
		TOKENIZE_EVENT(LVM_GETTOOLTIPS)
		TOKENIZE_EVENT(LVM_GETTOPINDEX)
		TOKENIZE_EVENT(LVM_GETVIEW)
		TOKENIZE_EVENT(LVM_GETVIEWRECT)
		TOKENIZE_EVENT(LVM_GETWORKAREAS)
		TOKENIZE_EVENT(LVM_HASGROUP)
		TOKENIZE_EVENT(LVM_HITTEST)
		TOKENIZE_EVENT(LVM_INSERTCOLUMN)
		TOKENIZE_EVENT(LVM_INSERTGROUP)
		TOKENIZE_EVENT(LVM_INSERTGROUPSORTED)
		TOKENIZE_EVENT(LVM_INSERTMARKHITTEST)
		TOKENIZE_EVENT(LVM_ISGROUPVIEWENABLED)
		TOKENIZE_EVENT(LVM_MAPIDTOINDEX)
		TOKENIZE_EVENT(LVM_MAPINDEXTOID)
		TOKENIZE_EVENT(LVM_MOVEGROUP)
		TOKENIZE_EVENT(LVM_MOVEITEMTOGROUP)
		TOKENIZE_EVENT(LVM_REDRAWITEMS)
		TOKENIZE_EVENT(LVM_REMOVEALLGROUPS)
		TOKENIZE_EVENT(LVM_REMOVEGROUP)
		TOKENIZE_EVENT(LVM_SCROLL)
		TOKENIZE_EVENT(LVM_SETBKIMAGE)
		TOKENIZE_EVENT(LVM_SETCALLBACKMASK)
		TOKENIZE_EVENT(LVM_SETCOLUMN)
		TOKENIZE_EVENT(LVM_SETCOLUMNORDERARRAY)
		TOKENIZE_EVENT(LVM_SETCOLUMNWIDTH)
		TOKENIZE_EVENT(LVM_SETEXTENDEDLISTVIEWSTYLE)
		TOKENIZE_EVENT(LVM_SETGROUPINFO)
		TOKENIZE_EVENT(LVM_SETGROUPMETRICS)
		TOKENIZE_EVENT(LVM_SETHOTCURSOR)
		TOKENIZE_EVENT(LVM_SETHOTITEM)
		TOKENIZE_EVENT(LVM_SETHOVERTIME)
		TOKENIZE_EVENT(LVM_SETICONSPACING)
		TOKENIZE_EVENT(LVM_SETINFOTIP)
		TOKENIZE_EVENT(LVM_SETINSERTMARK)
		TOKENIZE_EVENT(LVM_SETINSERTMARKCOLOR)
		TOKENIZE_EVENT(LVM_SETITEMCOUNT)
		TOKENIZE_EVENT(LVM_SETITEMPOSITION)
		TOKENIZE_EVENT(LVM_SETITEMPOSITION32)
		TOKENIZE_EVENT(LVM_SETITEMSTATE)
		TOKENIZE_EVENT(LVM_SETITEMTEXT)
		TOKENIZE_EVENT(LVM_SETOUTLINECOLOR)
		TOKENIZE_EVENT(LVM_SETSELECTEDCOLUMN)
		TOKENIZE_EVENT(LVM_SETSELECTIONMARK)
		TOKENIZE_EVENT(LVM_SETTEXTBKCOLOR)
		TOKENIZE_EVENT(LVM_SETTEXTCOLOR)
		TOKENIZE_EVENT(LVM_SETTILEINFO)
		TOKENIZE_EVENT(LVM_SETTILEVIEWINFO)
		TOKENIZE_EVENT(LVM_SETTILEWIDTH)
		TOKENIZE_EVENT(LVM_SETTOOLTIPS)
		TOKENIZE_EVENT(LVM_SETVIEW)
		TOKENIZE_EVENT(LVM_SETWORKAREAS)
		TOKENIZE_EVENT(LVM_SORTGROUPS)
		TOKENIZE_EVENT(LVM_SORTITEMS)
		TOKENIZE_EVENT(LVM_SORTITEMSEX)
		TOKENIZE_EVENT(LVM_SUBITEMHITTEST)
		TOKENIZE_EVENT(LVM_UPDATE)
		// Pager
		TOKENIZE_EVENT(PGM_FORWARDMOUSE)
		TOKENIZE_EVENT(PGM_GETBKCOLOR)
		TOKENIZE_EVENT(PGM_GETBORDER)
		TOKENIZE_EVENT(PGM_GETBUTTONSIZE)
		TOKENIZE_EVENT(PGM_GETBUTTONSTATE)
		TOKENIZE_EVENT(PGM_GETDROPTARGET)
		TOKENIZE_EVENT(PGM_GETPOS)
		TOKENIZE_EVENT(PGM_RECALCSIZE)
		TOKENIZE_EVENT(PGM_SETBKCOLOR)
		TOKENIZE_EVENT(PGM_SETBORDER)
		TOKENIZE_EVENT(PGM_SETBUTTONSIZE)
		TOKENIZE_EVENT(PGM_SETCHILD)
		TOKENIZE_EVENT(PGM_SETPOS)
		TOKENIZE_EVENT(PGN_SCROLL)
		// ProgressBar
		TOKENIZE_EVENT(PBM_GETPOS)
		TOKENIZE_EVENT(PBM_SETBKCOLOR)
		// Property Sheet
		TOKENIZE_EVENT(PSM_APPLY)
		TOKENIZE_EVENT(PSM_CANCELTOCLOSE)
		TOKENIZE_EVENT(PSM_GETCURRENTPAGEHWND)
		TOKENIZE_EVENT(PSM_GETRESULT)
		TOKENIZE_EVENT(PSM_GETTABCONTROL)
		TOKENIZE_EVENT(PSM_HWNDTOINDEX)
		TOKENIZE_EVENT(PSM_IDTOINDEX)
		TOKENIZE_EVENT(PSM_INDEXTOHWND)
		TOKENIZE_EVENT(PSM_INDEXTOID)
		TOKENIZE_EVENT(PSM_INDEXTOPAGE)
		TOKENIZE_EVENT(PSM_INSERTPAGE)
		TOKENIZE_EVENT(PSM_ISDIALOGMESSAGE)
		TOKENIZE_EVENT(PSM_PAGETOINDEX)
		TOKENIZE_EVENT(PSM_PRESSBUTTON)
		TOKENIZE_EVENT(PSM_QUERYSIBLINGS)
		TOKENIZE_EVENT(PSM_REBOOTSYSTEM)
		TOKENIZE_EVENT(PSM_RECALCPAGESIZES)
		TOKENIZE_EVENT(PSM_SETCURSELID)
		TOKENIZE_EVENT(PSM_SETFINISHTEXT)
		TOKENIZE_EVENT(PSM_SETHEADERSUBTITLE)
		TOKENIZE_EVENT(PSM_SETHEADERTITLE)
		TOKENIZE_EVENT(PSM_SETTITLE)
		TOKENIZE_EVENT(PSM_SETWIZBUTTONS)
		TOKENIZE_EVENT(PSM_UNCHANGED)
		// ReBar
		TOKENIZE_EVENT(RB_BEGINDRAG)
		TOKENIZE_EVENT(RB_DRAGMOVE)
		TOKENIZE_EVENT(RB_ENDDRAG)
		TOKENIZE_EVENT(RB_GETBANDBORDERS)
		TOKENIZE_EVENT(RB_GETBANDCOUNT)
		TOKENIZE_EVENT(RB_GETBANDINFO)
		TOKENIZE_EVENT(RB_GETBANDMARGINS)
		TOKENIZE_EVENT(RB_GETBARHEIGHT)
		TOKENIZE_EVENT(RB_GETBKCOLOR)
		TOKENIZE_EVENT(RB_GETCOLORSCHEME)
		TOKENIZE_EVENT(RB_GETPALETTE)
		TOKENIZE_EVENT(RB_GETROWCOUNT)
		TOKENIZE_EVENT(RB_GETTEXTCOLOR)
		TOKENIZE_EVENT(RB_GETTOOLTIPS)
		TOKENIZE_EVENT(RB_IDTOINDEX)
		TOKENIZE_EVENT(RB_MAXIMIZEBAND)
		TOKENIZE_EVENT(RB_MINIMIZEBAND)
		TOKENIZE_EVENT(RB_MOVEBAND)
		TOKENIZE_EVENT(RB_PUSHCHEVRON)
		TOKENIZE_EVENT(RB_SETBKCOLOR)
		TOKENIZE_EVENT(RB_SETCOLORSCHEME)
		TOKENIZE_EVENT(RB_SETPALETTE)
		TOKENIZE_EVENT(RB_SETTEXTCOLOR)
		TOKENIZE_EVENT(RB_SETTOOLTIPS)
		TOKENIZE_EVENT(RB_SHOWBAND)
		TOKENIZE_EVENT(RB_SIZETORECT)
		// RichText
		TOKENIZE_EVENT(EM_AUTOURLDETECT)
		TOKENIZE_EVENT(EM_CANPASTE)
		TOKENIZE_EVENT(EM_CANREDO)
		TOKENIZE_EVENT(EM_DISPLAYBAND)
		TOKENIZE_EVENT(EM_EXGETSEL)
		TOKENIZE_EVENT(EM_EXLIMITTEXT)
		TOKENIZE_EVENT(EM_EXLINEFROMCHAR)
		TOKENIZE_EVENT(EM_EXSETSEL)
		TOKENIZE_EVENT(EM_FINDTEXT)
		TOKENIZE_EVENT(EM_FINDTEXTEX)
		TOKENIZE_EVENT(EM_FINDTEXTEXW)
		TOKENIZE_EVENT(EM_FINDTEXTW)
		TOKENIZE_EVENT(EM_FINDWORDBREAK)
		TOKENIZE_EVENT(EM_FORMATRANGE)
		TOKENIZE_EVENT(EM_GETAUTOURLDETECT)
		TOKENIZE_EVENT(EM_GETBIDIOPTIONS)
		TOKENIZE_EVENT(EM_GETCHARFORMAT)
		TOKENIZE_EVENT(EM_GETCTFMODEBIAS)
		TOKENIZE_EVENT(EM_GETCTFOPENSTATUS)
		TOKENIZE_EVENT(EM_GETEDITSTYLE)
		TOKENIZE_EVENT(EM_GETEVENTMASK)
		TOKENIZE_EVENT(EM_GETHYPHENATEINFO)
		TOKENIZE_EVENT(EM_GETIMECOMPMODE)
		TOKENIZE_EVENT(EM_GETIMECOMPTEXT)
		TOKENIZE_EVENT(EM_GETIMEPROPERTY)
		TOKENIZE_EVENT(EM_GETLANGOPTIONS)
		TOKENIZE_EVENT(EM_GETOLEINTERFACE)
		TOKENIZE_EVENT(EM_GETOPTIONS)
		TOKENIZE_EVENT(EM_GETPAGEROTATE)
		TOKENIZE_EVENT(EM_GETPARAFORMAT)
		TOKENIZE_EVENT(EM_GETREDONAME)
		TOKENIZE_EVENT(EM_GETSCROLLPOS)
		TOKENIZE_EVENT(EM_GETSELTEXT)
		TOKENIZE_EVENT(EM_GETTEXTEX)
		TOKENIZE_EVENT(EM_GETTEXTLENGTHEX)
		TOKENIZE_EVENT(EM_GETTEXTMODE)
		TOKENIZE_EVENT(EM_GETTEXTRANGE)
		TOKENIZE_EVENT(EM_GETTYPOGRAPHYOPTIONS)
		TOKENIZE_EVENT(EM_GETUNDONAME)
		TOKENIZE_EVENT(EM_GETWORDBREAKPROCEX)
		TOKENIZE_EVENT(EM_GETZOOM)
		TOKENIZE_EVENT(EM_HIDESELECTION)
		TOKENIZE_EVENT(EM_ISIME)
		TOKENIZE_EVENT(EM_PASTESPECIAL)
		TOKENIZE_EVENT(EM_REDO)
		TOKENIZE_EVENT(EM_REQUESTRESIZE)
		TOKENIZE_EVENT(EM_SELECTIONTYPE)
		TOKENIZE_EVENT(EM_SETBIDIOPTIONS)
		TOKENIZE_EVENT(EM_SETBKGNDCOLOR)
		TOKENIZE_EVENT(EM_SETCHARFORMAT)
		TOKENIZE_EVENT(EM_SETCTFMODEBIAS)
		TOKENIZE_EVENT(EM_SETCTFOPENSTATUS)
		TOKENIZE_EVENT(EM_SETEDITSTYLE)
		TOKENIZE_EVENT(EM_SETEVENTMASK)
		TOKENIZE_EVENT(EM_SETFONTSIZE)
		TOKENIZE_EVENT(EM_SETHYPHENATEINFO)
		TOKENIZE_EVENT(EM_SETIMEMODEBIAS)
		TOKENIZE_EVENT(EM_SETLANGOPTIONS)
		TOKENIZE_EVENT(EM_SETOLECALLBACK)
		TOKENIZE_EVENT(EM_SETOPTIONS)
		TOKENIZE_EVENT(EM_SETPAGEROTATE)
		TOKENIZE_EVENT(EM_SETPALETTE)
		TOKENIZE_EVENT(EM_SETPARAFORMAT)
		TOKENIZE_EVENT(EM_SETSCROLLPOS)
		TOKENIZE_EVENT(EM_SETTARGETDEVICE)
		TOKENIZE_EVENT(EM_SETTEXTEX)
		TOKENIZE_EVENT(EM_SETTEXTMODE)
		TOKENIZE_EVENT(EM_SETTYPOGRAPHYOPTIONS)
		TOKENIZE_EVENT(EM_SETUNDOLIMIT)
		TOKENIZE_EVENT(EM_SETWORDBREAKPROCEX)
		TOKENIZE_EVENT(EM_SETZOOM)
		TOKENIZE_EVENT(EM_SHOWSCROLLBAR)
		TOKENIZE_EVENT(EM_STOPGROUPTYPING)
		TOKENIZE_EVENT(EM_STREAMIN)
		TOKENIZE_EVENT(EM_STREAMOUT)
		// StatusBar
		TOKENIZE_EVENT(SB_SETICON)
		// SysLink
		TOKENIZE_EVENT(LM_GETIDEALHEIGHT)
		TOKENIZE_EVENT(LM_GETITEM)
		TOKENIZE_EVENT(LM_HITTEST)
		TOKENIZE_EVENT(LM_SETITEM)
		// Tab Control
		TOKENIZE_EVENT(TCM_ADJUSTRECT)
		TOKENIZE_EVENT(TCM_DELETEALLITEMS)
		TOKENIZE_EVENT(TCM_DELETEITEM)
		TOKENIZE_EVENT(TCM_DESELECTALL)
		TOKENIZE_EVENT(TCM_GETCURFOCUS)
		TOKENIZE_EVENT(TCM_GETCURSEL)
		TOKENIZE_EVENT(TCM_GETEXTENDEDSTYLE)
		TOKENIZE_EVENT(TCM_GETIMAGELIST)
		TOKENIZE_EVENT(TCM_GETITEM)
		TOKENIZE_EVENT(TCM_GETITEMCOUNT)
		TOKENIZE_EVENT(TCM_GETITEMRECT)
		TOKENIZE_EVENT(TCM_GETROWCOUNT)
		TOKENIZE_EVENT(TCM_GETTOOLTIPS)
		TOKENIZE_EVENT(TCM_HIGHLIGHTITEM)
		TOKENIZE_EVENT(TCM_HITTEST)
		TOKENIZE_EVENT(TCM_INSERTITEM)
		TOKENIZE_EVENT(TCM_REMOVEIMAGE)
		TOKENIZE_EVENT(TCM_SETCURFOCUS)
		TOKENIZE_EVENT(TCM_SETCURSEL)
		TOKENIZE_EVENT(TCM_SETEXTENDEDSTYLE)
		TOKENIZE_EVENT(TCM_SETIMAGELIST)
		TOKENIZE_EVENT(TCM_SETITEM)
		TOKENIZE_EVENT(TCM_SETITEMEXTRA)
		TOKENIZE_EVENT(TCM_SETITEMSIZE)
		TOKENIZE_EVENT(TCM_SETMINTABWIDTH)
		TOKENIZE_EVENT(TCM_SETPADDING)
		TOKENIZE_EVENT(TCM_SETTOOLTIPS)
		// ToolBar
		TOKENIZE_EVENT(TB_ADDSTRING)
		TOKENIZE_EVENT(TB_AUTOSIZE)
		TOKENIZE_EVENT(TB_GETBITMAP)
		TOKENIZE_EVENT(TB_GETBITMAPFLAGS)
		TOKENIZE_EVENT(TB_GETBUTTONTEXT)
		TOKENIZE_EVENT(TB_GETIMAGELIST)
		TOKENIZE_EVENT(TB_GETMAXSIZE)
		TOKENIZE_EVENT(TB_ISBUTTONPRESSED)
		TOKENIZE_EVENT(TB_REPLACEBITMAP)
		TOKENIZE_EVENT(TB_SETBITMAPSIZE)
		TOKENIZE_EVENT(TB_SETCMDID)
		TOKENIZE_EVENT(TB_SETIMAGELIST)
		TOKENIZE_EVENT(TB_SETINDENT)
		TOKENIZE_EVENT(TB_SETTOOLTIPS)
		// TreeView
		TOKENIZE_EVENT(TVM_CREATEDRAGIMAGE)
		TOKENIZE_EVENT(TVM_DELETEITEM)
		TOKENIZE_EVENT(TVM_EDITLABEL)
		TOKENIZE_EVENT(TVM_ENDEDITLABELNOW)
		TOKENIZE_EVENT(TVM_ENSUREVISIBLE)
		TOKENIZE_EVENT(TVM_EXPAND)
		TOKENIZE_EVENT(TVM_GETBKCOLOR)
		TOKENIZE_EVENT(TVM_GETCOUNT)
		TOKENIZE_EVENT(TVM_GETEDITCONTROL)
		TOKENIZE_EVENT(TVM_GETIMAGELIST)
		TOKENIZE_EVENT(TVM_GETINDENT)
		TOKENIZE_EVENT(TVM_GETINSERTMARKCOLOR)
		TOKENIZE_EVENT(TVM_GETISEARCHSTRING)
		TOKENIZE_EVENT(TVM_GETITEM)
		TOKENIZE_EVENT(TVM_GETITEMHEIGHT)
		TOKENIZE_EVENT(TVM_GETITEMRECT)
		TOKENIZE_EVENT(TVM_GETITEMSTATE)
		TOKENIZE_EVENT(TVM_GETLINECOLOR)
		TOKENIZE_EVENT(TVM_GETNEXTITEM)
		TOKENIZE_EVENT(TVM_GETSCROLLTIME)
		TOKENIZE_EVENT(TVM_GETTEXTCOLOR)
		TOKENIZE_EVENT(TVM_GETTOOLTIPS)
		TOKENIZE_EVENT(TVM_GETVISIBLECOUNT)
		TOKENIZE_EVENT(TVM_HITTEST)
		TOKENIZE_EVENT(TVM_INSERTITEM)
		TOKENIZE_EVENT(TVM_MAPACCIDTOHTREEITEM)
		TOKENIZE_EVENT(TVM_MAPHTREEITEMTOACCID)
		TOKENIZE_EVENT(TVM_SELECTITEM)
		TOKENIZE_EVENT(TVM_SETBKCOLOR)
		TOKENIZE_EVENT(TVM_SETIMAGELIST)
		TOKENIZE_EVENT(TVM_SETINDENT)
		TOKENIZE_EVENT(TVM_SETINSERTMARK)
		TOKENIZE_EVENT(TVM_SETINSERTMARKCOLOR)
		TOKENIZE_EVENT(TVM_SETITEM)
		TOKENIZE_EVENT(TVM_SETITEMHEIGHT)
		TOKENIZE_EVENT(TVM_SETLINECOLOR)
		TOKENIZE_EVENT(TVM_SETSCROLLTIME)
		TOKENIZE_EVENT(TVM_SETTEXTCOLOR)
		TOKENIZE_EVENT(TVM_SETTOOLTIPS)
		TOKENIZE_EVENT(TVM_SORTCHILDREN)
		TOKENIZE_EVENT(TVM_SORTCHILDRENCB)
#undef TOKENIZE_EVENT
	}
	static char tmpbuf[16];
	_snprintf(tmpbuf, sizeof(tmpbuf) / sizeof(tmpbuf[0]), "WM_%04X", uMsg);
	return (const char *)tmpbuf;
}