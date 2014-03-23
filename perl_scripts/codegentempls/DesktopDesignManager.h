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
#ifndef _DESKTOPDESIGNMANAGER_H
#define _DESKTOPDESIGNMANAGER_H



class std::string;
class DesktopDesign;
class DesktopDesignInstance;
class ComponentInstance;


// 
// Background:
// In a hierarchical system, we need a manager at the 'project level'.
// A critical purpose of such a 'design manager' is to enable 
// hieiarchical composition of designs. In order to enable
// hieiarchy, design-manager maintains following objects on
// creation of top-level designs or sub-designs: Component, design-instance.
// For e.g. when a HFSS ECAD design is inserted into project at the
// top-level, a corresponding component and design-instance are created.
//    Note: Library components are not covered here. The concept is similar
//    that a Component is created for models coming from a library. But there
//    are differences such as: design is a 'live' component, while
//    library component is associated with some simulation helper code such as a 'netlist'
//
// Purpose: 
// - Manager of project's designs
// - Manage components, component-instances and design-instances that are
//   tied to designs
//
// Context:
// - DesktopProject creates/owns DesktopDesignManager
// 
// State (i.e. members):
// - Container of designs, components, top-level design-instances
// - 
// 
class DesktopDesignManager
{
   
  public:
  
  // Load components from libraries. 
   DesktopDesignManager(const std::string& systemLibPath, const std::string& userLibPath) ;
   ~DesktopDesignManager() ;
  
  // Invoke below method when model is inserted into project.
  // A design, corresponding-component, corresponding design-instance are created
  DesktopDesign* OnNewMCADModel() ;
  // Below method is invoked when one design-instance is placed into a parent design-instance.
  // In the implementation: 
  // - A new component-instance is created in the parent design. 
  // - One or more design-instances (of subDesign), corresponding to the newly created component-instance,
  //   are also created (see DesktopDesignInstance class for little more details)
  ComponentInstance* OnPlaceModel(DesktopDesignInstance* subDesignBeingPlaced, DesktopDesignInstance* parentDesignInstance) ;
  bool OnRemoveModel(DesktopDesign* modelOfProj) ;
  
  private:
  
  // NOTE:
  // A 'list' data-structure is likely unsuitable to manage large number of components. So
  // the usage below is not intended to reflect actual usage, but just a quick illustration
  // of hierarchy workings in Desktop
  std::list<ComponentDefinition*> m_projAndLibComponents;
  // NOTE: correspondance between design and it's component are not captured
  // in this sample code. So assume that, given a design, it's corresponding
  // component (and viceversa) is known
  std::list<DesktopDesign*> m_projModels;
  std::list<DesktopDesignInstance*> m_topLevelDesignInstances;

};

#endif
