#include <iostream>
#include <string>

enum class Colors {WHITE, BLACK};
struct Brain {};

class Player
{
private:
    Colors playerColor;
public:
    Colors getColor();
    void setColor(Colors);
    virtual std::string whatAmI();
    Brain brain;

};

Colors Player::getColor()
{
    return playerColor;
}

void Player::setColor(Colors color)
{
    playerColor = color;
}

std::string Player::whatAmI()
{
    return "A base player";
}

class AutoPlayer :  public Player
{
public:
    virtual std::string whatAmI();
    Brain brain = Brain();
};

std::string AutoPlayer::whatAmI()
{
    return "A auto player";
}

class BGame
{
public:
    BGame(Player *playerWhite, Player *playerBlack);

    Player *playerWhite = 0;
    Player *playerBlack = 0;
};

BGame::BGame( Player *playerWhite,
              Player *playerBlack )
        : playerWhite(playerWhite),
          playerBlack(playerBlack)
{}

int main(void) {
    AutoPlayer playerWhite = AutoPlayer();
    AutoPlayer playerBlack = AutoPlayer();

    std::cout << playerWhite.whatAmI() << std::endl;
    std::cout << playerBlack.whatAmI() << std::endl;

    BGame bgame = BGame(&playerWhite, &playerBlack);

    std::cout << "Black" << std::endl;
    std::cout << bgame.playerBlack->whatAmI() << std::endl;
    std::cout << "White" << std::endl;
    std::cout << bgame.playerWhite->whatAmI() << std::endl;

    return 0;
}