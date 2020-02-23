#include "TextureHolder.h"

TextureHolder::TextureHolder()
{
    //ctor
}

TextureHolder::~TextureHolder()
{
    //dtor
}

void TextureHolder::load(Textures::ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
    if (!texture->loadFromFile(filename))
    {
        throw std::runtime_error("failed to load " + filename);
    }

    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second); // debug
}

sf::Texture& TextureHolder::get(Textures::ID id)
{
    auto texture = mTextureMap.find(id);
    assert(texture != mTextureMap.end());
    return *texture->second; // return a pointer to the second element in the found pair
}
