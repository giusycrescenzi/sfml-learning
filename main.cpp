#include "src/RWindow.h"
#include "src/Window.h"
#include "src/FirstSimpleGame.h"
int main() {
    const auto *block = new BlockSurvival();
    block->run();
    return 0;
}