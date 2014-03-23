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
#ifndef _DESKTOPJOBAGENTMESSAGEHANDLER_H
#define _DESKTOPJOBAGENTMESSAGEHANDLER_H

class AnsoftMessage;

// Receives
class DesktopJobAgentMessageHandler
{
public:

  void AddAnsoftMessage(const AnsoftMessage& msg);

};

#endif
