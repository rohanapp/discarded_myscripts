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
#ifndef _MCADMODELCOMPONENTINSTANCE_H
#define _MCADMODELCOMPONENTINSTANCE_H





// 
// Purpose: 
// - Represents instance of MCADModelComponentDefinition
// - Overides parameter values and also has transformation to
//   enable placement in parent model
// 
class MCADModelComponentInstance : public ComponentInstance 
{
   
  public:
  
   MCADModelComponentInstance() ;
   ~MCADModelComponentInstance() ;
  
  private:
  
  // Coordinate system in which instance is placed
  int m_parentCSID;
  // Transformation relative to parent's CS in which instance is located
  TransformMatrix3D m_transf;
  

};

#endif
