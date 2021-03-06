
#pragma once

#include <vss.h>

#include "VssListAdapter.h"
#include "Macros.h"

using namespace System::Collections::Generic;

namespace Alphaleonis { namespace Win32 { namespace Vss
{
   private ref class VssComponent : IVssComponent, MarshalByRefObject
   {
   public:
      ~VssComponent();
      !VssComponent();

      property bool AdditionalRestores { virtual bool get(); }
      property String^ BackupOptions { virtual String^ get(); }
      property String^ BackupStamp { virtual String^ get(); }
      property bool BackupSucceeded { virtual bool get(); }
      property String^ ComponentName { virtual String^ get(); }
      property VssComponentType ComponentType { virtual VssComponentType get(); }
      property VssFileRestoreStatus FileRestoreStatus { virtual VssFileRestoreStatus get(); }
      property String^ LogicalPath { virtual String^ get(); }
      property String^ PostRestoreFailureMsg { virtual String^ get(); }
      property String^ PreRestoreFailureMsg { virtual String^ get(); }
      property String^ PreviousBackupStamp { virtual String^ get(); }
      property String^ RestoreOptions { virtual String^ get(); }
      property VssRestoreTarget RestoreTarget { virtual VssRestoreTarget get(); }
      property bool IsSelectedForRestore { virtual bool get(); }
      property IList<VssWMFileDescriptor^>^ AlternateLocationMappings { virtual IList<VssWMFileDescriptor^>^ get(); }
      property IList<VssDirectedTargetInfo^>^ DirectedTargets { virtual IList<VssDirectedTargetInfo^>^ get(); }
      property IList<VssWMFileDescriptor^>^ NewTargets { virtual IList<VssWMFileDescriptor^>^ get(); }
      property IList<VssPartialFileInfo^>^ PartialFiles { virtual IList<VssPartialFileInfo^>^ get(); }
      property IList<VssDifferencedFileInfo^>^ DifferencedFiles { virtual IList<VssDifferencedFileInfo^>^ get(); }
      property IList<VssRestoreSubcomponentInfo^>^ RestoreSubcomponents { virtual IList<VssRestoreSubcomponentInfo^>^ get(); }

      //
      // From IVssComponentEx
      //
      property bool IsAuthoritativeRestore { virtual bool get(); }
      property String^ PostSnapshotFailureMsg { virtual String^ get(); }
      property String^ PrepareForBackupFailureMsg { virtual String^ get(); }
      property String^ RestoreName { virtual String^ get(); }
      property String^ RollForwardRestorePoint { virtual String^ get(); }
      property VssRollForwardType RollForwardType { virtual VssRollForwardType get(); }

      // 
      // From IVssComponentEx2
      // 
      property VssComponentFailure^ Failure { virtual VssComponentFailure^ get(); virtual void set(VssComponentFailure^ value); }

   internal:
      static VssComponent^ Adopt(::IVssComponent *vssWriterComponents);
   private:
      VssComponent(::IVssComponent *vssWriterComponents);
      ::IVssComponent *m_vssComponent;

      DEFINE_EX_INTERFACE_ACCESSOR(IVssComponentEx, m_vssComponent)
      DEFINE_EX_INTERFACE_ACCESSOR(IVssComponentEx2, m_vssComponent)


      ref class DirectedTargetList sealed : VssListAdapter<VssDirectedTargetInfo^>
      {
      public:
         DirectedTargetList(VssComponent^ component);

         property int Count { virtual int get() override; }
         property VssDirectedTargetInfo^ default[int] { virtual VssDirectedTargetInfo^ get(int index) override; }
      private:
         VssComponent^ m_component;
      };

      ref class NewTargetList sealed : VssListAdapter<VssWMFileDescriptor^>
      {
      public:
         NewTargetList(VssComponent^ component);

         property int Count { virtual int get() override; }
         property VssWMFileDescriptor^ default[int] { virtual VssWMFileDescriptor^ get(int index) override; }
      private:
         VssComponent^ m_component;
      };

      ref class AlternateLocationMappingList sealed : VssListAdapter<VssWMFileDescriptor^>
      {
      public:
         AlternateLocationMappingList(VssComponent^ component);

         property int Count { virtual int get() override; }
         property VssWMFileDescriptor^ default[int] { virtual VssWMFileDescriptor^ get(int index) override; }
      private:
         VssComponent^ m_component;
      };

      ref class PartialFileList sealed : VssListAdapter<VssPartialFileInfo^>
      {
      public:
         PartialFileList(VssComponent^ component);

         property int Count { virtual int get() override; }
         property VssPartialFileInfo^ default[int] { virtual VssPartialFileInfo^ get(int index) override; }
      private:
         VssComponent^ m_component;
      };

      ref class DifferencedFileList sealed : VssListAdapter<VssDifferencedFileInfo^>
      {
      public:
         DifferencedFileList(VssComponent^ component);

         property int Count { virtual int get() override; }
         property VssDifferencedFileInfo^ default[int] { virtual VssDifferencedFileInfo^ get(int index) override; }
      private:
         VssComponent^ m_component;
      };

      ref class RestoreSubcomponentList sealed : VssListAdapter<VssRestoreSubcomponentInfo^>
      {
      public:
         RestoreSubcomponentList(VssComponent^ component);

         property int Count { virtual int get() override; }
         property VssRestoreSubcomponentInfo^ default[int] { virtual VssRestoreSubcomponentInfo^ get(int index) override; }
      private:
         VssComponent^ m_component;
      };

      AlternateLocationMappingList^ m_alternateLocationMappings;
      DirectedTargetList^ m_directedTargets;
      DifferencedFileList^ m_differencedFiles;
      RestoreSubcomponentList^ m_restoreSubcomponents;
      PartialFileList^ m_partialFiles;
      NewTargetList^ m_newTargets;
   };
}
} }