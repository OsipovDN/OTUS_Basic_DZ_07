# OTUS_Basic_DZ_07
Работа с UNIT-тестами

В данной работе выполнено основное задание и дополнительные пункты 1 и 3.

Для удобства в реализации контейнера ImplVector были дополнительно реализованы следующие методы:

ImplVector(const ImplVector <T>& obj) -конструктор копирования.
ImplVector(ImplVector <T>&& obj)  -move- конструктор (как дополнение к прошлому домашнему заданию).
ImplVector <T>& operator =(const  ImplVector <T>& obj)  -оператор копирующего присваивания.
ImplVector <T>& operator =(ImplVector <T>&& obj)  -оператор перемещения (как дополнение к прошлому домашнему заданию).
bool operator ==(const ImplVector <T>& obj) -оператор сравнения.

В контейнере ImplList были добавлены следующие методы:
bool operator ==(const ImplList& obj) -оператор сравнения.

Для двух контейнеров были реализованы следующие тесты:
  Vector:
InitializationContainer,
EraseEnd,
EraseFront,
EraseMidlle,
OperatorGetElement,
CopyVector,
MoveCopyVector.
  
 VectorFixture:
PushBack,
InsertFront,
InsertInMiddle,
GetSize.
  
 List:
InitializationContainer,
EraseEnd,
EraseFront,
EraseMidlle,
GetSize.
  
 ListFixture:
PushBack,
InsertFront,
InsertInMiddle.
  
В ходе выполнения тестов в реализации контейнера ImplList были исправленны ошибки в методах insert() и erase().
Так же была исправлена ошибка в реализации деструктора контейнера, которая при уничножении пустого объекта приводила к пробрасыванию исключения. 
