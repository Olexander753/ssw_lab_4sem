### Build

Note: all instructions here for machine with *nix OS. For WIndows users may be need some another instructions (you can try to use *Cygwin* or just change `g++` on `mingw`)

To build by make (Makefile):

```bash
$ cd <to repo path>/lab_01
$ make
```

To build by cmake (CMakeLists.txt):

```bash
$ cd <to repo path>/lab_01
$ cmake .
$ make
```



## lab_01

Реализация таких линейных структур данных как: стек, очередь, вектор.

Данные структуры должны поддерживать следующие операции/свойства:

- push - вставка элемента в структуру;
- pop - выталкивание элемента из структуры;
- peek - возврат вершины структуры (верхнего элемента);
- count - возврат количества элементов в структуре;
- динамический размер - размер структуры должен увеличиваться при необходимости;
- не должны содержать в себе STL контейнеров (`std::stack, std::queue, std::vector`).

### Что Вы должны сделать:

Ниже представлен список **индивидуальных** заданий:

- вариант 1: реализация - 
  - обмена (*swap*) данными между структурами; 
  - смены порядка элементов в структуре на обратный (*reverse*);
- вариант 2: вычисление -
  - суммы всех элементов;
  - среднего арифметического;
- вариант 3: исключение из структуры - 
  - всех элементов с отрицательными значениями;
  - элементов подпадающих в заданный диапазон;
- вариант 4: конкатенация - 
  - данных между структурами;
  - данных внутри структуры*.

Ваши **структуры должны** поддерживать реализации индивидуальных заданий (если не было указано иное). К примеру: *стек, очередь и вектор, для варианта 1 должны поддерживать такие методы как `swap` и `reverse` предоставляя ожидаемый функционал (обмен и "переворот" данных).* 

*К примеру: структура содержит следующий перечень элементов { 1, 2, 5, 40, 3 }, соответственно их конкатенация выдаст число 125403. Все отрицательные числа берутся по модулю, не реализуется для структуры - стек.

### Сборка

Все представленные ниже инструкции используются для _*nix_ семейства ОС.  Для пользователей ОС Windows может понадобиться использование других инструкций (либо вы можете использовать *Cygwin* или *MinGW*).

Для сборки с помощью `make` (Makefile):

```bash
$ cd <to repo path>/lab_01
$ make
```

Для сборки с помощью `cmake` (CMakeLists.txt):

```bash
$ cd <to repo path>/lab_01
$ cmake .
$ make
```

### Отчёт

В отчёте должно содержаться:

- перечисление **выполненых** заданий;
- листинг (код) программы;
- тестирование программы;
- вывод скомпилированной программы;
- вывод по проделанной работе.