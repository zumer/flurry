/*
 * Copyright (C) 2001-2011 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Ideaworks Labs.
 * This file consists of source code released by Ideaworks Labs under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_FLURRY_H
#define S3E_EXT_FLURRY_H

#include <s3eTypes.h>
#include "s3eLocation.h"

/**
 * @addtogroup s3egroup
 * @{
 */

/**
 * @defgroup flurryapigroup S3E FLURRY API Reference
 *
 * This allows the user to schedule and respond to local notificiation
 *
 * NOTE: THIS IS CURRENTLY A BETA MODULE
 * Interfaces are liable to change before the release version
 *
 * @supported
 * - ios: On devices running iOS 4.1 or newer
 *
 * For more information on flurry functionality provided by the S3E module,
 * see the "S3E FLURRY Overview" section of the S3E API Documentation.
 */

/**
 * @}
 * @addtogroup flurryapigroup
 * @{
 */


/**
 * Gender of user .
 *
 * @par Required Header Files
 * s3eIOSNotifications.h
 */
typedef enum s3eFlurryUserGender
{
    /** Male User */
    S3E_FLURRY_MALE  = 1,

    /** Female User */
    S3E_FLURRY_FEMALE  = 2
} s3eFlurryUserGender;
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the Flurry extension is available.
 */
s3eBool s3eFlurryAvailable();

/**
 * Start a flurry session using your flurry application ID
 *
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurryStart(const char* ID);

/**
 * Use this to count the number of times certain events happen during a session of your
 * application. For example, this can be useful for measuring how often users perform
 * various actions (maximum length 255 characters)
 * Limited to counting occurrences for 300 different event ids
 * (maximum length 255 characters).
 *
 * If s3eBool is true a timed event will be created. To end this event use
 * s3eFlurryEndTimedEvent otherwise this will be closed automatically when the app exits
 * @see s3eFlurryEndTimedEvent
 *
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurryLogEvent(const char* eventName, const s3eBool timed S3E_DEFAULT(S3E_FALSE));

/**
 * Use this to end timed event before app exits, otherwise timed events automatically
 * end when app exits. When ending the timed event, a new event parameters can be
 * passed NSDictionary object can be used to update event parameters. If you do not
 * wish to pass any new parameters please leave this field blank or pass NULL.
 *
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurryEndTimedEvent(const char* eventName);

/**
 * Use this to log exceptions and/or errors that occur in your app. Flurry will
 * report the first 10 errors that occur in each session.
 *
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurryLogError(const char* errorName, const char* errorMessage);

/**
 * Use this to log the user's ID or username after identifying this in you app.
 *
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurrySetUserID(const char* userID);

/**
 * Use this to log the user's age after identifying this in your app.
 *
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurrySetUserAge(const uint8 age);

/**
 * Use this to log the user's gender after identifying this in your app.
 *
 * @see s3eFlurryUserGender
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurrySetUserGender(const s3eFlurryUserGender gender);

/**
 * This allows you to set the current GPS location of the user. Flurry
 * will keep only the last location information.
 *
 * @platnote{ios} Method only available on iOS
 * @par Required Header Files
 * s3eFlurry.h
 * s3eLocation.h
 */
void s3eFlurrySetLocation(s3eLocation* location);

/**
 * This option is on by default. When enabled, Flurry will attempt to send
 * session data when the app is exited as well as it normally does when the
 * app is started. This will improve the speed at which your application
 * analytics are updated but can prolong the app termination process due
 * to network latency.
 * Note: In some cases, the network latency can cause the app to crash.
 *
 * @platnote{ios} Method only available on iOS
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurrySetSessionReportOnClose(const s3eBool sendReportOnClose);

/**
 * This option is on by default. When enabled, Flurry will attempt to send
 * session data when the app is paused as well as it normally does when the
 * app is started. This will improve the speed at which your application
 * analytics are updated but can prolong the app pause process due to network
 * latency.
 * Note: In some cases, the network latency can cause the app to crash.
 *
 * @platnote{ios} Method only available on iOS
 * @par Required Header Files
 * s3eFlurry.h
 */
void s3eFlurrySetSessionReportOnPause(const s3eBool sendReportOnPause);

S3E_END_C_DECL

#endif /* !S3E_EXT_FLURRY_H */
