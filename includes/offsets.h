#pragma once

#include <cstdint>


struct XMFLOAT3 {
        float      x;
        float      y;
        float      z;
};

namespace offsets
{
    std::uintptr_t GNames = 0x5dd8b80;
    std::uintptr_t GObjects = 0x5df0470;
    std::uintptr_t GWorld = 0x5ed7ca0;
};

class RootComponent
{
public:
    char pad_0000[0x120]; //0x0000
    XMFLOAT3  Position; //0x0120
}; //Size: 0x0578

class ActorArray
{
public:
    char pad_0000[24]; //0x0000
    int32_t ObjectID; //0x0018
    int32_t UnknownShit; //0x001C
    char pad_0020[272]; //0x0020
    class RootComponent* m_pRoot; //0x0130
};

class PersistentLevel
{
public:
    char pad_0000[88]; //0x0000
    wchar_t* LevelLogo; //0x0058
    char pad_0060[56]; //0x0060
    ActorArray** m_Actor; //0x0098
    int32_t ActorCount; //0x00A0
    int32_t MaxActor; //0x00A4
    ActorArray** m_Actor2; //0x00A8
    int32_t UnknownCount; //0x00B0
    int32_t MaxUnkCount; //0x00B4
}; //Size: 0x00B8


class LocalPawn
{
public:
    char pad_0000[304]; //0x0000
    class RootComponent* m_pRoot; //0x0130
}; //Size: 0x0138

class CameraManager
{
public:
    char pad_0000[3648]; //0x0000
    XMFLOAT3 CamLocation; //0x0E40
    XMFLOAT3 CamRotation; //0x0E4C
    float FOV; //0x0E58
    float DefaultFOV; //0x0E5C
    float OrthoWidth; //0x0E60
    float OrthoNearClipPlane; //0x0E64
    float OrthoFarClipPlane; //0x0E68
    float AspectRatio; //0x0E6C
    char pad_0E70[2992]; //0x0E70
    XMFLOAT3 Location; //0x1A20
    XMFLOAT3 Rotation; //0x1A2C
    float FOV1; //0x1A38
    float DesiredFOV1; //0x1A3C
    float OrthoWidth1; //0x1A40
    float OrthoNearClipPlane1; //0x1A44
    float OrthoFarClipPlane1; //0x1A48
    float AspectRatio1; //0x1A4C

}; //Size: 0x0E60

class PlayerController
{
public:
    char pad_0000[664]; //0x0000
    class LocalPawn* pLPawn; //0x0298
    char pad_02A0[16]; //0x02A0
    class CameraManager* m_CameraMgr; //0x02B0
}; //Size: 0x02B8

class GameScreen
{
public:
    char pad_0000[8]; //0x0000
    float Width; //0x0008
    float Height; //0x000C
}; //Size: 0x0010

class ViewportClient
{
public:
    char pad_0000[200]; //0x0000
    class GameScreen* p_Scr; //0x00C8
}; //Size: 0x00D0

class LocalPlayer
{
public:
    char pad_0000[48]; //0x0000
    class PlayerController* m_pCTRL; //0x0030
    char pad_0038[56]; //0x0038
    class ViewportClient* m_pViewport; //0x0070
    char pad_0078[24]; //0x0078
    XMFLOAT3 LocalPosition; //0x0090

}; //Size: 0x009C

class ULocalPlayer
{
public:
    class LocalPlayer* p_Local; //0x0000

}; //Size: 0x0008

class GameInstance
{
public:
    char pad_0000[56]; //0x0000
    class ULocalPlayer* m_pULocal; //0x0038

}; //Size: 0x0040

class UWorld
{
public:
    char pad_0000[48]; //0x0000
    class PersistentLevel* m_Persistent; //0x0030
    char pad_0038[312]; //0x0038
    class GameInstance* m_pGInstance; //0x0170
    char pad_0178[664]; //0x0178
    wchar_t* Maps; //0x0410
    char pad_0418[24]; //0x0418
    void* NameBS; //0x0430

    static auto GetInstance() {
        return *reinterpret_cast<UWorld**>(offsets::GWorld);
    }
};