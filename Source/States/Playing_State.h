#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include <vector>
#include <SFML/Audio.hpp>

#include "State_Base.h"

#include "../Animation.h"
#include "../Player.h"
#include "Pipe.h"
#include "Display.h"

namespace State
{
    class Playing : public State_Base
    {
        enum class Stage
        {
            Pre,
            Playing,
            Death_In_Process,
            Dead
        };

        constexpr static int NUM_PIPES = 3;

        public:
            constexpr static int PLAYER_X       = 200;
            constexpr static int DEATH_HEIGHT   = Display::HEIGHT - 100;

            Playing (Application& application);

            void input  (const sf::Event& e);
            void input  ();
            void update (float dt);
            void draw   ();

        private:
            void reset();

            Player m_player;
            sf::RectangleShape m_background;
            sf::RectangleShape m_ground;

            Toggle_Key m_spacebarToggle;

            std::vector<Pipe_Pair> m_trapPairs;

            int m_currentScore;

            sf::Text m_scoreText;
            sf::Sound m_hitSound;

            Stage m_stage;
    };
}

#endif // PLAYING_STATE_H_INCLUDED
