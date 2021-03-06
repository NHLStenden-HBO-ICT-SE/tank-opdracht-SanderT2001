#pragma once

namespace Tmpl8
{
    enum TileType
    {
        GRASS,
        FORREST,
        ROCKS,
        MOUNTAINS,
        WATER
    };

    class TerrainTile
    {
    public:
        //TerrainTile *up, *down, *left, *right;
        vector<TerrainTile*> exits;
        bool visited = false;

        size_t position_x;
        size_t position_y;

        TileType tile_type;

    private:
    };

    class Terrain
    {
    public:

        static Terrain& getInstance()
        {
            // -- "Meyers Singleton" --
            // Leunt op de werking van C++ die zegt dat het object Terrain alleen aangemaakt wordt zodra deze aangeroepen wordt.
            // Zodra deze er al is, wordt het bestaande object ge-returned.
            // Let op! Dit is alleen zo bij lokale static objecten.
            // Normaal gesproken zou je een static variabele bijhouden waarbij je checked of deze "gevuld" is.
            //   Zo ja, dan die returnen. Zo niet, dan nieuwe instantie maken, die in de variabele opslaan en dan returnen.
            static Terrain terrain;
            return terrain;
        }

        void update();
        void draw(Surface* target) const;

        //Use Breadth-first search to find shortest route to the destination
        vector<vec2> get_route(const Tank& tank, const vec2& target);

        float get_speed_modifier(const vec2& position) const;

        const vec2 getActualTerrainSize()
        {
            int width  = this->terrain_width*this->sprite_size;
            int height = this->terrain_height*this->sprite_size;

            return vec2(width, height);
        }

    private:

        Terrain();

        bool is_accessible(int y, int x);

        static constexpr int sprite_size = 16;
        static constexpr size_t terrain_width = 80;
        static constexpr size_t terrain_height = 45;

        std::unique_ptr<Surface> grass_img;
        std::unique_ptr<Surface> forest_img;
        std::unique_ptr<Surface> rocks_img;
        std::unique_ptr<Surface> mountains_img;
        std::unique_ptr<Surface> water_img;

        std::unique_ptr<Sprite> tile_grass;
        std::unique_ptr<Sprite> tile_forest;
        std::unique_ptr<Sprite> tile_rocks;
        std::unique_ptr<Sprite> tile_mountains;
        std::unique_ptr<Sprite> tile_water;

        std::array<std::array<TerrainTile, terrain_width>, terrain_height> tiles;
    };
}
