#include "Audio.h"
#include "iostream"

bool Audio::Initialize()
{
    return true;
}

void Audio::Shutdown()
{
}

void Audio::Update()
{
}

bool Audio::AddSound( const std::string& name)
{
    FMOD::Sound* sound = nullptr;
    m_audio->createSound(name.c_str(), FMOD_DEFAULT, 0, &sound);
    if (sound == nullptr)
    {
        return false;
        std::cerr << "Could not load sound:" << name << std::endl;
    }
    m_sounds[name] = sound;

    return true;
}

bool Audio::PlaySound(std::string& name)
{
    //check if sound exists
    if (m_sounds.find(name) == m_sounds.end())
    {
        if (!AddSound(name)) return false;
    }
    
    
    m_audio->playSound(m_sounds[name], 0, false, nullptr);
    return true;
}
