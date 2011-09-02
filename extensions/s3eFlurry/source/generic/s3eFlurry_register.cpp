/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "s3eFlurry_autodefs.h"
#include "s3eEdk.h"
#include "s3eFlurry.h"
//Declarations of Init and Term functions
extern s3eResult s3eFlurryInit();
extern void s3eFlurryTerminate();


#if defined I3D_OS_IPHONE || defined I3D_OS_OSX

static void s3eFlurryStart_wrap(const char* ID)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurryStart"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurryStart, 1, ID);
}

static void s3eFlurryLogEvent_wrap(const char* eventName, const s3eBool timed)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurryLogEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurryLogEvent, 2, eventName, timed);
}

static void s3eFlurryEndTimedEvent_wrap(const char* eventName)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurryEndTimedEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurryEndTimedEvent, 1, eventName);
}

static void s3eFlurryLogError_wrap(const char* errorName, const char* errorMessage)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurryLogError"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurryLogError, 2, errorName, errorMessage);
}

static void s3eFlurrySetUserID_wrap(const char* userID)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurrySetUserID"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurrySetUserID, 1, userID);
}

static void s3eFlurrySetUserAge_wrap(const uint8 age)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurrySetUserAge"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurrySetUserAge, 1, age);
}

static void s3eFlurrySetUserGender_wrap(const s3eFlurryUserGender gender)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurrySetUserGender"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurrySetUserGender, 1, gender);
}

static void s3eFlurrySetLocation_wrap(s3eLocation* location)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurrySetLocation"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurrySetLocation, 1, location);
}

static void s3eFlurrySetSessionReportOnClose_wrap(const s3eBool sendReportOnClose)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurrySetSessionReportOnClose"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurrySetSessionReportOnClose, 1, sendReportOnClose);
}

static void s3eFlurrySetSessionReportOnPause_wrap(const s3eBool sendReportOnPause)
{
    IwTrace(FLURRY_VERBOSE, ("calling s3eFlurry func on main thread: s3eFlurrySetSessionReportOnPause"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eFlurrySetSessionReportOnPause, 1, sendReportOnPause);
}

#define s3eFlurryStart s3eFlurryStart_wrap
#define s3eFlurryLogEvent s3eFlurryLogEvent_wrap
#define s3eFlurryEndTimedEvent s3eFlurryEndTimedEvent_wrap
#define s3eFlurryLogError s3eFlurryLogError_wrap
#define s3eFlurrySetUserID s3eFlurrySetUserID_wrap
#define s3eFlurrySetUserAge s3eFlurrySetUserAge_wrap
#define s3eFlurrySetUserGender s3eFlurrySetUserGender_wrap
#define s3eFlurrySetLocation s3eFlurrySetLocation_wrap
#define s3eFlurrySetSessionReportOnClose s3eFlurrySetSessionReportOnClose_wrap
#define s3eFlurrySetSessionReportOnPause s3eFlurrySetSessionReportOnPause_wrap

#endif /* I3D_OS_IPHONE */

void s3eFlurryRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[10];
    funcPtrs[0] = (void*)s3eFlurryStart;
    funcPtrs[1] = (void*)s3eFlurryLogEvent;
    funcPtrs[2] = (void*)s3eFlurryEndTimedEvent;
    funcPtrs[3] = (void*)s3eFlurryLogError;
    funcPtrs[4] = (void*)s3eFlurrySetUserID;
    funcPtrs[5] = (void*)s3eFlurrySetUserAge;
    funcPtrs[6] = (void*)s3eFlurrySetUserGender;
    funcPtrs[7] = (void*)s3eFlurrySetLocation;
    funcPtrs[8] = (void*)s3eFlurrySetSessionReportOnClose;
    funcPtrs[9] = (void*)s3eFlurrySetSessionReportOnPause;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[10] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("s3eFlurry", funcPtrs, sizeof(funcPtrs), flags, s3eFlurryInit, s3eFlurryTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eFlurryStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eFlurryRegisterExt;
    return 0;
}

int g_s3eFlurryVal = s3eFlurryStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eFlurryRegisterExt();
}
#endif

#endif
