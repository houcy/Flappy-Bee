#ifndef Pipe_H_INCLUDED
#define Pipe_H_INCLUDED

#include <Resource_Manager.h>

class Player;

class Pipe_Pair
{
    constexpr static int GAP_BETWEEN_TRAPS = 210;
    constexpr static int MOVE_SPEED        = 400;

    class Pipe
    {
        public:
            Pipe(const Resource_Holder& resources, bool rotate);

            void setY   (int y);
            void setX   (int x);

            void draw   ();

            sf::FloatRect getBounds() const;

        private:
            sf::RectangleShape m_sprite;
            bool m_isFlipped;
    };

    public:
        constexpr static int TRAP_WIDTH = 128;

        Pipe_Pair(const Resource_Holder& resources,
                      int initX);

        void update     (float dt);
        void draw       ();

        bool colliding  (Player& player) const;

    private:
        int getRandomYPos();
        void setRandomY();

        Pipe m_top;
        Pipe m_bottom;

        int m_currentXPosition;
};

#endif // Pipe_H_INCLUDED