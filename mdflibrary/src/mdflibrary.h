#pragma once

#include "MdfChannelObserver.h"
#include "MdfDataGroup.h"
#include "MdfChannelGroup.h"
#include "MdfChannel.h"

using namespace System;

namespace MdfLibrary {

public enum class MdfLogSeverity : uint8_t {
  Trace = 0,  ///< Trace or listen message
  Debug,      ///< Debug message
  Infog,      ///< Informational message
  Notice,     ///< Notice message. Notify the user.
  Warning,    ///< Warning message
  Error,      ///< Error message
  Critical,   ///< Critical message (device error)
  Alert,      ///< Alert or alarm message
  Emergency   ///< Fatal error message
};

public delegate void DoLogEvent(MdfLogSeverity severity,
                               String^ function,
                               String^ message);

public ref class MdfLibrary {
public:
  virtual ~MdfLibrary();
  static property MdfLibrary^ Instance {
    MdfLibrary^ get();
  }
  
  static bool IsMdfFile(String^ filename);
  static MdfChannelObserver^ CreateChannelObserver(
    MdfDataGroup^ data_group,
    MdfChannelGroup^ channel_group,
    MdfChannel^ channel);

  static MdfChannelObserver^ CreateChannelObserverByChannelName(
    MdfDataGroup^ data_group,
    String^ channel_name);
    
  static array<MdfChannelObserver^>^ CreateChannelObserverForChannelGroup(
    MdfDataGroup^ data_group,
    MdfChannelGroup^ channel_group);

  static String^ Utf8Conversion(const std::string& utf8_string);
  static std::string Utf8Conversion(String ^ string);

  event DoLogEvent^ LogEvent;
protected:
  MdfLibrary();

  !MdfLibrary();
private:
  static MdfLibrary^ instance_;

  MdfLibrary(const MdfLibrary^ &lib) {}
internal:
  
  void FireLogEvent(MdfLogSeverity severity,
    String^ function, String^ message);
  
};



}
