#pragma once

// Оперативная память (ram) — содержит буфер на 8 целых чисел, которые можно
// заполнить функцией write и считать функцией read.

struct Ram
{
    int data[8];
    bool dataIsInitialized = false;
};
