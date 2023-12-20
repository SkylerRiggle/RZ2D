# Razor2D Engine

## Compiling DLL

```command
g++ -I .\Razor2D\src\core -I .\Razor2D\src\debug -I .\Razor2D\src\ecs -c .\Razor2D\src\ecs\EntityManager.cpp .\Razor2D\src\ecs\ECSCoordinator.cpp .\Razor2D\src\ecs\ComponentManager.cpp
g++ -shared -o Razor2D.dll .\EntityManager.o .\ECSCoordinator.o .\ComponentManager.o
rm *.o
```