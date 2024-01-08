# Razor2D Engine

## About

Razor2D is a mostly experimental engine made to explore the core concepts of both C/C++ development and game engine architecture. As the title suggests, the engine is being developed with only 2D support in mind to reduce the complexity during these learning stages. Please feel free to use this project in your own codebases or as practice to learn! Also feel free to offer any feedback on how the implementation and/or architecture of the engine could be improved (_contact info. at the bottom of this README_).

## Compiling DLL

```command
g++ -I .\Razor2D\src\core -I .\Razor2D\src\debug -I .\Razor2D\src\ecs -c .\Razor2D\src\ecs\EntitySystem.cpp
g++ -shared -o Razor2D.dll .\EntitySystem.o
rm *.o
```

## Contact Info.

| Developer | Email | Discord Username |
| --------- | ----- | ---------------- |
| Skyler Riggle | Skyler.D.Riggle-1@ou.edu | skyler321 |