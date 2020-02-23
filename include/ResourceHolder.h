#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED

#include <map>
#include <memory>
#include <utility>
#include <assert.h>

// Resource holder template. Works for Textures and Fonts.
// TODO: Make compatible with Shaders.

template <typename Resource, typename Identifier>
class ResourceHolder
{
    public:
        void load(Identifier id, const std::string& filename);
        Resource& get(Identifier id);
        const Resource& get(Identifier id) const;

    private:
        std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

};

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    std::unique_ptr<Resource> resource = std::make_unique<Resource>();
    if (!resource->loadFromFile(filename))
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder::get(Identifier id)
{
    auto resource = mResourceMap.find(id);
    assert(resource != mResourceMap.end());
    return *resource->second; // return a pointer to the second element in the found pair
}


#endif // RESOURCEHOLDER_H_INCLUDED
