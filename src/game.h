#pragma once
#include <vector>
#include <list>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
typedef uint32_t uint32;
typedef unsigned char uchar;

enum SpawnSide
{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

struct Event
{
    double time;
    int enemiesToSpawn;
    SpawnSide spawnSide;
    int difficulty;
    bool happened;
};

enum EntityType
{
    ENEMY,
    PLAYER,
    PLAYER_BULLET,
    ENEMY_BULLET,
};

enum EntityState
{
    ALIVE,
    DEAD,
};

struct Entity
{
    Vector2 pos;
    Vector2 size;
    Vector2 velocity;
    Vector2 acceleration;
    EntityType type;
    EntityState state;
    float speed;
    Color color;
};

struct GameState
{
    bool initialized;
    std::vector<Event> events;
    std::list<Entity> bullets;
    std::list<Entity> enemies;
    Entity player;
    Color uicolor;
    bool uiClosed;

    double timeToWin;
    bool showFps;
    unsigned int score;
};