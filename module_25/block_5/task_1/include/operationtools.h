#pragma once

struct OperationStatus
{

    float cutPointX = 0;
    float cutPointY = 0;
    bool isCuted = false;
    bool isSutured = false;
};

// Команда scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии отсечения.
// При выполнении в консоль выводится сообщение о том, что был сделан разрез между введёнными координатами.
void scalpel(OperationStatus &newAction);

// Команда hemostat принимает на вход одну точку, в которой требуется сделать зажим, о чём также сообщает в консоль.
void hemostat(OperationStatus &newAction);

// Команда tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение об этом выводится в консоль.
void tweezers(OperationStatus &newAction);

// Команда suture — хирургическая игла, которая делает шов между двумя указанными точками.
void suture(OperationStatus &newAction);