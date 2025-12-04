#pragma once
#include "ram.h"

// Графическая карта (gpu) — выводит в консоль 8 чисел из оперативной памяти.

void print_data_from_ram(const Ram &object);
void print_computed_data(const int &computedData, const bool dataIsInitialized);