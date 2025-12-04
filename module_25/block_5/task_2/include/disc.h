#pragma once
#include "ram.h"

// Жёсткий диск (disk) — имеет в себе две функции, save и load.
// Функция save должна сохранить состояние 8 чисел из оперативной памяти на
// постоянный носитель в файл data.txt. Функция load — загрузить их с носителя в оперативную память.

void save(const Ram object);
void load(Ram &object);