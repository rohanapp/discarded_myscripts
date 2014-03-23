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
#ifndef _MCADMODEL_H
#define _MCADMODEL_H





// 
// Purpose: 
// - Represents MCADModel (parts, boundary conditions, etc.)
// - Container of 'subModels' (MCADModelComponentInstances)
// - Contained of leaf parts, boundary conditions, etc.
// 
class MCADModel
{
   
  public:
  
   MCADModel() ;
   ~MCADModel() ;
  
  // 
  
  
  private:
  
  std::list<MCADModelComponentInstance*> m_subModels;
  std::list<LeafPart*> m_leafParts;
  

};

#endif
