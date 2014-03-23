// -----------------------------------------------------------------
// Original Author: Naresh Appannagaari
// Contents: 
//     
// Copyright 2013 ANSYS Inc, All Rights Reserved
// No part of this file may be reproduced, stored in a 
// retrieval system, or transmitted in any form or by any means -
// electronic, mechanical, photocopying, recording, or otherwise - 
// without prior written permission of ANSYS Inc.
// -----------------------------------------------------------------
#ifndef _MCADMODELCOMPONENTDEF_H
#define _MCADMODELCOMPONENTDEF_H



class ComponentDefinition;


// 
// Background:
// In a hierarchical MCAD system, there are components that are a proxy for
// various objects in the system: MCAD model in the project, Parts from library, etc.
// So some kind of component manager, per project, is needed to
// manage available components.

// Purpose: 
// - Represents ComponentDefinition corresponding to an MCAD model

class MCADModelComponentDef : public ComponentDefinition<MCADModel*>, public IComponentDefinition 
{
  

};

#endif
