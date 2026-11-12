#include "../declarations/gameMetadata.hpp"

GameMetadata::GameMetadata() {

    initialise();

}

/*              NEXT SHAPE

    {70, 100}    {120, 100}    {170, 100}   {220, 100}   {270, 100}
    {70, 150}    {120, 150}    {170, 150}   {220, 150}   {270, 150}
    {70, 200}    {120, 200}    {170, 200}   {220, 200}   {270, 200}
    {70, 250}    {120, 250}    {170, 250}   {220, 250}   {270, 250}
    {70, 300}    {120, 300}    {170, 300}   {220, 300}   {270, 300}


*/


/*                  HOLD

    {70, 470}    {120, 470}    {170, 470}   {220, 470}   {270, 470}
    {70, 520}    {120, 520}    {170, 520}   {220, 520}   {270, 520}
    {70, 570}    {120, 570}    {170, 570}   {220, 570}   {270, 570}
    {70, 620}    {120, 620}    {170, 620}   {220, 620}   {270, 620}
    {70, 670}    {120, 670}    {170, 670}   {220, 670}   {270, 670}


*/


void GameMetadata::initialise() {

    nextShape[0].push_back({70, 100});
    nextShape[0].push_back({120, 100});
    nextShape[0].push_back({170, 100});
    nextShape[0].push_back({220, 100});
    nextShape[0].push_back({270, 100});

    nextShape[1].push_back({70, 150});
    nextShape[1].push_back({120, 150});
    nextShape[1].push_back({170, 150});
    nextShape[1].push_back({220, 150});
    nextShape[1].push_back({270, 150});

    nextShape[2].push_back({70, 200});
    nextShape[2].push_back({120, 200});
    nextShape[2].push_back({170, 200});
    nextShape[2].push_back({220, 200});
    nextShape[2].push_back({270, 200});

    nextShape[3].push_back({70, 250});
    nextShape[3].push_back({120, 250});
    nextShape[3].push_back({170, 250});
    nextShape[3].push_back({220, 250});
    nextShape[3].push_back({270, 250});

    nextShape[4].push_back({70, 300});
    nextShape[4].push_back({120, 300});
    nextShape[4].push_back({170, 300});
    nextShape[4].push_back({220, 300});
    nextShape[4].push_back({270, 300});

    // ---------------------------------------------

    hold[0].push_back({70, 470});
    hold[0].push_back({120, 470});
    hold[0].push_back({170, 470});
    hold[0].push_back({220, 470});
    hold[0].push_back({270, 470});

    hold[1].push_back({70, 520});
    hold[1].push_back({120, 520});
    hold[1].push_back({170, 520});
    hold[1].push_back({220, 520});
    hold[1].push_back({270, 520});

    hold[2].push_back({70, 570});
    hold[2].push_back({120, 570});
    hold[2].push_back({170, 570});
    hold[2].push_back({220, 570});
    hold[2].push_back({270, 570});

    hold[3].push_back({70, 620});
    hold[3].push_back({120, 620});
    hold[3].push_back({170, 620});
    hold[3].push_back({220, 620});
    hold[3].push_back({270, 620});

    hold[4].push_back({70, 670});
    hold[4].push_back({120, 670});
    hold[4].push_back({170, 670});
    hold[4].push_back({220, 670});
    hold[4].push_back({270, 670});

}