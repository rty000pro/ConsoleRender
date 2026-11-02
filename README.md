## ConsoleRender

От скуки написал простой консольный рендер который рисует по x y.

## Есть 4 типа Demo 'Временно не работает'
- # classic
  ```bash
  ./ConsoleRender 35 35 classic
<img width="602" height="474" alt="image" src="https://github.com/user-attachments/assets/131e79b1-dd4d-408e-9563-853961469544" />

- # classicColor
  ```bash
  ./ConsoleRender 35 35 classicColor
<img width="597" height="471" alt="image" src="https://github.com/user-attachments/assets/274deab2-b32c-4fd1-a613-ac97f637c75c" />


- # nocolor
  ```bash
  ./ConsoleRender 35 35 nocolor
<img width="599" height="474" alt="image" src="https://github.com/user-attachments/assets/f7c0ac5e-5fe5-4ea5-b4fd-c3045e8fcc8f" />

- # color
  ```bash
  ./ConsoleRender 35 35 color
<img width="597" height="473" alt="image" src="https://github.com/user-attachments/assets/860d09f1-f9ba-4994-b1d7-ebcbd0d396cc" />

## Сборка

```bash
  cmake -S . -B build
  cmake --build build -j
```
или можно через Visual Studio подключив туда gcc
