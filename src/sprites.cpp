#include "sprites.h"

std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_walk = 
{{
    {{
        {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }}, 
    {{
        {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 7, 7, 1, 0, 1, 3, 1, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 0, 1, 0, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 0, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
    }}, 
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }},
    {{     
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 1, 3, 1, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 0, 1, 0, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }}
}};

std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_idle = 
{{
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }}, 
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }}, 
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }},
    {{     
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }}
}};

std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_attack = 
{{
    {{
        {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 1, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 1, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 1, 6, 6, 1, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 0, 9, 1, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 9, 8, 0, 9, 0, 0, 0}}
    }},
    {{
        {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 1, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 1, 7, 1, 1, 1, 1, 1, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 1, 5, 5, 5, 6, 6, 1}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 1, 1, 1, 1, 1, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 0, 9, 8, 8, 0, 9, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 9, 8, 0, 9, 8, 0, 0}}
    }},
    {{
        {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 1, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 1, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 1, 6, 6, 1, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 0, 9, 1, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 9, 8, 0, 9, 0, 0, 0}}
    }},
    {{
        {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 1, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 1, 7, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }}, 
}};

std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> tree_idle = 
{{
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0}},
        {{0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 1, 0}},
        {{0, 0, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0}},
        {{0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 1, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}},
    }},
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0}},
        {{0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 1, 0}},
        {{0, 0, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0}},
        {{0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 1, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}},
    }},
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0}},
        {{0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 1, 0}},
        {{0, 0, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0}},
        {{0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 1, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}},
    }},
    {{
        {{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0}},
        {{0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0}},
        {{0, 1, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0}},
        {{0, 1, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 1, 0}},
        {{0, 0, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0}},
        {{0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 4, 4, 1, 0, 1, 2, 1, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 4, 1, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}},
    }},
}};

AnimationSprites tree_sprites = {
    {IDLE, tree_idle}
};

AnimationSprites player_sprites = {
    {WALK, player_walk},
    {IDLE, player_idle},
    {ATTACK, player_attack},
};

std::map<int, uint16_t> player_sprites_color_map = {
    {1, TFT_BLACK},
    {2, TFT_BROWN},
    {3, 0xFDB8},
    {4, TFT_RED},
    {5, 0xAEDC},
    {6, TFT_LIGHTGREY},
    {7, TFT_DARKGREY},
    {8, TFT_WHITE},
    {9, TFT_LIGHTGREY},
};

std::map<int, uint16_t> tree_sprites_color_map = {
    {1, TFT_BLACK},
    {2, TFT_GREEN},
    {3, TFT_RED},
    {4, TFT_BROWN},
};