
using System;
using System.Runtime.Serialization;

namespace Alphaleonis.Win32.Vss
{
   /// <summary>
   ///     Exception thrown to indicate that the writer infrastructure is not operating properly. 
   /// </summary>
   /// <remarks>
   ///     Check that the Event Service and VSS have been started, and check for errors associated with those services in the error log.
   /// </remarks>
   [Serializable]
   public sealed class VssWriterInfrastructureException : VssWriterException
   {
      /// <summary>
      ///     Initializes a new instance of the <see cref="VssWriterInfrastructureException"/> 
      ///     class with a system-supplied message describing the error.
      /// </summary>
      public VssWriterInfrastructureException()
         : base(Resources.LocalizedStrings.TheWriterInfrastructureIsNotOperatingProperly)
      {
      }

      /// <summary>
      ///     Initializes a new instance of the <see cref="VssWriterInfrastructureException"/> class with a specified error message.
      /// </summary>
      /// <param name="message">The message that describes the error</param>
      public VssWriterInfrastructureException(string message)
         : base(message)
      {
      }

      /// <summary>
      ///     Initializes a new instance of the <see cref="VssWriterInfrastructureException"/> class with 
      ///     a specified error message and a reference to the inner exception that is the cause of this exception.
      /// </summary>
      /// <param name="message">The message that describes the error</param>
      /// <param name="innerException">The exception that is the cause of the current exception.</param>
      public VssWriterInfrastructureException(string message, Exception innerException)
         : base(message, innerException)
      {
      }

      /// <summary>
      /// Initializes a new instance of the <see cref="VssWriterInfrastructureException"/> class.
      /// </summary>
      /// <param name="info">The <see cref="SerializationInfo"/> that holds the serialized object data about the exception being thrown.</param>
      /// <param name="context">The <see cref="StreamingContext"/> that contains contextual information about the source or destination.</param>
      /// <exception cref="ArgumentNullException">The <paramref name="info"/> parameter is <see langword="null"/>. </exception>
      /// <exception cref="SerializationException">The class name is <see langword="null"/> or <see cref="Exception.HResult"/> is zero (0). </exception>
      private VssWriterInfrastructureException(SerializationInfo info, StreamingContext context)
         : base(info, context)
      {
      }
   }
}
