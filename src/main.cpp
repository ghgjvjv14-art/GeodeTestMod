#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <cstdlib>

using namespace geode::prelude;

class $modify(MyPlayerMod, PlayerObject) {
    float m_colorTimer = 0.0f;

    void update(float dt) {
        PlayerObject::update(dt);

        m_fields->m_colorTimer += dt;

        if (m_fields->m_colorTimer >= 1.0f) {
            m_fields->m_colorTimer = 0.0f;

            uint8_t r = std::rand() % 256;
            uint8_t g = std::rand() % 256;
            uint8_t b = std::rand() % 256;

            cocos2d::ccColor3B randomColor = {r, g, b};

            this->setColor(randomColor);
            this->setSecondColor(randomColor);
        }
    }
};
