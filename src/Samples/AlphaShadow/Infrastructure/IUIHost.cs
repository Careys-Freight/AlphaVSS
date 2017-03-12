
using System;
using System.Diagnostics;
using System.Collections.Generic;

namespace AlphaShadow
{
   public interface IUIHost
   {
      IDisposable GetIndent();
      void ExecCommand(string execCommand, string args);
      bool VerboseOutputEnabled { get; set; }
      bool IsWordWrapEnabled { get; set; }            
      
      void WriteLine();
      void WriteTable(StringTable table, int columnSpacing = 3, bool addRowSpace = false);

      void PushIndent();
      void PopIndent();
      void WriteHeader(string message, params object[] args);
      void WriteLine(string message, params object[] args);
      void WriteWarning(string message, params object[] args);
      void WriteError(string message, params object[] args);
      void WriteVerbose(string message, params object[] args);

      bool ShouldContinue();
   }
}
