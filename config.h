/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 60;       /* snap pixel */
static const unsigned int gappih    = 35;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 35;       /* vert inner gap between windows */
static const unsigned int gappoh    = 30;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 5;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Hack Nerd Font Mono:style=bold:size=9" };
static const char col_nejtmavsi[]       = "#1d2021";
static const char col_tmava[]  = "#3c3836";
static const char col_hlavni[]        = "#504945";
static const char col_nejsvetlejsi[]        = "#fbf1c7";
static const char col_zluta[]        = "#fabd2f";
static const char col_cervena[]        = "#fb4934";
static const char col_cervena2[]        = "#cc241d";
static const char col_oranzova[]        = "#fe8019";
static const char col_modra[]        = "#458588";
static const char col_modra2[]        = "#83a598";
static const char col_zelena[]        = "#b8bb26";
static const char col_zelena2[]        = "#98971a";
static const char col_fialova[]        = "#b16286";
static const char col_fialova2[]        = "#d3869b";
static const char col_koral[]        = "#8ec07c";
static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_nejsvetlejsi, col_nejtmavsi, col_modra },
  [SchemeSel] = { col_zluta, col_tmava, col_zluta },
};

/* tagging */
static const char *tags[] = { "1  VŠEHOCHUŤ ", "2  Soubory", "3  NET", "4  EDIT", "5  MÉDIA", "6  DEV", "7  SYS", "8  OSTATNÍ", "9  PRÁCE"};

static const char *tagsel[][2] = {
	{ col_nejtmavsi, col_zluta },
	{ col_nejtmavsi, col_zelena },
	{ col_nejsvetlejsi, col_modra },
	{ col_nejtmavsi, col_cervena },
	{ col_nejsvetlejsi, col_fialova },
	{ col_nejtmavsi, col_oranzova },
	{ col_nejtmavsi, col_koral },
	{ col_nejtmavsi, col_fialova2 },
	{ col_nejsvetlejsi, col_cervena2 },
};

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class      instance    title       tags mask     switchtotag    isfloating   monitor */ 
  /* VŠEHOCHUŤ */
  {"st",	NULL,		NULL,		1 << 0,		1,	0,	-1},
  {"URxvt",	NULL,		NULL,		1 << 0,		1,	0,	-1},
  {"XTerm",	NULL,		NULL,		1 << 0,		1,	0,	-1},
  {"Bseterm",	NULL,		NULL,		1 << 0,		1,	0,	-1},
  {"Putty",		NULL,		NULL,	1 << 0,		1,	0,	-1},
  //HRY
  {"dosbox",	NULL,		NULL,		1 << 0,		1,	0,	-1},
  
  /*SOUBORY*/
  {"Pcmanfm",		NULL,	NULL,		1 << 1,		1,	0,	-1},
  {"FileZilla",		NULL,	NULL,		1 << 1,		1,	0,	-1},
  {"Gnome-commander",	NULL,	NULL,		1 << 1,		1,	0,	-1},
  {"Thunar",	NULL,		NULL,		1 << 1,		1,	0,	-1},
  {"File-roller",	NULL,	NULL,		1 << 1,		1,	0,	-1},
  {NULL,		NULL,	"ranger",	1 << 1,		1,	0,	-1},

  /*NET*/
  { "Links",  	NULL,       NULL,		1 << 2,		1,	0,	-1},
  { "Firefox",  	NULL,   NULL,		1 << 2,		1,	0,	-1},
  { "Brave-browser",  	NULL,   NULL,		1 << 2,		1,	0,	-1},
  { "Surf",  	NULL,       NULL,		1 << 2,		1,	0,	-1},
  { NULL,  	"Navigator",    NULL,		1 << 2,		1,	0,	-1},
  { NULL,  	"surf",    NULL,		1 << 2,		1,	0,	-1},
  {"thunderbird",NULL,NULL,			1 << 2,		1,	0,	-1},
  {"whatsapp-desktop",NULL,NULL,		1 << 2,		1,	0,	-1},
  {"Vncviewer",	      NULL,		NULL,	1 << 2,		1,	0,	-1},
  {"TeamViewer",      NULL,		NULL,	1 << 2,		1,	0,	-1},
  {"Wireshark",	      NULL,		NULL,	1 << 2,		1,	0,	-1},
  {"transmission-gtk",    NULL,		NULL,	1 << 2,		1,	0,	-1},
  
  /*EDIT*/
  { "libreoffice-writer",  	NULL,	NULL,	1 << 3,		1,	0,	-1},
  { "libreoffice-calc",  	NULL,   NULL,   1 << 3,		1,	0,	-1},
  { "libreoffice-startcenter", 	NULL,   NULL,   1 << 3,		1,	0,	-1},
  { "Emacs-29",			NULL,	NULL,	1 << 3,		1,	0,	-1},
  { "Geany",			NULL,	NULL,	1 << 3,		1,	0,	-1},
  { "Leafpad",			NULL,	NULL,	1 << 3,		1,	0,	-1},
  
  /*MEDIA*/
  { "Amsynth",     	NULL,   NULL,	1 << 4,		1,	0,	-1},
  { "Audacity",     	NULL,   NULL,	1 << 4,		1,	0,	-1},
  { NULL,     	"Audacity", NULL,       1 << 4,		1,	0,	-1},
  { "Cheese",   NULL,       NULL,	1 << 4,		1,	0,	-1},
  { "Easytag",   NULL,       NULL,	1 << 4,		1,	0,	-1},
  { "Hdajackretask",   NULL,	NULL,	1 << 4,		1,	0,	-1},
  { "Hwmixvolume",   NULL,	NULL,	1 << 4,		1,	0,	-1},
  { "Hydrogen",   NULL,		NULL,	1 << 4,		1,	0,	-1},
  { "lmms",   NULL,		NULL,	1 << 4,		1,	0,	-1}, 
  { "vlc",     	NULL,       NULL,       1 << 4,		1,	0,	-1},
  { "Gpicview",   NULL,       NULL,	1 << 4,		1,	0,	-1},
  { "Rhythmbox",   NULL,       NULL,	1 << 4,		1,	0,	-1},
  { "Soundconverter",   NULL, NULL,	1 << 4,		1,	0,	-1},
  { "SimpleScreenRecorder",   NULL,NULL,1 << 4,		1,	0,	-1},
  { "Xfburn",   NULL,       NULL,      	1 << 4,		1,	0,	-1},
  { "Mixxx",   NULL,       NULL,       	1 << 4,		1,	0,	-1},
  {"XpdfReader",	NULL,	NULL,	1 << 4,		1,	0,	-1},
  {"converseen",	NULL,	NULL,	1 << 4,		1,	0,	-1},
  { "Gimp",     NULL,       NULL,	1 << 4,		1,	0,	-1},
  { NULL,     	"gimp",     NULL,       1 << 4,		0,	0,	-1},
  { "Inkscape",   NULL,       NULL,     1 << 4,		1,	0,	-1},
  { "Blender",   NULL,       NULL,      1 << 4,		1,	0,	-1},
  {"fontforge",	NULL,	NULL,		1 << 4,		1,	0,	-1},
  {"libreoffice-draw",	NULL,	NULL,	1 << 4,		1,	0,	-1},
  {"feh",		NULL,	NULL,	1 << 4,		1,	0,	-1},
  { "PrusaSlicer",   NULL,       NULL,	1 << 4,		1,	0,	-1},
  { "org.gnome.SoundRecorder",NULL, NULL, 1 << 4,	1,	0,	-1},
  { NULL,NULL, "ncmpcpp 0.9.2",		1 << 4,		1,	0,	-1},
  {"Audacious",		NULL,	NULL,	1 << 4,		1,	0,	-1},
  {"Brasero",		NULL,	NULL,	1 << 4,		1,	0,	-1},
  
  /*DEV*/
  {"FLTK",			NULL,	NULL,	1 << 5,		1,	0,	-1},
  {"Jaspersoft Studio",		NULL,	NULL,	1 << 5,		1,	0,	-1},
  {"DbVisualizer",		NULL,	NULL,	1 << 5,		1,	0,	-1},
  {"Eclipse",	 		NULL,	NULL,   1 << 5,		1,	0,	-1},
  {"Gitk",	 		NULL,	NULL,   1 << 5,		1,	0,	-1},
  {"install4j-com-eviware-soapui-SoapUI", NULL,	NULL,   1 << 5,		1,	0,	-1},
  
  /*SYS*/
  {"Lxappearance",	        NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"qt5ct",			NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Xfce4-display-settings",	NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Xfce4-keyboard-settings",	NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Xfce4-mouse-settings",	NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Xfce4-accessibility-settings",	NULL,	NULL,	1 << 6,		1,	0,	-1},  
  {"Arandr",			NULL,		NULL,	1 << 6,		1,	0,	-1},  
  {"hp-toolbox",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Kvantum Manager",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"wpa_gui",			NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Gnome-disks",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"GParted",			NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"laptop mode tools",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Shredder",			NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Blueman-services",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Blueman-applet",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Blueman-adapters",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Blueman-manager",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"qlipper",			NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Nm-applet",			NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Nm-connection-editor",	NULL,		NULL,	1 << 6,		1,	0,	-1},
  {"Volumeicon",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  {NULL,			NULL,		"htop",	1 << 6,		1,	0,	-1},
  {"Xephyr",		NULL,		NULL,	1 << 6,		1,	0,	-1},
  
  /*OSTATNÍ*/
  {"Libfm-pref-apps",		NULL,		NULL,	1 << 7,		1,	0,	-1},  
  {"gnome-calculator",		NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"Gucharmap",			NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"QtPass",			NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"Virt-manager",		NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"VirtualBox Manager",	NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"Spicy",			NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"gnome-font-viewer",		NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"org.gnome.Characters",	NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"Grsync",			NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"gtk4-icon-browser",		NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"gtk4-node-editor",		NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"gtk4-widget-factory",	NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"kdeconnect-indicator",	NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"kdeconnect.app",		NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"kdeconnect.handler",	NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"kdeconnect-settings",	NULL,		NULL,	1 << 7,		1,	0,	-1},
  {"kdeconnect.sms",		NULL,		NULL,	1 << 7,		1,	0,	-1},
  
  /*PRÁCE*/
  {"Java",		NULL,		NULL,	0,		0,	1,	-1},
  { "boss-Start",	NULL,		NULL,	1 << 8,		1,	0,	-1},
  {NULL,"sun-awt-X11-XFramePeer",	NULL,	1 << 8,		0,	0,	-1},
  { "SWT",		NULL,		NULL,   1 << 2,		0,	0,	 1},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { ":::",      gaplessgrid },
  //{ "###",      nrowgrid },
  { "[M]",      monocle },
  { "|M|",      centeredmaster },
  { "[@]",      spiral },
  //{ "[\\]",     dwindle },
  //{ "H[]",      deck },
  { "TTT",      bstack },
  //{ "===",      bstackhoriz },
  //{ "HHH",      grid },
  //{ "---",      horizgrid },
  //{ ">M>",      centeredfloatingmaster },
  { "><>",      NULL },    /* no layout function means floating behavior */
  { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALT Mod1Mask
#define TAGKEYS(KEY,TAG)						\
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "/home/martin/.dmv/skripty/dmenu_run.sh", NULL };
static const char *viacmd[] = { "/home/martin/.dmv/skripty/via.sh", NULL };
static const char *termcmd[]  = { "terminal", NULL };
static const char *editorcmd[]  = { "emacs", NULL };
static const char *killcmd[]  = { "/home/martin/.dmv/skripty/xkill.sh", NULL }; 
static const char *lockcmd[]  = { "/home/martin/.dmv/skripty/slock-zamknout.sh", NULL }; 
static const char *startupcmd[]  = { "/home/martin/.dmv/startup.sh", NULL };
static const char *dmvdirectory[]  = { "terminal", "-e", "mc", "/home/martin/.dmv/", NULL };
static const char *pozdravcmd[]  = { "/home/martin/.dmv/skripty/notify-send/notify-send-pozdrav.sh", NULL };
static const char *conkypanelcmd[]  = { "/home/martin/.dmv/skripty/conky/conky-desktop_panel.sh", NULL };

/* MENU */
static const char *menu[]  = { "/home/martin/.dmv/skripty/jgmenu/jgmenu-menu.sh", NULL };
static const char *pvamenu[]  = { "/home/martin/.dmv/skripty/jgmenu/jgmenu-pva.sh", NULL };
static const char *zaznamymenu[]  = { "/home/martin/.dmv/skripty/dmenu/zaznamy.sh", NULL };
static const char *gentoomenu[]  = { "/home/martin/.dmv/skripty/dmenu/gentoo.sh", NULL };
static const char *dmvmenu[]  = { "/home/martin/.dmv/skripty/dmenu/dmv.sh", NULL };

/* MULTIMEDIA */
static const char *volup[]  = { "/home/martin/.dmv/skripty/amixer/amixer-zesilit.sh", NULL };
static const char *voldown[]  = { "/home/martin/.dmv/skripty/amixer/amixer-ztlumit.sh", NULL };
static const char *voltoggle[]  = { "/home/martin/.dmv/skripty/amixer/amixer-mute.sh", NULL };
static const char *mpc_next[]  = { "/home/martin/.dmv/skripty/mpc/mpc-next.sh", NULL };
static const char *mpc_prev[]  = { "/home/martin/.dmv/skripty/mpc/mpc-prev.sh", NULL };
static const char *mpc_stop[]  = { "/home/martin/.dmv/skripty/mpc/mpc-stop.sh", NULL };
static const char *mpc_toggle[]  = { "/home/martin/.dmv/skripty/mpc/mpc-toggle.sh", NULL };
static const char *screenshotselectcmd[]  = { "/home/martin/.dmv/skripty/import-screenshot-select.sh", NULL }; /* Spustí můj skript na screenshot celé obrazovky */
static const char *screenshotcmd[]  = { "/home/martin/.dmv/skripty/import-screenshot.sh", NULL }; /* Spustí můj skript na screenshot celé obrazovky */
static const char *zmenportret[]  = { "/home/martin/.dmv/skripty/conky/conky-portrait.sh", NULL };
static const char *zmenpozadi[]  = { "/home/martin/.dmv/skripty/feh-nahodne_pozadi.sh", NULL };
static const char *xbacklight_minus[]  = { "/home/martin/.dmv/skripty/xbacklight-minus.sh", NULL };
static const char *xbacklight_plus[]  = { "/home/martin/.dmv/skripty/xbacklight-plus.sh", NULL };

#include "exitdwm.c"
#include "movestack.c"
#include <X11/XF86keysym.h>
static Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
  { MODKEY,			  XK_Return, spawn,          {.v = termcmd } },
  { MODKEY,		          XK_F2,     spawn,          {.v = voltoggle } },
  { MODKEY,		          XK_F3,     spawn,          {.v = voldown } },
  { MODKEY, 		 	  XK_F4,				spawn,			{.v = volup } },
  { MODKEY, 		          XK_F5,				spawn,			{.v = mpc_prev } },
  { MODKEY, 			  XK_F6,				spawn,			{.v = mpc_stop } },
  { MODKEY, 			  XK_F7,				spawn,			{.v = mpc_toggle } },
  { MODKEY, 			  XK_F8,				spawn,			{.v = mpc_next } },
  { 0, 				  XF86XK_AudioPrev,			spawn,			{.v = mpc_prev } },
  { 0, 				  XF86XK_AudioStop,			spawn,			{.v = mpc_stop } },
  { 0, 				  XF86XK_AudioPlay,			spawn,			{.v = mpc_toggle } },
  { 0, 				  XF86XK_AudioNext,			spawn,			{.v = mpc_next } },
  { 0, 				  XF86XK_AudioRaiseVolume,	spawn,			{.v = volup } },
  { 0, 				  XF86XK_AudioLowerVolume,	spawn,			{.v = voldown } },
  { 0, 				  XF86XK_AudioMute,		    spawn,          {.v = voltoggle } },
  { 0, 				  XF86XK_WWW,				spawn,			SHCMD("firefox") },
  { 0, 				  XF86XK_TouchpadToggle,		spawn,			SHCMD("/home/martin/.dmv/skripty/synclient-touchpad.sh") },
  { 0, 				  XF86XK_TouchpadOff,		spawn,			SHCMD("/home/martin/.dmv/skripty/xinput-touchpad-off.sh") },
  { 0, 				  XF86XK_TouchpadOn,			spawn,			SHCMD("/home/martin/.dmv/skripty/xinput-touchpad-on.sh") },
  { 0, 				  XF86XK_MonBrightnessUp,	spawn,			{.v = xbacklight_plus } },
  { 0, 				  XF86XK_MonBrightnessDown,	spawn,			{.v = xbacklight_minus } },
  { 0, 				  XF86XK_AudioMicMute,	    spawn,          SHCMD("/home/martin/.dmv/skripty/amixer-capture-toogle.sh") },
  { 0, 				  XF86XK_Display,	    	spawn,          SHCMD("terminal -e bash /home/martin/.dmv/skripty/xrandr-set.sh") },
  { MODKEY,    			  XK_Print,   spawn,          {.v = screenshotcmd } },
  { MODKEY|ShiftMask,    	  XK_Print,   spawn,          {.v = screenshotselectcmd } },
  { MODKEY,  			  XK_z,   	spawn,          {.v = zaznamymenu } },
  { MODKEY,  			  XK_x,   	spawn,          {.v = killcmd } },
  { MODKEY,	                  XK_w, 		spawn,          {.v = menu } },  
  { MODKEY,	                  XK_p, 		spawn,          {.v = pvamenu } },	
  { MODKEY,	                  XK_s, 		spawn,          {.v = dmvdirectory } },
  { MODKEY,	                  XK_e, 		spawn,       	{.v = viacmd } },
  { MODKEY,	                  XK_Escape, 	spawn,      	{.v = lockcmd } },
  { MODKEY|ShiftMask,		  XK_Escape, 	spawn,      	{.v = zmenportret } },
  { MODKEY|ShiftMask,		  XK_Escape, 	spawn,      	{.v = zmenpozadi } },
  { MODKEY,             	  XK_g,   spawn,		       	{.v = gentoomenu } },
  { MODKEY,             	  XK_d,   spawn,		       	{.v = dmvmenu } },
  { MODKEY,	                  XK_semicolon,    view,     	{.ui = ~0 } },
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
  { MODKEY,                       XK_k,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_j,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_l,      incnmaster,     {.i = +1 } },
  { MODKEY|ShiftMask,             XK_h,      incnmaster,     {.i = -1 } },
  { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = +1 } },
  { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = -1 } },
  { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY|ALT,         	  XK_h,      setcfact,       {.f = +0.25} },
  { MODKEY|ALT,         	  XK_l,      setcfact,       {.f = -0.25} },
  { MODKEY|ALT,         	  XK_o,      setcfact,       {.f =  0.00} },
  { MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +10 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -10 } },
  { MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +10 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -10 } },
  { MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +10 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -10 } },
  { MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +10 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -10 } },
  { MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +10 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -10 } },
  { MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +10 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -10 } },
  { MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +10 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -10 } },
  { MODKEY,              	  XK_v,      togglegaps,     {0} },
  { MODKEY|ShiftMask,    	  XK_v,      defaultgaps,    {0} },
  { MODKEY,			  XK_q,      killclient,     {0} },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,           		  XK_space,  cyclelayout,    {.i = +1 } },
  { MODKEY|ShiftMask,    	  XK_space,  cyclelayout,    {.i = -1 } },
  { MODKEY,           		  XK_f,      togglefloating, 	{0} },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = +1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = -1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = -1 } },
  { MODKEY,                       XK_Left,   rotatetags,     {.i = -1 } },
  { MODKEY,                       XK_Right,  rotatetags,     {.i = +1 } },
  { MODKEY,           XK_Up,  viewnext,       {0} },
  { MODKEY,           XK_Down,  viewprev,       {0} },
  { MODKEY|ShiftMask,             XK_Up,  tagtonext,      {0} },
  { MODKEY|ShiftMask,             XK_Down,   tagtoprev,      {0} },
  TAGKEYS(                        XK_plus,                      0)
  TAGKEYS(                        XK_ecaron,                      1)
  TAGKEYS(                        XK_scaron,                      2)
  TAGKEYS(                        XK_ccaron,                      3)
  TAGKEYS(                        XK_rcaron,                      4)
  TAGKEYS(                        XK_zcaron,                      5)
  TAGKEYS(                        XK_yacute,                      6)
  TAGKEYS(                        XK_aacute,                      7)
  TAGKEYS(                        XK_iacute,                      8)
  TAGKEYS(                        XK_eacute,                      9)
  { MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} },
  { MODKEY|ShiftMask,             XK_q,      exitdwm,           {0} },
};

/* button definitions */
#define Button6 6
#define Button7 7
#define Button8 8
#define Button9 9
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click              event mask      button          function        argument */
  { ClkLtSymbol,        0,              Button1,        cyclelayout,    {.i = +1 } },
  { ClkLtSymbol,        0,              Button2,        setlayout,      {.v = &layouts[0]} },
  { ClkLtSymbol,        0,              Button3,        cyclelayout,    {.i = -1 } },
  { ClkLtSymbol,        0,              Button4,        setmfact,       {.f = +0.05} },
  { ClkLtSymbol,        0,              Button5,        setmfact,       {.f = -0.05} },
  { ClkWinTitle,        0,              Button1,        zoom,           {0} },
  { ClkWinTitle,        0,              Button2,        killclient,     {0} },
  { ClkWinTitle,        0,              Button3,        togglefloating, 	{0} },
  { ClkWinTitle,        0,              Button4,        focusstack,     {.i = -1 } },
  { ClkWinTitle,        0,              Button5,        focusstack,     {.i = +1 } },
  { ClkStatusText,      0,              Button1,        spawn,          {.v = menu } },
  { ClkStatusText,      0,              Button2,        killclient,     {0} },
  { ClkStatusText,      0,              Button3,        spawn,          {.v = conkypanelcmd } },
  { ClkStatusText,      0,              Button4,        spawn,          {.v = volup } },
  { ClkStatusText,      0,              Button5,        spawn,          {.v = voldown } },
  { ClkClientWin,       MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,       MODKEY,         Button2,        togglefloating, 	{0} },
  { ClkClientWin,       MODKEY,         Button3,        resizemouse,    {0} },
  { ClkClientWin,       MODKEY,         Button4,        setmfact,       {.f = +0.05} },
  { ClkClientWin,       MODKEY,         Button5,        setmfact,       {.f = -0.05} },
  { ClkClientWin,     	MODKEY|ShiftMask,   Button1,    zoom,           {0} },
  { ClkClientWin,     	MODKEY|ShiftMask,   Button2,    killclient,     {0} },
  { ClkClientWin,     	MODKEY|ShiftMask,   Button3,    togglefullscr,  {0} },
  { ClkClientWin,     	MODKEY|ShiftMask,   Button4,    incnmaster,     {.i = +1 } },
  { ClkClientWin,    	MODKEY|ShiftMask,   Button5,    incnmaster,     {.i = -1 } },
  { ClkClientWin, 	MODKEY,         Button6,        rotatetags,     {.i = +1 } },
  { ClkClientWin, 	0,              Button8,        viewprev,       {0} },
  { ClkClientWin, 	MODKEY,         Button7,        rotatetags,     {.i = -1 } },
  { ClkClientWin, 	0,              Button9,        viewnext,       {0} },
  { ClkTagBar,          0,              Button1,        view,           {0} },
  { ClkTagBar,          0,              Button2,        view,           {.ui = ~0 } },
  { ClkTagBar,          0,              Button3,        toggleview,     {0} },
  { ClkTagBar,     	0,              Button4,        viewnext,       {0} },
  { ClkTagBar, 		0,              Button5,        viewprev,       {0} },
  { ClkTagBar,          MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,          MODKEY,         Button3,        toggletag,      {0} },
  { ClkTagBar,     	MODKEY,         Button4,        rotatetags,     {.i = +1 } },
  { ClkTagBar, 		MODKEY,         Button5,        rotatetags,     {.i = -1 } },
  { ClkTagBar, 		0,      	Button6,        rotatetags,     {.i = +1 } },
  { ClkTagBar, 		0,      	Button7,        rotatetags,     {.i = -1 } },
  { ClkTagBar, 		0,    		Button8,        viewprev,       {0} },
  { ClkTagBar, 		0,			Button9,        viewnext,       {0} },
  { ClkRootWin,         0,              Button1,        spawn,          {.v = menu } },
  { ClkRootWin,         0,              Button2,        togglebar,      {0} },
  { ClkRootWin,         0,              Button3,        spawn,          {.v = menu } },
  { ClkRootWin,         MODKEY,         Button2,        spawn,          {.v = zmenportret } },
  { ClkRootWin,         MODKEY,         Button2,        spawn,          {.v = zmenpozadi } },
  { ClkRootWin,         MODKEY,         Button3,        spawn,          {.v = startupcmd } },
  { ClkRootWin,     	0,              Button4,        viewnext,       {0} },
  { ClkRootWin, 	0,              Button5,        viewprev,       {0} },
  { ClkRootWin,     	MODKEY,         Button4,        rotatetags,     {.i = +1 } },
  { ClkRootWin,		MODKEY,         Button5,        rotatetags,     {.i = -1 } },
  { ClkRootWin, 	0,              Button6,        viewprev,       {0} },
  { ClkRootWin, 	0,              Button7,        viewprev,       {0} },
  { ClkRootWin, 	0,              Button8,        viewprev,       {0} },
  { ClkRootWin, 	0,              Button9,        viewnext,       {0} },
};
