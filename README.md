# Razor2D Engine

## About

Razor2D is a mostly experimental engine made to explore the core concepts of both C/C++ development and game engine architecture. As the title suggests, the engine is being developed with only 2D support in mind to reduce the complexity during these learning stages. Please feel free to use this project in your own codebases or as practice to learn! Also feel free to offer any feedback on how the implementation and/or architecture of the engine could be improved (_contact info. at the bottom of this README_).

## Compiling DLL

```command
g++ -I .\Razor2D\src\core -I .\Razor2D\src\debug -I .\Razor2D\src\ecs -c .\Razor2D\src\ecs\EntityManager.cpp .\Razor2D\src\ecs\ECSCoordinator.cpp .\Razor2D\src\ecs\ComponentManager.cpp
g++ -shared -o Razor2D.dll .\EntityManager.o .\ECSCoordinator.o .\ComponentManager.o
rm *.o
```

## Tasks

- [ ] Design System Registration
- [ ] Design Archetype Enforcement
- [ ] Create Nicer Build System (Most likely Makefiles/Bash scripts)
- [ ] Design Crash Report System
    - [ ] Tie In Logging System
        - [X] Timestamps In Log Statements
        - [ ] Cross-Platform Color Support
        - [ ] Possibly Adding Multiple Outputs (Ex: "An error occurred at index: ", idx)
    - [ ] Include Recent Stack Trace On Failed Assertions
    - [ ] Defined Assertion Failure Callback (Useful for future applications to do things like sending the crash data to a server)

## Contact Info.

| Developer | Email | Discord Username |
| --------- | ----- | ---------------- |
| Skyler Riggle | Skyler.D.Riggle-1@ou.edu | skyler321 |