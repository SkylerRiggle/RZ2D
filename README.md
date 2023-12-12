# Razor2D Engine

## Compiling DLL

```command
g++ -I .\ -I ..\debug -I ..\core -c .\EntityManager.cpp
g++ -shared -o Razor2D.dll .\EntityManager.o
```