/******************************************************************************
 *
 * This file is provided under a dual license.  When you use or
 * distribute this software, you may choose to be licensed under
 * version 2 of the GNU General Public License ("GPLv2 License")
 * or BSD License.
 *
 * GPLv2 License
 *
 * Copyright(C) 2017 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 *
 * BSD LICENSE
 *
 * Copyright(C) 2017 MediaTek Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/
/*! \file   "reset.h"
*   \brief  This file contains the declairation of reset module
*/

/*******************************************************************************
*                         C O M P I L E R   F L A G S
********************************************************************************
*/
#ifndef _RESET_H
#define _RESET_H

/*******************************************************************************
*                    E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/
#include "reset_fsm_def.h"

/**********************************************************************
*                                 M A C R O S
***********************************************************************
*/
#define RESETKO_API_VERSION 1

/**********************************************************************
*                              C O N S T A N T S
***********************************************************************
*/

/**********************************************************************
*                             D A T A   T Y P E S
***********************************************************************
*/
enum ReturnStatus {
	RESET_RETURN_STATUS_SUCCESS = 0,
	RESET_RETURN_STATUS_FAIL,

	RESET_RETURN_STATUS_MAX
};

struct ModuleMsg {
	unsigned int msgId;
	void *msgData;
};

/**********************************************************************
*                  F U N C T I O N   D E C L A R A T I O N S
***********************************************************************
*/
enum ReturnStatus resetko_register_module(enum ModuleType module,
					char *name,
					enum TriggerResetApiType resetApiType,
					void *resetFunc,
					void *notifyFunc);
enum ReturnStatus resetko_unregister_module(enum ModuleType module);

enum ReturnStatus send_reset_event(enum ModuleType module,
				enum ResetFsmEvent event);

enum ReturnStatus send_msg_to_module(enum ModuleType srcModule,
				    enum ModuleType dstModule,
				    void *msg);


/**********************************************************************
*                            P U B L I C   D A T A
***********************************************************************
*/

/**********************************************************************
*                           P R I V A T E   D A T A
***********************************************************************
*/

/**********************************************************************
*                              F U N C T I O N S
**********************************************************************/

#endif /* _RESET_H */

