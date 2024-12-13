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
    MdfReader Reader("example.mf4");
    Reader.ReadEverythingButData();    
    auto Header = Reader.GetHeader();
    
    for (const auto& DataGroup : Header.GetDataGroups()) {
      for (const auto& ChannelGroup : DataGroup.GetChannelGroups()) {
        std::vector<MdfLibrary::MdfChannelObserver> Observers;
        for (const auto& Channel : ChannelGroup.GetChannels()) {
          Observers.push_back(
              MdfChannelObserver(DataGroup, ChannelGroup, Channel));
        }

        Reader.ReadData(DataGroup);

        for (size_t i = 0; i < ChannelGroup.GetNofSamples(); i++) {
          for (const auto& Observer : Observers) {
            switch (Observer.GetChannel().GetDataType()) {
              case ChannelDataType::CanOpenDate:
              case ChannelDataType::CanOpenTime: {
                uint64_t channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Name: " << Observer.GetName();
                std::cout << ", Unit: " << Observer.GetUnit();
                std::cout << ", Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::UnsignedIntegerLe:
              case ChannelDataType::UnsignedIntegerBe: {
                uint64_t channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Name: " << Observer.GetName();
                std::cout << ", Unit: " << Observer.GetUnit();
                std::cout << ", Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::SignedIntegerLe:
              case ChannelDataType::SignedIntegerBe: {
                int64_t channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Name: " << Observer.GetName();
                std::cout << ", Unit: " << Observer.GetUnit();
                std::cout << ", Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::FloatLe:
              case ChannelDataType::FloatBe: {
                double channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Name: " << Observer.GetName();
                std::cout << ", Unit: " << Observer.GetUnit();
                std::cout << ", Channel: " << channel_value
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
                std::cout << "Name: " << Observer.GetName();
                std::cout << ", Unit: " << Observer.GetUnit();
                std::cout << ", Channel: " << channel_value
                          << ", Eng: " << eng_value << std::endl;
                break;
              }
              case ChannelDataType::MimeStream:
              case ChannelDataType::MimeSample:
              case ChannelDataType::ByteArray: {
                std::vector<uint8_t> channel_value, eng_value;
                Observer.GetChannelValue(i, channel_value);
                Observer.GetEngValue(i, eng_value);
                std::cout << "Name: " << Observer.GetName();
                std::cout << ", Unit: " << Observer.GetUnit();
                std::cout << ", Channel: " << channel_value.size()
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
