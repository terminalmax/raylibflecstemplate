#include <raylib.h>
#include <flecs.h>

int main() {

  InitWindow(400, 400, "Template");
  SetTargetFPS(60);
  
  ecs_world_t *world = ecs_init();

  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GRAY);
    EndDrawing();
  }
  
  ecs_fini(world);

  return 0;
}
