/*!
REVISION HISTORY
$Revision: 3659 $
$Date: 2015-07-01 10:19:20 -0700 (Wed, 01 Jul 2015) $

Copyright (c) 2013, Linear Technology Corp.(LTC)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of Linear Technology Corp.

The Linear Technology Linduino is not affiliated with the official Arduino team.
However, the Linduino is only possible because of the Arduino team's commitment
to the open-source community.  Please, visit http://www.arduino.cc and
http://store.arduino.cc , and consider a purchase that will help fund their
ongoing work.
*/
/*! @file
    @ingroup LTPSM_InFlightUpdate
    Library Header File for NVM
*/


#ifndef NVM_H_
#define NVM_H_

#include <stdbool.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include "../LT_PMBUS/LT_PMBus.h"
#include "../LT_SMBUS/LT_SMBusNoPec.h"
#include "../LT_SMBUS/LT_SMBusPec.h"
#include "../LT_SMBUS/LT_I2CBus.h"
#include "main_record_processor.h"
#include "hex_file_parser.h"

// Give access to c code used by this class
extern LT_SMBusNoPec *smbusNoPec__;
extern LT_SMBusPec *smbusPec__;

class NVM
{
  private:
    uint8_t numAddrs;

  public:
    //! Constructor.
    NVM(LT_SMBusNoPec *,    //!< reference to no pec smbus object
        LT_SMBusPec *       //!< reference to pec smbus object
       );

    //! Program with hex data.
    //! @return true if data loaded.
    bool programWithData(const unsigned char * //!< array of hex data
                        );

    //! Verifies board NVM with hex data..
    //! @return true if NVM configuration matches the hex data.
    bool verifyWithData(const unsigned char *);

};

#endif /* NVM_H_ */
