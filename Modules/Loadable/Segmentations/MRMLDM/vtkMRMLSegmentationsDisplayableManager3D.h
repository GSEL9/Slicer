/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

#ifndef __vtkMRMLSegmentationsDisplayableManager3D_h
#define __vtkMRMLSegmentationsDisplayableManager3D_h

// MRMLDisplayableManager includes
#include "vtkMRMLAbstractThreeDViewDisplayableManager.h"

#include "vtkSlicerSegmentationsModuleMRMLDisplayableManagerExport.h"

/// \brief Display segmentations in 3D views
///
/// Displays poly data representations of segmentations in 3D viewers
/// If master representation is a poly data then show master representation.
/// Otherwise show first poly data representation if any.
/// Otherwise try converting to closed surface representation
///
class VTK_SLICER_SEGMENTATIONS_MODULE_MRMLDISPLAYABLEMANAGER_EXPORT vtkMRMLSegmentationsDisplayableManager3D
  : public vtkMRMLAbstractThreeDViewDisplayableManager
{
public:

  static vtkMRMLSegmentationsDisplayableManager3D* New();
  vtkTypeMacro(vtkMRMLSegmentationsDisplayableManager3D,vtkMRMLAbstractThreeDViewDisplayableManager);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

protected:

  vtkMRMLSegmentationsDisplayableManager3D();
  virtual ~vtkMRMLSegmentationsDisplayableManager3D();

  virtual void UnobserveMRMLScene() VTK_OVERRIDE;
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node) VTK_OVERRIDE;
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node) VTK_OVERRIDE;
  virtual void ProcessMRMLNodesEvents(vtkObject* caller, unsigned long event, void* callData) VTK_OVERRIDE;

  /// Update actors based on segmentations in the scene
  virtual void UpdateFromMRML() VTK_OVERRIDE;

  virtual void OnMRMLSceneStartClose() VTK_OVERRIDE;
  virtual void OnMRMLSceneEndClose() VTK_OVERRIDE;

  virtual void OnMRMLSceneEndBatchProcess() VTK_OVERRIDE;

  /// Initialize the displayable manager
  virtual void Create() VTK_OVERRIDE;

  /// Find display node managed by the displayable manager at a specified world RAS position.
  /// \return Non-zero in case a node is found at the position, 0 otherwise
  virtual int Pick3D(double ras[3]) VTK_OVERRIDE;

  /// Get the MRML ID of the picked node, returns empty string if no pick
  virtual const char* GetPickedNodeID() VTK_OVERRIDE;

  /// Get the ID of the picked segment, returns empty string if no pick
  virtual const char* GetPickedSegmentID();

private:

  vtkMRMLSegmentationsDisplayableManager3D(const vtkMRMLSegmentationsDisplayableManager3D&); // Not implemented
  void operator=(const vtkMRMLSegmentationsDisplayableManager3D&);                 // Not Implemented

  class vtkInternal;
  vtkInternal* Internal;
  friend class vtkInternal;
};

#endif
