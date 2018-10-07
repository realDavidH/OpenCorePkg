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

#ifndef OC_GUID_TABLE_H_
#define OC_GUID_TABLE_H_

typedef struct {
  GUID  *Guid;
  CHAR8 *ShortName;
} GUID_NAME_MAP;

extern CONST GUID_NAME_MAP GuidStringMap[];

#endif // OC_GUID_TABLE_H_
