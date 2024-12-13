#include <iostream>
#include <sstream>

#include <mdflibrary/MdfExport.h>
#include <mdflibrary/MdfChannelObserver.h>
#include <mdflibrary/MdfReader.h>
#include <mdflibrary/MdfWriter.h>

using namespace MdfLibrary;
using namespace MdfLibrary::ExportFunctions;

void cpp_example() {
  {
    std::cout << "Read" << std::endl;
    MdfReader Reader("example.mf4");
    Reader.ReadEverythingButData();
    auto Header = Reader.GetHeader();
    std::cout << "Author: " << Header.GetAuthor().c_str() << std::endl;
    std::cout << "Department: " << Header.GetDepartment() << std::endl;
    std::cout << "Description: " << Header.GetDescription() << std::endl;
    std::cout << "Project: " << Header.GetProject() << std::endl;
    std::cout << "StartTime: " << Header.GetStartTime() << std::endl;
    std::cout << "Subject: " << Header.GetSubject() << std::endl;

    auto Historys = Header.GetFileHistorys();
    std::cout << "History: " << Historys.size() << std::endl;
    for (const auto& Histroy : Historys) {
      std::cout << "Time: " << Histroy.GetTime() << std::endl;
      std::cout << "Description: " << Histroy.GetDescription() << std::endl;
      std::cout << "ToolName: " << Histroy.GetToolName() << std::endl;
      std::cout << "ToolVendor: " << Histroy.GetToolVendor() << std::endl;
      std::cout << "ToolVersion: " << Histroy.GetToolVersion() << std::endl;
      std::cout << "UserName: " << Histroy.GetUserName() << std::endl;
      std::cout << std::endl;
    }

    auto DataGroups = Header.GetDataGroups();
    std::cout << "DataGroups: " << DataGroups.size() << std::endl;
    for (const auto& DataGroup : DataGroups) {
      auto ChannelGroups = DataGroup.GetChannelGroups();
      std::cout << "ChannelGroups: " << ChannelGroups.size() << std::endl;
      for (const auto& ChannelGroup : ChannelGroups) {
        std::cout << "Name: " << ChannelGroup.GetName() << std::endl;
        std::cout << "Description: " << ChannelGroup.GetDescription()
                  << std::endl;

        std::cout << "Nof Samples: " << ChannelGroup.GetNofSamples()
                  << std::endl;

        auto Channels = ChannelGroup.GetChannels();
        std::cout << "Channels: " << Channels.size() << std::endl;
        std::vector<MdfLibrary::MdfChannelObserver> Observers;
        for (const auto& Channel : Channels) {
          std::cout << "Name: " << Channel.GetName() << std::endl;
          std::cout << "Description: " << Channel.GetDescription() << std::endl;
          std::cout << "Type: " << static_cast<int>(Channel.GetType())
                    << std::endl;
          std::cout << "Sync: " << static_cast<int>(Channel.GetSync())
                    << std::endl;
          std::cout << "DataType: " << static_cast<int>(Channel.GetDataType())
                    << std::endl;
          std::cout << "DataBytes: " << Channel.GetDataBytes() << std::endl;
          std::cout << "Unit: " << Channel.GetUnit() << std::endl;
          std::cout << std::endl;

          Observers.push_back(
              MdfChannelObserver(DataGroup, ChannelGroup, Channel));
        }

        Reader.ReadData(DataGroup);

        for (size_t i = 0; i < ChannelGroup.GetNofSamples(); i++) {
          std::cout << "Sample: " << i << std::endl;
          for (const auto& Observer : Observers) {
            switch (Observer.GetChannel().GetDataType()) {
              case ChannelDataType::CanOpenDate:
              case ChannelDataType::CanOpenTime: {
                uint64_t channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::UnsignedIntegerLe:
              case ChannelDataType::UnsignedIntegerBe: {
                uint64_t channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::SignedIntegerLe:
              case ChannelDataType::SignedIntegerBe: {
                int64_t channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::FloatLe:
              case ChannelDataType::FloatBe: {
                double channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::StringAscii:
              case ChannelDataType::StringUTF8:
              case ChannelDataType::StringUTF16Le:
              case ChannelDataType::StringUTF16Be: {
                std::string channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::MimeStream:
              case ChannelDataType::MimeSample:
              case ChannelDataType::ByteArray: {
                std::vector<uint8_t> channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Channel: " << channel_value.size()
                          << ", Eng: " << eng_value.size() << std::endl;
                break;
              }
              default:
                break;
            }
          }
          std::cout << std::endl;
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
  }
}

int main() {
  cpp_example();
  return 0;
}