# QAM-AWGN-simulator
Implementation of QPSK/QAM16/QAM64 modulation and BER analysis in C++
## Описание проекта

Данный проект реализует симулятор цифровой системы связи на языке C++.

Симулятор включает:

* модуляцию/демодуляцию QPSK
* модуляцию/демодуляцию QAM16
* модуляцию/демодуляцию QAM64
* модель канала AWGN (Additive White Gaussian Noise)
* анализ BER (Bit Error Rate)
* визуализацию BER с использованием Python

## Модель системы связи

Реализованная цепочка передачи данных:

```text
Случайная битовая последовательность
            ↓
        QAM-модулятор
            ↓
         AWGN-канал
            ↓
      QAM-демодулятор
            ↓
        Расчёт BER
```

---

## Реализованные виды модуляции

| Модуляция | Количество бит на символ |
| --------- | ------------------------ |
| QPSK      | 2                        |
| QAM16     | 4                        |
| QAM64     | 6                        |

---

## Анализ BER

Симулятор вычисляет BER для различных значений дисперсии шума.

Анализируется зависимость:

BER от дисперсии шума.

Полученные результаты показывают:

* QPSK обладает наилучшей помехоустойчивостью
* QAM16 имеет больший BER по сравнению с QPSK
* QAM64 наиболее чувствителен к шуму

## Структура проекта

```text
QAM-AWGN-simulator/
│
├── include/
│   ├── qam_modulator.h
│   ├── qam_demodulator.h
│   └── awgn_channel.h
│
├── src/
│   ├── main.cpp
│   ├── qam_modulator.cpp
│   ├── qam_demodulator.cpp
│   └── awgn_channel.cpp
│
├── results/
│   ├── ber_qpsk.txt
│   ├── ber_qam16.txt
│   └── ber_qam64.txt
│
├── plot_ber.py
└── README.md
```

---

## Компиляция проекта

Компиляция выполняется командой:

```bash
g++ src/*.cpp -Iinclude -std=c++17 -o qam_sim
```

---

## Запуск симуляции

Запуск программы:

```bash
./qam_sim
```

Тип модуляции выбирается в файле:

```cpp
main.cpp
```

```cpp
std::string modulationType = "QPSK";
```

Возможные значения:

* QPSK
* QAM16
* QAM64

---

## Построение BER-графиков

Запуск Python-скрипта:

```bash
python plot_ber.py
```

Скрипт строит сравнительные BER-кривые для:

* QPSK
* QAM16
* QAM64

---

## Используемые технологии

* C++17
* Python

---
