#include "app.h"

int main() {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    App app;

    app.Run();
    return 0;
}
