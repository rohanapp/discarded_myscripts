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
#ifndef _MCADMODELSMANAGER_H
#define _MCADMODELSMANAGER_H



class std::string;
class MCADModel;


// 
// Background:
// In a hierarchical MCAD system, there are components that are a proxy for
// various objects in the system: MCAD model in the project, Parts from library, etc.
// So some kind of component manager, per project, is needed to
// manage available components.

// Purpose: 
// - Manager of models and their components
// - Manager of components from libraries 
//   (Note: Usually library manager is separate from model manager)
// 
// State (i.e. members):
// - Container of components
// 
class MCADModelsManager
{
   
  public:
  
  // Load components from libraries. 
   MCADModelsManager(const std::string& systemLibPath, const std::string& userLibPath) ;
   ~MCADModelsManager() ;
  
  // Invoke below method when model is inserted into project.
  // A model and component corresponding to it are created
  MCADModel* OnNewMCADModel() ;
  bool OnRemoveMCADModel(MCADModel* modelOfProj) ;
  
  private:
  
  // 'list' used just for quick illustration
  std::list<ComponentDefinition*> m_projAndLibComponents;
  std::list<MCADModel*> m_projModels;

};

#endif
