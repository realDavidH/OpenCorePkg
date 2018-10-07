/** @file
  Copyright (C) 2016, The HermitCrabs Lab. All rights reserved.

  All rights reserved.

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#ifndef OC_LOG_PROTOCOL_H_
#define OC_LOG_PROTOCOL_H_

// The defines for the log flags.

#define OC_LOG_DISABLE      0
#define OC_LOG_ENABLE       BIT0
#define OC_LOG_CONSOLE      BIT1
#define OC_LOG_SERIAL       BIT2
#define OC_LOG_VARIABLE     BIT3
#define OC_LOG_FILE         BIT4
#define OC_LOG_NONVOLATILE  BIT5

typedef UINTN OC_LOG_OPTIONS;

// OC_LOG_PROTOCOL_GUID
/// The GUID of the OC_LOG_PROTOCOL.
#define OC_LOG_PROTOCOL_GUID                                                  \
  {                                                                                 \
    0xDBB6008F, 0x89E4, 0x4272, { 0x98, 0x81, 0xCE, 0x3A, 0xFD, 0x97, 0x24, 0xD0 }  \
  }

// OC_LOG_PROTOCOL
/// The forward declaration for the protocol for the OC_LOG_PROTOCOL.
typedef struct OC_LOG_PROTOCOL OC_LOG_PROTOCOL;

// OcLogAddEntry
/** Add an entry to the log buffer

  @param[in] This          This protocol.
  @param[in] ErrorLevel    Debug level.
  @param[in] FormatString  String containing the output format.
  @param[in] Marker        Address of the VA_ARGS marker.

  @retval EFI_SUCCESS  The timers were reset successfully.
**/
typedef
EFI_STATUS
(EFIAPI *OC_LOG_ADD_ENTRY) (
  IN OC_LOG_PROTOCOL  *This,
  IN UINTN                  ErrorLevel,
  IN CONST CHAR8            *FormatString,
  IN VA_LIST                Marker
  );

// OcLogResetTimers
/** Reset the internal timers

  @param[in] This  This protocol.

  @retval EFI_SUCCESS  The timers were reset successfully.
**/
typedef
EFI_STATUS
(EFIAPI *OC_LOG_RESET_TIMERS) (
  IN OC_LOG_PROTOCOL  *This
  );

// OcLogGetLog
/** Retrieve pointer to the log buffer

  @param[in] This           This protocol.
  @param[in] OcLogBuffer  Address to store the buffer pointer.

  @retval EFI_SUCCESS  The timers were reset successfully.
**/
typedef
EFI_STATUS
(EFIAPI *OC_LOG_GET_LOG) (
  IN  OC_LOG_PROTOCOL  *This,
  OUT CHAR16                 **OcLogBuffer
  );

// OcLogSaveLog
/** Save the current log

  @param[in] This         This protocol.
  @param[in] NonVolatile  Variable.
  @param[in] FilePath     Filepath to save the log. OPTIONAL

  @retval EFI_SUCCESS  The log was saved successfully.
**/
typedef
EFI_STATUS
(EFIAPI *OC_LOG_SAVE_LOG) (
  IN OC_LOG_PROTOCOL    *This,
  IN UINT32                    NonVolatile OPTIONAL,
  IN EFI_DEVICE_PATH_PROTOCOL  *FilePath OPTIONAL
  );

// _OC_LOG_PROTOCOL
/// The structure exposed by the OC_LOG_PROTOCOL.
struct OC_LOG_PROTOCOL {
  UINT32                    Revision;     ///< The revision of the installed protocol.
  OC_LOG_OPTIONS          Options;      ///< The current options of the installed protocol.
  OC_LOG_ADD_ENTRY    AddEntry;     ///< A pointer to the AddEntry function.
  OC_LOG_GET_LOG      GetLog;       ///< A pointer to the GetLog function.
  OC_LOG_SAVE_LOG     SaveLog;      ///< A pointer to the SaveLog function.
  OC_LOG_RESET_TIMERS ResetTimers;  ///< A pointer to the ResetTimers function.
};

// gOcLogProtocolGuid
/// A global variable storing the GUID of the OC_LOG_PROTOCOL.
extern EFI_GUID gOcLogProtocolGuid;

#endif // OC_LOG_PROTOCOL_H_
