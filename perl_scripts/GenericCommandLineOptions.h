// -----------------------------------------------------------------
// Original Author: Naresh Appannagaari
// Contents: 
//     
// Copyright 2011 ANSYS Inc, All Rights Reserved
// No part of this file may be reproduced, stored in a 
// retrieval system, or transmitted in any form or by any means -
// electronic, mechanical, photocopying, recording, or otherwise - 
// without prior written permission of ANSYS Inc.
// -----------------------------------------------------------------
#ifndef _GENERICCOMMANDLINEOPTIONS_H
#define _GENERICCOMMANDLINEOPTIONS_H

class rtype;
class i2type;
class IMessageHandler;

//  Holds command-line options with each option represented as a named value
//  
// 
// fff
class GenericCommandLineOptions
{
public:

  rtype GetName(int i1name, i2type i2name) const;
  IMessageHandler* GetIMessageHandler() const;
  rtype GetPropertyValue(long* i1name, i2type i2name);

};

#endif
