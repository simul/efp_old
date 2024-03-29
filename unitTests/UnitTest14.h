//
// Created by Anders Cedronius on 2019-12-05.
//

#ifndef EFP_UNITTEST14_H
#define EFP_UNITTEST14_H

#include "../ElasticFrameProtocol.h"

#define MTU 1456 //SRT-max

class UnitTest14 {
public:
    bool startUnitTest();
private:
    void sendData(const std::vector<uint8_t> &subPacket);
    void gotData(ElasticFrameProtocol::pFramePtr &packet);
    bool waitForCompletion();
    ElasticFrameProtocol *myEFPReciever = nullptr;
    ElasticFrameProtocol *myEFPPacker = nullptr;
    std::atomic_bool unitTestActive;
    std::atomic_bool unitTestFailed;
    int activeUnitTest = 14;
    std::atomic_int unitTestPacketNumberSender;
    std::atomic_int unitTestPacketNumberReciever;
    std::vector<uint8_t> unitTestsSavedData;
    std::vector<std::vector<uint8_t>> unitTestsSavedData2D;
    std::vector<std::vector<std::vector<uint8_t>>> unitTestsSavedData3D;
    uint64_t expectedPTS;
    struct PrivateData {
        int myPrivateInteger = 10;
        uint8_t myPrivateUint8_t = 44;
        size_t sizeOfData = 0;
    };
};

#endif //EFP_UNITTEST14_H
