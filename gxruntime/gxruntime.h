
#ifndef GXRUNTIME_H
#define GXRUNTIME_H

#include <windows.h>
#include <string>
#include <vector>

#include "gxaudio.h"
#include "gxinput.h"
#include "gxfilesystem.h"
#include "gxtimer.h"
#if BB_BLITZ3D_ENABLED
#include "gxgraphics.h"
#endif

#include "../debugger/debugger.h"

class gxRuntime{
	/***** INTERNAL INTERFACE *****/
public:

	HWND hwnd;
	HINSTANCE hinst;

	gxAudio *audio;
	gxInput *input;
	gxFileSystem *fileSystem;

	void moveMouse( int x,int y );

	LRESULT windowProc( HWND hwnd,UINT msg,WPARAM w,LPARAM l );

#if BB_BLITZ3D_ENABLED
	struct GfxMode;
	struct GfxDriver;
	gxGraphics *graphics;

	void flip( bool vwait );
#endif

private:
	gxRuntime( HINSTANCE hinst,const std::string &cmd_line,HWND hwnd );
	~gxRuntime();

	void paint();
	void suspend();
	void forceSuspend();
	void resume();
	void forceResume();

	RECT t_rect;
	int t_style;
	std::string cmd_line;
	bool pointer_visible;
	std::string app_title;
	std::string app_close;

#if BB_BLITZ3D_ENABLED
	bool enum_all;
	std::vector<GfxDriver*> drivers;
	GfxDriver *curr_driver;

	bool setDisplayMode( int w,int h,int d,bool d3d,IDirectDraw7 *dd );
	gxGraphics *openWindowedGraphics( int w,int h,int d,bool d3d );
	gxGraphics *openExclusiveGraphics( int w,int h,int d,bool d3d );
	void backupGraphics();
	void restoreGraphics();
	void backupWindowState();
	void restoreWindowState();
	void enumGfx();
	void denumGfx();
#endif

	int use_di;

	void resetInput();
	void pauseAudio();
	void resumeAudio();
	void acquireInput();
	void unacquireInput();

	/***** APP INTERFACE *****/
public:
	static gxRuntime *openRuntime( HINSTANCE hinst,const std::string &cmd_line,Debugger *debugger );
	static void closeRuntime( gxRuntime *runtime );

	void asyncStop();
	void asyncRun();
	void asyncEnd();

	/***** GX INTERFACE *****/
public:
	enum{
		GFXMODECAPS_3D=1
	};

	//return true if program should continue, or false for quit.
	bool idle();
	bool delay( int ms );

	bool execute( const std::string &cmd );
	void setTitle( const std::string &title,const std::string &close );
	int  getMilliSecs();
	void setPointerVisible( bool vis );

	std::string commandLine();

	std::string systemProperty( const std::string &t );

	void debugStop();
	void debugProfile( int per );
	void debugStmt( int pos,const char *file );
	void debugEnter( void *frame,void *env,const char *func );
	void debugLeave();
	void debugInfo( const char *t );
	void debugError( const char *t );
	void debugLog( const char *t );

	gxAudio *openAudio( int flags );
	void closeAudio( gxAudio *audio );

	gxInput *openInput( int flags );
	void closeInput( gxInput *input );

	gxFileSystem *openFileSystem( int flags );
	void closeFileSystem( gxFileSystem *filesys );

	gxTimer *createTimer( int hertz );
	void freeTimer( gxTimer *timer );

	void enableDirectInput( bool use );
	int  directInputEnabled(){ return use_di; }

	int callDll( const std::string &dll,const std::string &func,const void *in,int in_sz,void *out,int out_sz );

	OSVERSIONINFO osinfo;

#if BB_BLITZ3D_ENABLED
	gxGraphics *openGraphics( int w,int h,int d,int driver,int flags );
	void closeGraphics( gxGraphics *graphics );
	bool graphicsLost();

	int numGraphicsDrivers();
	void graphicsDriverInfo( int driver,std::string *name,int *caps );

	int numGraphicsModes( int driver );
	void graphicsModeInfo( int driver,int mode,int *w,int *h,int *d,int *caps );

	void windowedModeInfo( int *caps );
#endif
};

#endif