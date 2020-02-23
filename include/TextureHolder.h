#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <map>
#include <memory>
#include <utility>
#include <assert.h>
#include <SFML/Graphics.hpp>

// Enumerates every texture in the game.
namespace Textures
{
    enum ID {Landscape, Player};
}

// Loads textures from disk and holds them for easy access.
class TextureHolder
{
    public:
        TextureHolder();
        virtual ~TextureHolder();
        void load(Textures::ID id, const std::string& filename);
        sf::Texture& get(Textures::ID id);
        const sf::Texture& get(Textures::ID id) const;

    private:
        std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

#endif // TEXTUREHOLDER_H
