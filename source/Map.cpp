#include "Map.h"
#include "TextureManager.h"
#include "Definitions.h"

Map::Map(int arr[defaultHeightBlocks][defaultWidthBlocks])
{
    dirt = TextureManager::loadTexture("assets/sprites/Dirt_72.png");
    grass = TextureManager::loadTexture("assets/sprites/Grass_72.png");
    water = TextureManager::loadTexture("assets/sprites/Water_72.png");

    loadMap(arr);

    src.w = defaultSpriteUnit;
    src.h = defaultSpriteUnit;

    dest.w = defaultBlockSize;
    dest.h = defaultBlockSize;

    src.x = src.y = 0;
    dest.x = dest.y = 0;
}

Map::~Map() {}

void Map::loadMap(const int arr[defaultHeightBlocks][defaultWidthBlocks])
{
    for (int row = 0; row < defaultHeightBlocks; row++)
    {
        for (int column = 0; column < defaultWidthBlocks; column++)
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::gifMap()
{
    int columnFrame = int(SDL_GetTicks() / 2000) % defaultGifSteps;
    src.x = columnFrame * defaultSpriteUnit;
}

void Map::updateMap()
{
    Map::gifMap();
}

void Map::drawMap()
{
    int type = 0;
    for (int row = 0; row < defaultHeightBlocks; row++)
    {
        for (int column = 0; column < defaultWidthBlocks; column++)
        {

            dest.x = column * defaultBlockSize;
            dest.y = row * defaultBlockSize;

            type = map[row][column];
            switch (type)
            {
            case 0:
                TextureManager::draw(grass, src, dest);
                break;

            case 1:
                TextureManager::draw(dirt, src, dest);
                break;

            case 2:
                TextureManager::draw(water, src, dest);
                break;

            default:
                break;
            }
        }
    }
}

void Map::cleanMap() const
{
    SDL_DestroyTexture(dirt);
    SDL_DestroyTexture(grass);
    SDL_DestroyTexture(water);
}