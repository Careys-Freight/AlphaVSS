
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.EnterpriseServices;
using System;

// General Information about an assembly is controlled through the following 
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
[assembly: AssemblyTitle("AlphaShadow")]
[assembly: AssemblyDescription("AlphaVSS Volume Shadow Copy Library Sample Client")]
[assembly: AssemblyCulture("")]

// Setting ComVisible to false makes the types in this assembly not visible 
// to COM components.  If you need to access a type in this assembly from 
// COM, set the ComVisible attribute to true on that type.
[assembly: ComVisible(false)]

[assembly:CLSCompliant(false)]

// The following GUID is for the ID of the typelib if this project is exposed to COM
[assembly: Guid("7a51187d-1509-45ad-9281-ea25c979d987")]

[assembly: ApplicationAccessControl(Authentication = AuthenticationOption.Privacy,
                                    ImpersonationLevel = ImpersonationLevelOption.Identify,
                                    AccessChecksLevel = AccessChecksLevelOption.ApplicationComponent)]